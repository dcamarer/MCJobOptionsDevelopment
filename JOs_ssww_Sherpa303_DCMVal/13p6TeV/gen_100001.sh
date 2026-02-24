#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
asetup AthGeneration,23.6.60,here

WORKDIR="/afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_ssww_Sherpa303_DCMVal/13TeV/100001_gen" # Ensure working dir

# Check if workdir exists, abort if not
if [ ! -d "$WORKDIR" ]; then
    echo "ERROR: Workdir does not exist: $WORKDIR" >&2
    echo "Aborting execution." >&2
    exit 1
fi

cd "$WORKDIR" || exit 1

Gen_tf.py --ecmEnergy=13600.0 \
          --randomSeed=1234 \
          --jobConfig=../100001 \
          --outputEVNTFile=run3_100001.EVNT.root \
          --maxEvents=30000
