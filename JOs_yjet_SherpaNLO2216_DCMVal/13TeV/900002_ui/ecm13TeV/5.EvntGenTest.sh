#!/bin/sh -

# Default configuration
BASE_DIR="/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900002_ui"
BASE_DIR_ext="${BASE_DIR}/ecm13TeV"
DEFAULT_NCORES=1
DEFAULT_ENERGY_BEAM=6500.0

if [ "$1" != "--really" ]; then 
  exec singularity exec -e --no-home -B /cvmfs -B /var -B ${BASE_DIR_ext} -B $(pwd | cut -d '/' -f 1-2) -B ${BASE_DIR} /cvmfs/atlas.cern.ch/repo/containers/fs/singularity/x86_64-almalinux9 /bin/bash -- "$0" --really "$@";
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
cd ${BASE_DIR_ext}

echo "ncores=${NCORES} nhours=24 ${BASE_DIR_ext}/5.EvntGenTest.sh"
source $AtlasSetup/scripts/asetup.sh 23.6.49,AthGeneration
set -e
rm -rf 5.EvntGenTest
mkdir 5.EvntGenTest
cd 5.EvntGenTest
echo 'genSeq.Sherpa_i.Parameters += [ "LOG_FILE=" ]' > events.py
outputEVNTFile=$(mktemp -u /tmp/XXXXXXXX.pool.root)
Gen_tf.py --ecmEnergy=${ENERGY_CM} --maxEvents=1 --firstEvent=1 --randomSeed=10 --jobConfig=${BASE_DIR} --postInclude=events.py --outputEVNTFile=${outputEVNTFile}
cat log.generate
post_ini_time=$(grep snapshot_post_ini log.generate | awk '{ print $5}')
post_lastevt_time=$(grep snapshot_post_lastevt log.generate | awk '{ print $5}')
nPer12h=$(awk -v a="$post_lastevt_time" -v b="$post_ini_time" 'BEGIN { printf "%.0f", 100*12*60*60*1000/(a-b) }' </dev/null)
finalEventsPerJob=0
for i in 1 2 5 10 20 50 100 200 500 1000 2000 5000 10000; do if test $nPer12h -gt $i; then finalEventsPerJob=$i; fi; done
echo "Possible number of events per 12h: ${nPer12h} -> ${finalEventsPerJob} "
if grep -q evgenConfig.nEventsPerJob ${BASE_DIR}/mc.*.py; then
  sed -e "s/evgenConfig.nEventsPerJob.*=.*\([0-9]*\)/evgenConfig.nEventsPerJob = ${finalEventsPerJob}/g" -i ${BASE_DIR}/mc.*.py
else
  echo "evgenConfig.nEventsPerJob = ${finalEventsPerJob}" >> ${BASE_DIR}/mc.*.py
fi
cp log.generate ../../
cd ..
rm -rf 5.EvntGenTest
exit 0
