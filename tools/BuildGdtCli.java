import ghidra.GhidraApplicationLayout;
import ghidra.framework.Application;
import ghidra.framework.ApplicationConfiguration;
import ghidra.framework.HeadlessGhidraApplicationConfiguration;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.data.FileDataTypeManager;
import ghidra.program.model.data.DataTypeManager;
import ghidra.util.task.TaskMonitor;
import java.io.File;

/**
 * Standalone CLI utility to parse C header files into a Ghidra Data Type Archive (.gdt).
 * Does not require a running Ghidra project, GUI, or ELF file import.
 */
public class BuildGdtCli {

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.err.println("Usage: java BuildGdtCli <header.h> <output.gdt>");
            System.exit(1);
        }

        File headerFile = new File(args[0]).getAbsoluteFile();
        File gdtFile = new File(args[1]).getAbsoluteFile();

        if (!headerFile.exists()) {
            System.err.println("Error: Header file not found: " + headerFile);
            System.exit(1);
        }

        if (!Application.isInitialized()) {
            ApplicationConfiguration config = new HeadlessGhidraApplicationConfiguration();
            Application.initializeApplication(new GhidraApplicationLayout(), config);
        }

        if (gdtFile.exists()) {
            gdtFile.delete();
        }
        gdtFile.getParentFile().mkdirs();

        String[] fileNames = new String[] { headerFile.getAbsolutePath() };
        DataTypeManager[] openDTMs = new DataTypeManager[0];
        String[] cargs = new String[] { "-D_GHIDRA_" };

        FileDataTypeManager archiveDTM = CParserUtils.parseHeaderFiles(
            openDTMs, fileNames, cargs, gdtFile.getAbsolutePath(), TaskMonitor.DUMMY
        );

        if (archiveDTM != null) {
            try {
                archiveDTM.save();
                System.out.println("✓ Successfully built " + gdtFile.getName() + " (" + archiveDTM.getDataTypeCount(true) + " data types)");
            } finally {
                archiveDTM.close();
            }
        } else {
            System.err.println("✗ Failed to compile GDT archive.");
            System.exit(1);
        }
    }
}
