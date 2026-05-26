#!/bin/sh -

# Default configuration
BASE_DIR="/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900007_ui"
BASE_DIR_ext="${BASE_DIR}/ecm13TeV"
DEFAULT_NCORES=48
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

echo "ncores=${NCORES} nhours=336 ${BASE_DIR_ext}/3.integrate.sh"
source $AtlasSetup/scripts/asetup.sh 23.6.49,AthGeneration
set -e
cat > Run.dat <<EOL

(run){
  # Perturbative scales
  FSF:=1.; RSF:=1.; QSF:=1.;
  SCALES STRICT_METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};
  CORE_SCALE VAR{PPerp2(p[2])};
  ALPHAQED_DEFAULT_SCALE=0.0;
  
  # ME generator settings
  ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;
  LOOPGEN:=OpenLoops;

  # Tags for process setup
  NJET:=3; LJET:=2,3; QCUT:=20.;

  # EW corrections setup
  ASSOCIATED_CONTRIBUTIONS_VARIATIONS=EW EW|LO1 EW|LO1|LO2 EW|LO1|LO2|LO3;
  METS_BBAR_MODE=5;
  EW_SCHEME=3;
  GF=1.166397e-5;
  KFACTOR VAR{128.802/137.03599976};

  # Speed and neg weight fraction improvements
  PP_RS_SCALE VAR{H_T2/4};
  NLO_CSS_PSMODE=1
}(run)

(processes){
  Process 93 93 -> 22 93 93{NJET};
  Order (*,1);
  CKKW sqr(QCUT/E_CMS)/(1.0+sqr(QCUT/0.6)/PPerp2(p[2]));
  Associated_Contributions EW|LO1|LO2|LO3 {LJET};
  NLO_QCD_Mode MC@NLO {LJET};
  ME_Generator Amegic {LJET};
  RS_ME_Generator Comix {LJET};
  Loop_Generator LOOPGEN {LJET};
  Integration_Error 0.20 {2,3};  # 20% for 2-jet NLO (was 0.99 in old)
  Integration_Error 0.10 {4,5,6,7,8};  # Keep 10% for higher jets
  PSI_ItMin 30000 {2,3};
  PSI_ItMin 50000 {4,5};
  End process;
}(processes)

(selector){
  IsolationCut  22  0.1  2  0.10
  PTNLO 22  1000  E_CMS
  RapidityNLO  22  -2.7  2.7
}(selector)

