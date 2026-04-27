#!/bin/bash

### Sherpa 2.2.16
#asetup AthGeneration,23.6.49,here
### Sherpa 3.0.3
#asetup AthGeneration,23.6.49,here
### Latest
asetup main,latest,AthGeneration

### Setup Rivet
source setupRivet
rivet --version

echo ""
date
echo ""
echo "C'est fini!"
echo ""
