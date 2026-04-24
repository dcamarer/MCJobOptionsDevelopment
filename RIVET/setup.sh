echo ""
date
echo ""

setupATLAS
lsetup asetup

### Same-sign WW polarisation studies
asetup AthGeneration,23.6.28,here
### Sherpa 2.2.16
#asetup AthGeneration,23.6.49,here
### Sherpa 3.0.3
#asetup AthGeneration,23.6.49,here
### Latest
#asetup main,latest,AthGeneration

### Setup Rivet
# Rivet 4 is not backwards compatible with Rivet 3 and crucially the DressedLeptons projection was removed https://gitlab.com/hepcedar/rivet/-/blob/release-4-1-x/doc/tutorials/mig3to4.md
source setupRivet
rivet --version

echo ""
date
echo ""
echo "C'est fini!"
echo ""
