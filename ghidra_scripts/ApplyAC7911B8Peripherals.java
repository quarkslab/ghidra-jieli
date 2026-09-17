// Applies AC7911B8 / WL82 Peripheral Structures from ac7911b8_peripherals.gdt
//@category JieLi
//@keybinding
//@menupath Tools.JieLi.Apply AC7911B8 Peripheral Structs
//@toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.FileDataTypeManager;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.SourceType;
import java.io.File;

public class ApplyAC7911B8Peripherals extends GhidraScript {

    private static class PeriphDef {
        String name;
        String typeName;
        long address;

        PeriphDef(String name, String typeName, long address) {
            this.name = name;
            this.typeName = typeName;
            this.address = address;
        }
    }

    private static final PeriphDef[] PERIPHERALS = new PeriphDef[] {
        new PeriphDef("JL_SFC", "JL_SFC_TypeDef", 0x00040200L),
        new PeriphDef("JL_SFCENC", "JL_SFCENC_TypeDef", 0x00040300L),
        new PeriphDef("JL_SDR", "JL_SDR_TypeDef", 0x00040400L),
        new PeriphDef("JL_PSRAM", "JL_PSRAM_TypeDef", 0x00040500L),
        new PeriphDef("JL_MBISTH", "JL_MBISTH_TypeDef", 0x00041100L),
        new PeriphDef("JL_AES", "JL_AES_TypeDef", 0x00041200L),
        new PeriphDef("JL_DCP", "JL_DCP_TypeDef", 0x00041300L),
        new PeriphDef("JL_EMI", "JL_EMI_TypeDef", 0x00041400L),
        new PeriphDef("JL_JPG", "JL_JPG_TypeDef", 0x00041900L),
        new PeriphDef("JL_ISC0", "JL_ISC_TypeDef", 0x00041a00L),
        new PeriphDef("JL_ISC1", "JL_ISC_TypeDef", 0x00041b00L),
        new PeriphDef("JL_DBG", "JL_DBG_TypeDef", 0x00041c00L),
        new PeriphDef("JL_IMD", "JL_IMD_TypeDef", 0x00041d00L),
        new PeriphDef("JL_PORTA", "JL_PORT_FLASH_TypeDef", 0x00050000L),
        new PeriphDef("JL_PORTB", "JL_PORT_FLASH_TypeDef", 0x00050040L),
        new PeriphDef("JL_PORTC", "JL_PORT_FLASH_TypeDef", 0x00050080L),
        new PeriphDef("JL_PORTD", "JL_PORT_FLASH_TypeDef", 0x000500c0L),
        new PeriphDef("JL_PORTE", "JL_PORT_FLASH_TypeDef", 0x00050100L),
        new PeriphDef("JL_PORTF", "JL_PORT_FLASH_TypeDef", 0x00050140L),
        new PeriphDef("JL_PORTG", "JL_PORT_FLASH_TypeDef", 0x00050180L),
        new PeriphDef("JL_PORTH", "JL_PORT_FLASH_TypeDef", 0x000501c0L),
        new PeriphDef("JL_USB_IO", "JL_USB_IO_TypeDef", 0x00051000L),
        new PeriphDef("JL_WAKEUP", "JL_WAKEUP_TypeDef", 0x0005100cL),
        new PeriphDef("JL_IOMAP", "JL_IOMAP_TypeDef", 0x0005101cL),
        new PeriphDef("JL_LCDC", "JL_LCDC_TypeDef", 0x00051100L),
        new PeriphDef("JL_POWER", "JL_POWER_TypeDef", 0x00010000L),
        new PeriphDef("JL_CLOCK", "JL_CLOCK_TypeDef", 0x00010000L),
        new PeriphDef("JL_SYSTEM", "JL_SYSTEM_TypeDef", 0x000100c0L),
        new PeriphDef("JL_MODE", "JL_MODE_TypeDef", 0x00010100L),
        new PeriphDef("JL_INTEST", "JL_INTEST_TypeDef", 0x00010200L),
        new PeriphDef("JL_TIMER0", "JL_TIMER_TypeDef", 0x00010400L),
        new PeriphDef("JL_TIMER1", "JL_TIMER_TypeDef", 0x00010500L),
        new PeriphDef("JL_TIMER2", "JL_TIMER_TypeDef", 0x00010600L),
        new PeriphDef("JL_TIMER3", "JL_TIMER_TypeDef", 0x00010700L),
        new PeriphDef("JL_TIMER4", "JL_TIMER_TypeDef", 0x00010800L),
        new PeriphDef("JL_TIMER5", "JL_TIMER_TypeDef", 0x00010900L),
        new PeriphDef("JL_PCNT", "JL_PCNT_TypeDef", 0x00011000L),
        new PeriphDef("JL_GPCNT", "JL_GPCNT_TypeDef", 0x00011100L),
        new PeriphDef("JL_SD0", "JL_SD_TypeDef", 0x00011400L),
        new PeriphDef("JL_SD1", "JL_SD_TypeDef", 0x00011500L),
        new PeriphDef("JL_SHA", "JL_SHA_TypeDef", 0x00011700L),
        new PeriphDef("JL_USB", "JL_USB_TypeDef", 0x00011800L),
        new PeriphDef("JL_ANA", "JL_ANA_TypeDef", 0x00011900L),
        new PeriphDef("JL_SPI0", "JL_SPI_TypeDef", 0x00011c00L),
        new PeriphDef("JL_SPI1", "JL_SPI_TypeDef", 0x00011d00L),
        new PeriphDef("JL_SPI2", "JL_SPI_TypeDef", 0x00011e00L),
        new PeriphDef("JL_SPI3", "JL_SPI_TypeDef", 0x00011f00L),
        new PeriphDef("JL_UART0", "JL_UART_TypeDef", 0x00012000L),
        new PeriphDef("JL_UART1", "JL_UART_TypeDef", 0x00012100L),
        new PeriphDef("JL_UART2", "JL_UART_TypeDef", 0x00012200L),
        new PeriphDef("JL_IIC", "JL_IIC_TypeDef", 0x00012400L),
        new PeriphDef("JL_USB1", "JL_USB_TypeDef", 0x00012700L),
        new PeriphDef("JL_PAP", "JL_PAP_TypeDef", 0x00012800L),
        new PeriphDef("JL_SS", "JL_SS_TypeDef", 0x00012b00L),
        new PeriphDef("JL_RDEC", "JL_RDEC_TypeDef", 0x00012c00L),
        new PeriphDef("JL_PLNK0", "JL_PLNK_TypeDef", 0x00012d00L),
        new PeriphDef("JL_PLNK1", "JL_PLNK_TypeDef", 0x00015200L),
        new PeriphDef("JL_ALNK0", "JL_ALNK_TypeDef", 0x00012e00L),
        new PeriphDef("JL_ALNK1", "JL_ALNK_TypeDef", 0x00015100L),
        new PeriphDef("JL_AUDIO", "JL_AUDIO_TypeDef", 0x00012f00L),
        new PeriphDef("JL_ENC", "JL_ENC_TypeDef", 0x00013000L),
        new PeriphDef("JL_ADC", "JL_ADC_TypeDef", 0x00013100L),
        new PeriphDef("JL_IR", "JL_IR_TypeDef", 0x00013200L),
        new PeriphDef("JL_OSA", "JL_OSA_TypeDef", 0x00013400L),
        new PeriphDef("JL_CRC", "JL_CRC_TypeDef", 0x00013500L),
        new PeriphDef("JL_LRCT", "JL_LRCT_TypeDef", 0x00013600L),
        new PeriphDef("JL_EFUSE", "JL_EFUSE_TypeDef", 0x00013700L),
        new PeriphDef("JL_RAND", "JL_RAND_TypeDef", 0x00013b00L),
        new PeriphDef("JL_CTM", "JL_CTM_TypeDef", 0x00013c00L),
        new PeriphDef("JL_SBC", "JL_SBC_TypeDef", 0x00013d00L),
        new PeriphDef("JL_P33", "JL_P33_TypeDef", 0x00013e00L),
        new PeriphDef("JL_DMA", "JL_DMA_TypeDef", 0x00013f00L),
        new PeriphDef("JL_WL", "JL_WL_TypeDef", 0x00014000L),
        new PeriphDef("JL_SRC", "JL_SRC_TypeDef", 0x00014300L),
        new PeriphDef("JL_PWM", "JL_MCPWM_TypeDef", 0x00015000L),
        new PeriphDef("JL_MBIST", "JL_MBIST_TypeDef", 0x00015300L),
        new PeriphDef("JL_MBISTW", "JL_MBISTW_TypeDef", 0x00015400L),
        new PeriphDef("JL_EQ", "JL_EQ_TypeDef", 0x0001e000L),
        new PeriphDef("JL_EQ_RAM", "JL_EQ_RAM_TypeDef", 0x0001e800L),
        new PeriphDef("JL_ANC", "JL_ANC_TypeDef", 0x0001f000L),
        new PeriphDef("JL_ANC_RAM", "JL_ANC_RAM_TypeDef", 0x0001f800L),

        // Core Special Function Registers (CSFR: 0x01ee0000)
        new PeriphDef("JL_CMNG", "JL_CMNG_TypeDef", 0x01ee0000L),
        new PeriphDef("JL_SDTAP", "JL_SDTAP_TypeDef", 0x01ee0100L),
        new PeriphDef("JL_MBIS", "JL_MBIS_TypeDef", 0x01ee0200L),
        new PeriphDef("JL_HMEM", "JL_HMEM_TypeDef", 0x01ee0300L),
        new PeriphDef("JL_FFT", "JL_FFT_TypeDef", 0x01ee0400L),
        new PeriphDef("JL_COREX2", "JL_TypeDef_corex2", 0x01eee000L),
        new PeriphDef("JL_Q32DSP0", "JL_TypeDef_q32DSP", 0x01eef000L),
        new PeriphDef("JL_Q32DSP1", "JL_TypeDef_q32DSP", 0x01eef200L),
    };

