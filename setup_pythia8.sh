echo ""
date
echo ""

# When running on the UIs
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'
export RUCIO_ACCOUNT=dcamarer

setupATLAS
asetup AthGeneration,23.6.3,here # version 8.308
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