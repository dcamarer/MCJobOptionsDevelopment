#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
asetup AthGeneration,23.6.49,here

#WORKDIR="/afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_gen_part5"
WORKDIR="/usatlas/u/dcamarero/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_gen_part5"

# Check if workdir exists, abort if not
if [ ! -d "$WORKDIR" ]; then
    echo "ERROR: Workdir does not exist: $WORKDIR" >&2
    echo "Aborting execution." >&2
    exit 1
fi

cd "$WORKDIR" || exit 1

Gen_tf.py --ecmEnergy=13000.0 \
          --randomSeed=3141 \
          --jobConfig=../900001 \
          --outputEVNTFile=run2_900001_part5.EVNT.root \
          --maxEvents=10000
