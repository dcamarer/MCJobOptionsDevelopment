#!/bin/sh -
ulimit -f 1000000;
cd /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006/ecm13TeV

echo 'ncores=1 nhours=1 /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006/ecm13TeV/4.makeTarball.sh';
set -e
tar czhf /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13TeV/900006/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_500_1000.GRID.tar.gz $(ls -d Results.db Process 3.integrate.log 2>/dev/null) 
exit 0
