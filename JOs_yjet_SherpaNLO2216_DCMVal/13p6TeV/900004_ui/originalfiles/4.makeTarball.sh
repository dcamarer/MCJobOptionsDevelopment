#!/bin/sh -
ulimit -f 1000000;
cd /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13p6TeV/900004_ui/900004/ecm13p6TeV

echo 'ncores=1 nhours=1 /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13p6TeV/900004_ui/900004/ecm13p6TeV/4.makeTarball.sh';
set -e
tar czhf /afs/cern.ch/work/d/dcamarer/private/PostDoc/PMG/MCJobOptionsDevelopment/JOs_yjet_SherpaNLO2216_DCMVal/13p6TeV/900004_ui/900004/mc_13p6TeV.Sh_22_NNPDF30NNLO_SinglePhoton_pty_140_280.GRID.tar.gz $(ls -d Results.db Process 3.integrate.log 2>/dev/null) 
exit 0
