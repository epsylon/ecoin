#!/bin/bash
set -euo pipefail

SRC="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/bootstrap.dat"
DATADIR="${1:-$HOME/.ecoin}"

if [ ! -f "$SRC" ]; then
    echo "[!] bootstrap.dat not found next to this script: $SRC"
    exit 1
fi

mkdir -p "$DATADIR"

if [ -f "$DATADIR/bootstrap.dat" ]; then
    echo "[!] $DATADIR/bootstrap.dat already exists and has not been imported yet."
    echo "    Start ecoind or ecoin-qt to import it, or remove it to load this one."
    exit 1
fi

if [ -f "$DATADIR/bootstrap.dat.old" ]; then
    echo "[*] A bootstrap file was already imported into $DATADIR before."
fi

cp "$SRC" "$DATADIR/bootstrap.dat"

echo "[✓] Copied $(du -h "$SRC" | cut -f1) to $DATADIR/bootstrap.dat"
echo "[*] It will be imported on the next start and renamed to bootstrap.dat.old"
echo "[*] Usage: $(basename "${BASH_SOURCE[0]}") [data directory]   (default: $HOME/.ecoin)"
