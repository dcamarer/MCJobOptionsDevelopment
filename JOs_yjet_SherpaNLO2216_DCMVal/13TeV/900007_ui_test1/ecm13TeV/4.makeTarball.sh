#!/bin/sh -

# Default configuration
BASE_DIR="/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900007_ui_test1"
BASE_DIR_ext="${BASE_DIR}/ecm13TeV"
BASE_JO="Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS"

echo "$BASE_DIR"
echo "$BASE_DIR_ext"
echo "$BASE_JO"

ulimit -f 1000000;
cd ${BASE_DIR_ext}

echo "ncores=1 nhours=1 ${BASE_DIR_ext}/4.makeTarball.sh";
set -e
tar czhf ${BASE_DIR}/mc_13TeV.${BASE_JO}.GRID.tar.gz $(ls -d Results.db Process 3.integrate.log 2>/dev/null) 
exit 0
