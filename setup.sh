echo ""
date
echo ""

setupATLAS -c
asetup AthGeneration,23.6.50,here
lsetup rucio
lsetup "rucio -w"

# Grid jobs
voms-proxy-init -voms atlas:/atlas
lsetup panda

echo ""
date
echo ""
echo "C'est fini!"
echo ""