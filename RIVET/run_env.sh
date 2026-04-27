#!/bin/bash

MODE="${1:-EL9}"

echo ""
date
echo ""

case "$MODE" in
  C7)
    echo "Starting CentOS7 container..."
    setupATLAS -c centos7
    ;;
  EL9)
    setupATLAS
    lsetup asetup
    source ./inside_el9.sh
    ;;
  *)
    echo "ERROR: unknown mode '$MODE'"
    echo "Usage: $0 [C7|EL9]"
    exit 1
    ;;
esac
