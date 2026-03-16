# mc15_13TeV.364541.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_17_35.evgen.EVNT.e6788
# mc15_13TeV.364542.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_35_70.evgen.EVNT.e6788
# mc15_13TeV.364543.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_70_140.evgen.EVNT.e5938
# mc15_13TeV.364544.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_140_280.evgen.EVNT.e5938
# mc15_13TeV.364545.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_280_500.evgen.EVNT.e5938
# mc15_13TeV.364546.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_500_1000.evgen.EVNT.e5938
# mc15_13TeV.364547.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.evgen.EVNT.e6068

lsetup panda
pathena --extOutFile=run2_snlo222_pty_1000_E_CMS.yoda.gz \
        --inDS=mc15_13TeV.364547.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.evgen.EVNT.e6068 \
        --outDS=user.dcamarer.364547.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.analph2jets.v0 \
        RivetAnalysis_13TeV_ph2jets_slice7.py
