// Post-import setup script for JieLi PI32V2 programs:
// 1. Patches .text / code memory blocks to executable (fixing missing SHF_EXECINSTR in JieLi ELFs)
// 2. Disassembles program entry points (dynamically discovered from program metadata)
// 3. Analyzes and labels hardware interrupt vector table slots (dynamically read from active .pspec)
// 4. Applies variant peripheral hardware structures if available for the active processor variant
//@category JieLi
//@keybinding
//@menupath Tools.JieLi.Setup JieLi PI32V2 Program
//@toolbar

import ghidra.app.plugin.processors.generic.MemoryBlockDefinition;
import ghidra.app.script.GhidraScript;
import ghidra.program.database.ProgramDB;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.lang.AddressLabelInfo;
import ghidra.program.model.lang.Language;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.io.File;
import java.util.List;

public class SetupJieLiProgram extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("=== Starting JieLi PI32V2 Post-Import Setup ===");
        Memory mem = currentProgram.getMemory();
        Language lang = currentProgram.getLanguage();
        String variant = lang.getLanguageDescription().getVariant();
        println("Detected processor variant: " + variant);

        // 1. Fix section execution permissions dynamically
        int tx = currentProgram.startTransaction("Patch Section Permissions");
        int patchedBlocks = 0;
        try {
            // Apply memory block definitions from pspec if applicable
            MemoryBlockDefinition[] defaultBlocks = lang.getDefaultMemoryBlocks();
            if (defaultBlocks != null && currentProgram instanceof ProgramDB) {
                for (MemoryBlockDefinition def : defaultBlocks) {
                    try {
                        def.fixupBlock((ProgramDB) currentProgram);
                    } catch (Exception e) {
                        // Ignore conflicts with existing blocks from ELF loader
                    }
                }
            }

            // Patch any unexecutable ELF blocks named code/text/boot/init
            for (MemoryBlock block : mem.getBlocks()) {
                String name = block.getName().toLowerCase();
                if (!block.isExecute() && (name.contains("text") || name.contains("boot") || 
                    name.contains("code") || name.contains("init"))) {
                    block.setExecute(true);
                    patchedBlocks++;
                    println("Enabled EXECUTE permission on block: " + block.getName() + " (" + block.getStart() + " - " + block.getEnd() + ")");
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("Patched " + patchedBlocks + " memory blocks.");

        // 2. Disassemble program entry points dynamically (excluding vector table slots)
        List<AddressLabelInfo> defaultSymbols = lang.getDefaultSymbols();
        java.util.Set<Address> vectorSlots = new java.util.HashSet<>();
        for (AddressLabelInfo info : defaultSymbols) {
            if (info.getLabel().startsWith("vector_")) {
                vectorSlots.add(info.getAddress());
            }
        }

        int entryCount = 0;
        AddressIterator entryIter = currentProgram.getSymbolTable().getExternalEntryPointIterator();
        while (entryIter.hasNext()) {
            Address entry = entryIter.next();
            if (!vectorSlots.contains(entry) && mem.contains(entry) && !lang.isVolatile(entry)) {
                println("Disassembling entry point at " + entry + "...");
                disassemble(entry);
                entryCount++;
            }
        }
        if (entryCount == 0 && mem.contains(currentProgram.getImageBase())) {
            Address base = currentProgram.getImageBase();
            println("No external entry point found; disassembling image base at " + base + "...");
            disassemble(base);
        }

        // 3. Process Interrupt Vector Table dynamically from .pspec default symbols
        tx = currentProgram.startTransaction("Process Interrupt Vector Table");
        int isrCount = 0;
        try {
            for (AddressLabelInfo info : defaultSymbols) {
                String label = info.getLabel();
                if (!label.startsWith("vector_")) {
                    continue;
                }

                Address vecAddr = info.getAddress();
                if (!mem.contains(vecAddr)) {
                    continue;
                }

                try {
                    int rawVal = mem.getInt(vecAddr);
                    long targetOffset = rawVal & 0xffffffffL;
                    Address targetAddr = toAddr(targetOffset);
                    MemoryBlock targetBlock = mem.getBlock(targetAddr);

                    // Validate target: exists, in RAM/Flash (non-volatile), and readable/executable
                    if (targetBlock != null && !lang.isVolatile(targetAddr) && (targetBlock.isExecute() || targetBlock.isRead())) {
                        String vecName = label.substring("vector_".length());

                        currentProgram.getListing().clearCodeUnits(vecAddr, vecAddr.add(3), false);
                        currentProgram.getListing().createData(vecAddr, PointerDataType.dataType);
                        createLabel(vecAddr, "vec_" + vecName, true);

                        disassemble(targetAddr);
                        Function isrFunc = getFunctionAt(targetAddr);
                        if (isrFunc == null) {
                            createFunction(targetAddr, "ISR_" + vecName);
                        } else if (isrFunc.getName().startsWith("FUN_")) {
                            isrFunc.setName("ISR_" + vecName, SourceType.USER_DEFINED);
                        }
                        isrCount++;
                    }
                } catch (Exception e) {
                    // Ignored: uninitialized or unmapped slot
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("Processed vector table (" + isrCount + " active ISR targets labeled from " + defaultSymbols.size() + " pspec symbols).");

        // 4. Apply variant peripheral structures dynamically if GDT archive exists
        if (variant != null && !variant.isEmpty() && !variant.equalsIgnoreCase("default")) {
            File scriptFile = getSourceFile() != null ? getSourceFile().getFile(false) : null;
            File gdtFile = null;
            if (scriptFile != null) {
                File moduleDir = scriptFile.getParentFile().getParentFile();
                gdtFile = new File(moduleDir, "data/typeinfo/" + variant + "_peripherals.gdt");
            }
            if (gdtFile == null || !gdtFile.exists()) {
                gdtFile = new File("ghidra-jieli/data/typeinfo/" + variant + "_peripherals.gdt");
            }
            if (!gdtFile.exists()) {
                gdtFile = new File("data/typeinfo/" + variant + "_peripherals.gdt");
            }

            String scriptName = "Apply" + variant.toUpperCase() + "Peripherals.java";
            if (gdtFile.exists()) {
                println("Found peripheral GDT archive for " + variant + ", running " + scriptName + "...");
                runScript(scriptName);
            } else {
                println("No peripheral archive found for variant: " + variant);
            }
        }

        println("=== Setup Complete! Memory permissions, entry points, ISR vectors, and peripheral structures are configured. ===");
        println("=== You can now run Auto Analysis (press 'A' in Ghidra GUI or run analysis). ===");
    }
}
