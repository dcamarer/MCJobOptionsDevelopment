#!/bin/bash

MODE="${1:-el9}"

echo ""
date
echo ""

case "$MODE" in
  c7)
    echo "Starting CentOS7 container..."
    setupATLAS -c centos7
    ;;
  el9)
    setupATLAS
    lsetup asetup
    source ./inside_el9.sh
    ;;
  *)
    echo "ERROR: unknown mode '$MODE'"
    echo "Usage: $0 [c7|el9]"
    ;;
esac
