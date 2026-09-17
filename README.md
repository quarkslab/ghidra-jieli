# ghidra-jieli

A comprehensive Ghidra processor module for JieLi CPU architectures (**PI32**, **PI32V2**, and **Q32S**), derived from [Kagaimiq](https://github.com/kagaimiq)'s [original implementation](https://github.com/kagaimiq/jielie/).

## Architecture Support

| Architecture | Status | Instruction Coverage | Notes |
| :--- | :--- | :--- | :--- |
| **PI32V2** | Mature | Extensive | Comprehensive SLEIGH specification covering all 10 instruction categories, delay slots, loops, SIMD, MAC, Cordic, and floating-point. |
| **PI32** | Functional | Partial | Legacy 32-bit core used on older JieLi SoCs (AC690x, etc.). |
| **Q32S** | Functional | Partial | Compact 32-bit core used on low-power chips (BD19, BD29 / AC632N, AC630N). |

---

## PI32V2 Features

### Broad Instruction Coverage & Decompiler Semantics
- **Extensive Instruction Set Support**: Implements the vendor LLVM decoding paths and known assembly forms across all 10 instruction categories (arithmetic, logic, shifts/rotates, bitops, moves/immediates, load/store, control flow, SIMD, MAC/DSP, and floating-point).
- **Control Flow**: Accurate handling of delayed jumps (`j.f`, `call.f`, `ret.f`, `reti.f`), conditional branches (`if (cond) goto`), hardware loops (`repeat`, `loop`), and pipeline controls (`flushinv`, `idle`, `halt`).
- **SIMD & DSP**: Vector pack/unpack, vector arithmetic, dot products, and multi-precision multiply-accumulate operations with saturation.
- **Decompiler Cleanliness**: Configured `<volatile>` memory ranges for peripheral registers and `<inferptrbounds>` pointer inference ranges so hardware polling loops and memory accesses decompile cleanly without dead-code elimination.
- **ELF Detection**: Integrated `JieLi.opinion` automatically binds ELF machine ID `241` (`0xf1`) to `JieLi pi32v2`.


### Supported SoC Variants
- **`default`**: Generic, memory-agnostic PI32V2 core definition suitable for any JieLi PI32V2 target.
- **`ac7911b8`**: Dedicated SoC support for JieLi **AC7911B8 / WL82** dual-core Wi-Fi/BT processors:
  - Complete memory map: SPI Flash (8MB), System SRAM (512KB), SDRAM (2MB), Cache RAM, CSFR, LSFR, BSFR, HSFR, and PSFR.
  - 73 hardware interrupt vector slots mapped and labeled at `0x01c7fe00`.
  - 627 memory-mapped peripheral register symbols.

### Peripheral Data Type Archive
- **[ac7911b8_peripherals.gdt](file:///data/typeinfo/ac7911b8_peripherals.gdt)**: Ghidra Data Type Archive containing 66 composite C structures with named bitfields and register offsets derived from official SDK headers.
- **`ApplyAC7911B8Peripherals.java`**: Script to overlay all 81 peripheral hardware instances to their memory-mapped SFR base addresses.

### Automated Post-Import Script
- **`SetupJieLiProgram.java`**: One-click setup script accessible under `Tools -> JieLi -> Setup JieLi PI32V2 Program`:
  1. Fixes `.text` and code block execution permissions (overcoming missing `SHF_EXECINSTR` flags in vendor ELFs).
  2. Dynamically discovers and disassembles program entry points.
  3. Scans and labels active hardware ISR vector table handlers from `.pspec`.
  4. Dynamically detects the processor variant and applies peripheral structures.

---

## Installation

### Method 1: Directory Installation (Recommended for Development)
Link or copy `ghidra-jieli` into your Ghidra installation's processor directory:
```bash
ln -s /path/to/ghidra-jieli <GHIDRA_INSTALL_DIR>/Ghidra/Processors/ghidra-jieli
```

### Method 2: Extension Archive
Zip the repository and install via Ghidra GUI:
1. `zip -r ghidra-jieli.zip ghidra-jieli -x "*.git*"`
2. In Ghidra: **File -> Install Extensions... -> Add Extension (+) -> Select `ghidra-jieli.zip`**.
3. Restart Ghidra.

---

## Usage Workflow

1. **Import Binary**:
   - Open your JieLi ELF or raw binary in Ghidra.
   - For ELF files, Ghidra will automatically identify the architecture as **JieLi pi32v2**.
   - Under **Variant**, select `ac7911b8` (for AC7911 / WL82) or `default` (generic).
2. **Run Post-Import Setup**:
   - Open the binary in the CodeBrowser.
   - When prompted to run Auto-Analysis, click **No** (or cancel).
   - Go to **Tools -> JieLi -> Setup JieLi PI32V2 Program** (or run `SetupJieLiProgram.java` from the Script Manager).
3. **Analyze**:
   - Press **`A`** (or **Analysis -> Auto Analyze**) to start Ghidra's standard code analysis with full memory permissions, vectors, and structures pre-configured.

---

## Compiling SLEIGH Changes

To recompile the SLEIGH specification binary (`pi32v2.sla`):
```bash
<GHIDRA_INSTALL_DIR>/support/sleigh data/languages/pi32v2.slaspec data/languages/pi32v2.sla
```

## Rebuilding Peripheral Data Type Archive (.gdt)

Because `.gdt` is Ghidra's serialized data type database format, Ghidra's C parser library is used to generate it from the C header.

To rebuild `data/typeinfo/ac7911b8_peripherals.gdt`:
```bash
./tools/build_gdt.sh
```
*(Alternatively, in the Ghidra GUI: open **File -> Parse C Source...**, add `ac7911b8_peripherals.h`, and parse into an archive).*

## License
Apache License 2.0. See [LICENSE](LICENSE) for details.

