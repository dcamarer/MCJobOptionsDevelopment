#!/bin/sh -

# Default configuration
BASE_DIR="/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900003_ui"
BASE_DIR_ext="${BASE_DIR}/ecm13TeV"
DEFAULT_NCORES=4
DEFAULT_ENERGY_BEAM=6500.0

if [ "$1" != "--really" ]; then 
  exec singularity exec -e --no-home -B /cvmfs -B /var -B ${BASE_DIR} -B $(pwd | cut -d '/' -f 1-2) /cvmfs/atlas.cern.ch/repo/containers/fs/singularity/x86_64-almalinux9 /bin/bash -- "$0" --really "$@";
fi
shift;

# Optional overrides from command line
NCORES="${1:-$DEFAULT_NCORES}"
ENERGY_BEAM="${2:-$DEFAULT_ENERGY_BEAM}"
ENERGY_CM="$(awk -v ebeam="$ENERGY_BEAM" 'BEGIN {print 2*ebeam}')"

echo "$NCORES"
echo "$ENERGY_BEAM"
echo "$ENERGY_CM"
echo "$BASE_DIR"
echo "$BASE_DIR_ext"

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
ulimit -f 1000000;
cd ${BASE_DIR}

echo "ncores=${NCORES} nhours=48 ${BASE_DIR}/2.makelibs.sh";
if ! test -f makelibs; then echo INFO: No makelibs file found; exit 0; fi
source $AtlasSetup/scripts/asetup.sh 23.6.49,AthGeneration
wget http://prdownloads.sourceforge.net/scons/scons-local-3.1.2.tar.gz
tar xzf scons-local-*.tar.gz
ln -s scons.py scons
export PATH=$PATH:$PWD
set -e
./makelibs -j${NCORES}
rm -rf Process/Amegic/P2_*
rm -rf scons*
exit 0
