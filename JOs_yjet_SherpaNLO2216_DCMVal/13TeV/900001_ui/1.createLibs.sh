#!/bin/sh -

# Default configuration
BASE_DIR="/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_ui"
BASE_DIR_ext="${BASE_DIR}/ecm13TeV"
DEFAULT_NCORES=48
DEFAULT_ENERGY_BEAM=6500.0
DEFAULT_ENERGY_CM=13000.0

# Optional overrides from command line
NCORES="${1:-$DEFAULT_NCORES}"
ENERGY_BEAM="${2:-$DEFAULT_ENERGY_BEAM}"
ENERGY_CM="${3:-$DEFAULT_ENERGY_CM}"

if [ "$1" != "--really" ]; then 
  exec singularity exec -e --no-home -B /cvmfs -B /var -B ${BASE_DIR} -B $(pwd | cut -d '/' -f 1-2) /cvmfs/atlas.cern.ch/repo/containers/fs/singularity/x86_64-almalinux9 /bin/bash -- "$0" --really "$@";
fi
shift;

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
ulimit -f 1000000;
cd ${BASE_DIR}

echo "ncores=1 nhours=48 ${BASE_DIR}/1.createLibs.sh";
source $AtlasSetup/scripts/asetup.sh 23.6.49,AthGeneration
set -e
rm -rf Process/Amegic.db Process/Comix.db Process/Sherpa.db Process/Amegic
echo 'genSeq.Sherpa_i.Parameters += [ "INIT_ONLY=1", "EVENTS=0", "FRAGMENTATION=Off", "MI_HANDLER=None", "LOG_FILE="]
' > events.py
outputEVNTFile=$(mktemp -u /tmp/XXXXXXXX.pool.root)
returncode=0
Gen_tf.py --ecmEnergy=${ENERGY_CM} --maxEvents=1 --firstEvent=1 --randomSeed=10 --jobConfig=${BASE_DIR} --postInclude=events.py --outputEVNTFile=${outputEVNTFile} || returncode=$?
echo Pasting log.generate ===============
cat log.generate
echo Gen_tf exited with return code $returncode
if [ $returncode -eq 251 ]; then
  echo 'ERROR: OpenLoops-libary is missing: add missing OpenLoops-libary (see http://openloops.hepforge.org/process_library.php) to variable genSeq.Sherpa_i.OpenLoopsLibs in the jobOption-file, remove Process directory and start again'
  exit 1
fi
if [ $returncode -eq 65 ]; then
  if grep -q 'Sherpa: Sherpa::InitializeTheRun throws normal exit' log.generate || grep -q 'ERROR Have to compile Amegic libraries' log.generate; then
    echo 'Libraries successfully written out. (Ignore errors above.)'
  elif grep -q 'INFO Have to compile Amegic libraries' log.generate; then
    echo 'Libraries successfully written out with <=2.2.1. (Ignore errors above.)'
  else
    echo 'ERROR: Gen_tf.py has failed in an unexpected way. This likely means your job options are incorrect. This log file will have more details.'
    exit 1
  fi
fi
if [ $returncode -ne 0 -a $returncode -ne 251 -a $returncode -ne 65 ]; then
  echo 'ERROR: unexpexted error from Gen_tf'
  exit 1
fi
rm -rf ${outputEVNTFile} _joproxy* AtRndmGenSvc.out AthenaSummary_Generate.txt Generate_messageSvc_jobOptions.py Generate_runathena PoolFileCatalog.xml PoolFileCatalog.xml.BAK TransformTimer_Generate.pickle config.pickle dmesg_trf.txt hostnamelookup.tmp inputDictionary.pickle jobInfo.xml jobInfo_Generate.xml jobReport* last.Generate last.runargs.gpickle runargs.Generate.gpickle runargs.Generate.py metadata_Generate.xml metadata.xml Sherpa_References.tex ntuple.pmon.stream setupevprod.sh share ntuple.pmon.gz testHepMC.root events.py Bdecays0.dat Bs2Jpsiphi.DEC DECAY.DEC G4particle_acceptlist.txt PDGTABLE.MeV pdt.table runargs.generate.py runwrapper.generate.sh eventLoopHeartBeat.txt susyParticlePdgid.txt TestHepMC.root log.generate mem.full.generate mem.summary.generate.json env.txt Run.dat Sherpa.yaml
exit 0
