#!/bin/sh -
if [ "$1" != "--really" ]; then 
  exec singularity exec -e --no-home -B /cvmfs -B /var -B /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006 -B $(pwd | cut -d '/' -f 1-2) /cvmfs/atlas.cern.ch/repo/containers/fs/singularity/x86_64-almalinux9 /bin/bash -- "$0" --really "$@";
fi
shift;

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
ulimit -f 1000000;
cd /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006

echo 'ncores=4 nhours=48 /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006/2.makelibs.sh';
if ! test -f makelibs; then echo INFO: No makelibs file found; exit 0; fi
source $AtlasSetup/scripts/asetup.sh 23.6.49,AthGeneration
wget http://prdownloads.sourceforge.net/scons/scons-local-3.1.2.tar.gz
tar xzf scons-local-*.tar.gz
ln -s scons.py scons
export PATH=$PATH:$PWD
set -e
./makelibs -j4
rm -rf Process/Amegic/P2_*
rm -rf scons*
exit 0