    @Override
    public void run() throws Exception {
        File scriptFile = getSourceFile() != null ? getSourceFile().getFile(false) : null;
        File gdtFile = null;
        if (scriptFile != null) {
            File moduleDir = scriptFile.getParentFile().getParentFile();
            gdtFile = new File(moduleDir, "data/typeinfo/ac7911b8_peripherals.gdt");
        }
        if (gdtFile == null || !gdtFile.exists()) {
            gdtFile = new File("ghidra-jieli/data/typeinfo/ac7911b8_peripherals.gdt");
        }
        if (!gdtFile.exists()) {
            gdtFile = new File("data/typeinfo/ac7911b8_peripherals.gdt");
        }
        if (!gdtFile.exists()) {
            printerr("GDT file not found: " + gdtFile.getAbsolutePath());
            return;
        }

        FileDataTypeManager archive = FileDataTypeManager.openFileArchive(gdtFile, false);
        AddressSpace ram = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int applied = 0;

        int tx = currentProgram.startTransaction("Apply AC7911B8 Peripheral Structures");
        try {
            for (PeriphDef p : PERIPHERALS) {
                DataType dt = archive.getDataType("/ac7911b8_peripherals.h/" + p.typeName);
                if (dt == null) {
                    println("Warning: Data type not found: " + p.typeName);
                    continue;
                }

                Address addr = ram.getAddress(p.address);
                try {
                    currentProgram.getListing().clearCodeUnits(addr, addr.add(dt.getLength() - 1), false);
                    Data d = currentProgram.getListing().createData(addr, dt);
                    currentProgram.getSymbolTable().createLabel(addr, p.name, SourceType.USER_DEFINED);
                    applied++;
                } catch (Exception e) {
                    println("Notice: Could not map " + p.name + " at " + addr + ": " + e.getMessage());
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
            archive.close();
        }

        println("Successfully applied " + applied + "/" + PERIPHERALS.length + " peripheral structures!");
    }
}
