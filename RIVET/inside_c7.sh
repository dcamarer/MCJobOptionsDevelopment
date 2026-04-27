#!/bin/bash

lsetup asetup

### Same-sign WW polarisation studies
asetup AthGeneration,23.6.28,here

### Setup Rivet
source setupRivet
rivet --version

echo ""
date
echo ""
echo "C'est fini!"
echo ""