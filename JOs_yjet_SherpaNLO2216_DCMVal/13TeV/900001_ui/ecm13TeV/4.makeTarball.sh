#!/bin/sh -
ulimit -f 1000000;
cd /home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_ui/ecm13TeV

echo 'ncores=1 nhours=1 /home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_ui/ecm13TeV/4.makeTarball.sh';
set -e
tar czhf /home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900001_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_17_35.GRID.tar.gz $(ls -d Results.db Process 3.integrate.log 2>/dev/null) 
exit 0