EOL
sed '/.*\}(run).*/i\ \ BEAM_1=2212' -i Run.dat
sed '/.*\}(run).*/i\ \ BEAM_2=2212' -i Run.dat
sed '/.*\}(run).*/i\ \ MAX_PROPER_LIFETIME=10.0' -i Run.dat
sed '/.*\}(run).*/i\ \ HEPMC_TREE_LIKE=1' -i Run.dat
sed '/.*\}(run).*/i\ \ PRETTY_PRINT=Off' -i Run.dat
sed '/.*\}(run).*/i\ \ OVERWEIGHT_THRESHOLD=10' -i Run.dat
sed '/.*\}(run).*/i\ \ PP_HPSMODE=0' -i Run.dat
sed '/.*\}(run).*/i\ \ HEPMC_USE_NAMED_WEIGHTS=1' -i Run.dat
sed '/.*\}(run).*/i\ \ CSS_REWEIGHT=1' -i Run.dat
sed '/.*\}(run).*/i\ \ REWEIGHT_SPLITTING_PDF_SCALES=1' -i Run.dat
sed '/.*\}(run).*/i\ \ REWEIGHT_SPLITTING_ALPHAS_SCALES=1' -i Run.dat
sed '/.*\}(run).*/i\ \ CSS_REWEIGHT_SCALE_CUTOFF=5.0' -i Run.dat
sed '/.*\}(run).*/i\ \ HEPMC_INCLUDE_ME_ONLY_VARIATIONS=1' -i Run.dat
sed '/.*\}(run).*/i\ \ SCALE_VARIATIONS=0.25,0.25 0.25,1. 1.,0.25 1.,1. 1.,4. 4.,1. 4.,4.' -i Run.dat
sed '/.*\}(run).*/i\ \ EW_SCHEME=0' -i Run.dat
sed '/.*\}(run).*/i\ \ MASS[6]=172.5' -i Run.dat
sed '/.*\}(run).*/i\ \ WIDTH[6]=1.32' -i Run.dat
sed '/.*\}(run).*/i\ \ MASS[15]=1.777' -i Run.dat
sed '/.*\}(run).*/i\ \ WIDTH[15]=2.26735e-12' -i Run.dat
sed '/.*\}(run).*/i\ \ MASS[23]=91.1876' -i Run.dat
sed '/.*\}(run).*/i\ \ WIDTH[23]=2.4952' -i Run.dat
sed '/.*\}(run).*/i\ \ MASS[24]=80.399' -i Run.dat
sed '/.*\}(run).*/i\ \ WIDTH[24]=2.085' -i Run.dat
sed '/.*\}(run).*/i\ \ SIN2THETAW=0.23113' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[6,24,5]=1.32' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-6,-24,-5]=1.32' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,5,-5]=2.35e-3' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,15,-15]=2.57e-4' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,13,-13]=8.91e-7' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,4,-4]=1.18e-4' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,3,-3]=1.00e-6' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,21,21]=3.49e-4' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[25,22,22]=9.28e-6' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[24,2,-1]=0.7041' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[24,4,-3]=0.7041' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[24,12,-11]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[24,14,-13]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[24,16,-15]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-24,-2,1]=0.7041' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-24,-4,3]=0.7041' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-24,-12,11]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-24,-14,13]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[-24,-16,15]=0.2256' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,1,-1]=0.3828' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,2,-2]=0.2980' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,3,-3]=0.3828' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,4,-4]=0.2980' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,5,-5]=0.3828' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,11,-11]=0.0840' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,12,-12]=0.1663' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,13,-13]=0.0840' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,14,-14]=0.1663' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,15,-15]=0.0840' -i Run.dat
sed '/.*\}(run).*/i\ \ HDH_WIDTH[23,16,-16]=0.1663' -i Run.dat
sed '/.*\}(run).*/i\ \ OL_PARAMETERS=preset=2 write_parameters=1' -i Run.dat
sed '/.*\}(run).*/i\ \ OL_PREFIX=/cvmfs/atlas.cern.ch/repo/sw/software/23.6/sw/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/openloops/2.1.4/x86_64-el9-gcc13-opt' -i Run.dat
sed '/.*\}(run).*/i\ \ PDF_LIBRARY=LHAPDFSherpa' -i Run.dat
sed '/.*\}(run).*/i\ \ USE_PDF_ALPHAS=1' -i Run.dat
sed '/.*\}(run).*/i\ \ PDF_SET=NNPDF30_nnlo_as_0118_hessian' -i Run.dat
sed '/.*\}(run).*/i\ \ PDF_VARIATIONS=NNPDF30_nnlo_as_0118_hessian[all] NNPDF30_nnlo_as_0117 NNPDF30_nnlo_as_0119 MSHT20nnlo_as118 CT18NNLO_as_0118 PDF4LHC21_40_pdfas[all] NNPDF31_nnlo_as_0118_hessian NNPDF40_nnlo_as_01180_hessian CT18ANNLO CT18XNNLO CT18ZNNLO' -i Run.dat
sed '/.*\}(run).*/i\ \ OL_PARAMETERS=redlib1=5=redlib2=5=write_parameters=1' -i Run.dat
sed '/.*\}(run).*/i\ \ EW_SCHEME=3' -i Run.dat
sed '/.*\}(run).*/i\ \ GF=1.166397e-5' -i Run.dat
sed "/.*\\}(run).*/i\\  BEAM_ENERGY_1=${ENERGY_BEAM}" -i Run.dat
sed "/.*\\}(run).*/i\\  BEAM_ENERGY_2=${ENERGY_BEAM}" -i Run.dat
source /cvmfs/sft.cern.ch/lcg/releases/gcc/13.1.0-b3d18/x86_64-el9/setup.sh
export PATH=/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/openmpi/4.1.6/x86_64-el9-gcc13-opt/bin:$PATH
export LHAPATH=/cvmfs/sft.cern.ch/lcg/external/lhapdfsets/current:/cvmfs/atlas.cern.ch/repo/sw/Generators/lhapdfsets/current/
export OPAL_PREFIX=/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/openmpi/4.1.6/x86_64-el9-gcc13-opt
export LD_LIBRARY_PATH=/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/openmpi/4.1.6/x86_64-el9-gcc13-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/zlib/*/${LCG_PLATFORM}/lib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/sqlite/*/${LCG_PLATFORM}/lib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a/HepMC/*/${LCG_PLATFORM}/lib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/lhapdf/*/${LCG_PLATFORM}/lib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a_ATLAS_9/fastjet/*/${LCG_PLATFORM}/lib:/cvmfs/atlas.cern.ch/repo/sw/software/23.6/sw/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/openloops/2.1.4/x86_64-el9-gcc13-opt/lib:/cvmfs/atlas.cern.ch/repo/sw/software/23.6/sw/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/openloops/2.1.4/x86_64-el9-gcc13-opt/proclib:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/sherpa/${SHERPAVER}.openmpi3/${LCG_PLATFORM}/lib64/SHERPA-MC:/cvmfs/sft.cern.ch/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/sherpa/${SHERPAVER}.openmpi3/${LCG_PLATFORM}/lib/SHERPA-MC:$LD_LIBRARY_PATH
mpirun -n "$NCORES" /cvmfs/sft.cern.ch/lcg/releases/LCG_107a_ATLAS_9/MCGenerators/sherpa/${SHERPAVER}.openmpi3/${LCG_PLATFORM}/bin/Sherpa EVENTS=0 FRAGMENTATION=Off MI_HANDLER=None BEAM_ENERGY_1=${ENERGY_BEAM} BEAM_ENERGY_2=${ENERGY_BEAM}
exit 0
