#!/usr/bin/env bash
#
# build_gdt.sh - Compile C peripheral headers into Ghidra Data Type Archives (.gdt)
#                without launching the Ghidra GUI or analyzeHeadless.
#
# Usage (run from inside the ghidra-jieli directory):
#   export GHIDRA_HOME=/path/to/ghidra
#   ./tools/build_gdt.sh [header_file [output_gdt]]
#   ./tools/build_gdt.sh [variant_name]
#   ./tools/build_gdt.sh (builds all headers found in data/headers/*.h)
#

set -e

if [[ -z "${GHIDRA_HOME}" || ! -d "${GHIDRA_HOME}" ]]; then
    echo "Error: GHIDRA_HOME environment variable is not set or directory does not exist."
    echo "Please set GHIDRA_HOME to your Ghidra installation directory (e.g. export GHIDRA_HOME=/opt/ghidra)."
    exit 1
fi

JAVA_SRC="tools/BuildGdtCli.java"
if [[ ! -f "${JAVA_SRC}" ]]; then
    echo "Error: Cannot find ${JAVA_SRC}."
    echo "Please run this script from inside the ghidra-jieli root directory: ./tools/build_gdt.sh"
    exit 1
fi

# Resolve header and gdt target pairs: "header:gdt"
PAIRS=()

if [[ $# -eq 0 ]]; then
    # Auto-discover all headers in data/headers/*.h
    shopt -s nullglob
    headers=(data/headers/*.h)
    shopt -u nullglob
    if [[ ${#headers[@]} -eq 0 ]]; then
        echo "Error: No header files found in data/headers/."
        exit 1
    fi
    for h in "${headers[@]}"; do
        base=$(basename "${h}" .h)
        PAIRS+=("${h}:data/typeinfo/${base}.gdt")
    done
elif [[ $# -eq 1 ]]; then
    arg="$1"
    if [[ "${arg}" == *.h && -f "${arg}" ]]; then
        base=$(basename "${arg}" .h)
        PAIRS+=("${arg}:data/typeinfo/${base}.gdt")
    elif [[ -f "data/headers/${arg}_peripherals.h" ]]; then
        PAIRS+=("data/headers/${arg}_peripherals.h:data/typeinfo/${arg}_peripherals.gdt")
    elif [[ -f "data/headers/${arg}.h" ]]; then
        PAIRS+=("data/headers/${arg}.h:data/typeinfo/${arg}.gdt")
    elif [[ -f "${arg}" ]]; then
        base=$(basename "${arg}")
        PAIRS+=("${arg}:data/typeinfo/${base}.gdt")
    else
        echo "Error: Cannot resolve header for argument '${arg}'."
        echo "Looked for '${arg}', 'data/headers/${arg}_peripherals.h', and 'data/headers/${arg}.h'."
        exit 1
    fi
elif [[ $# -eq 2 ]]; then
    PAIRS+=("$1:$2")
else
    echo "Usage: $0 [header_file [output_gdt]]"
    echo "       $0 [variant_name]"
    exit 1
fi

echo "[1/2] Building Ghidra classpath..."
CLASSPATH=$(find "${GHIDRA_HOME}/Ghidra/Framework" "${GHIDRA_HOME}/Ghidra/Features" -name "*.jar" 2>/dev/null | tr '\n' ':')

BUILD_DIR="build/gdt_build"
mkdir -p "${BUILD_DIR}"
javac -cp "${CLASSPATH}" -d "${BUILD_DIR}" "${JAVA_SRC}"

echo "[2/2] Compiling GDT archive(s)..."
for pair in "${PAIRS[@]}"; do
    header="${pair%%:*}"
    gdt="${pair##*:}"
    echo "==> Compiling ${header} -> ${gdt}"
    java -cp "${BUILD_DIR}:${CLASSPATH}" BuildGdtCli "${header}" "${gdt}"
done

rm -rf "${BUILD_DIR}"
