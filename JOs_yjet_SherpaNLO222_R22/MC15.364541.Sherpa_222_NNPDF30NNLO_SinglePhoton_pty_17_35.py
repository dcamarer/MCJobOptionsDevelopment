include("MC15JobOptions/Sherpa_2.2.2_NNPDF30NNLO_Common.py")

evgenConfig.description = "Sherpa gamma + 1,2j@NLO + 3,4j@LO with 17<pT_y<35."
evgenConfig.keywords = ["SM", "photon", "NLO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "frank.siegert@cern.ch", "heberth.torres@cern.ch" ]
evgenConfig.minevents = 1000
evgenConfig.inputconfcheck = "Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_17_35"

Sherpa_iRunCard="""
(run){
  % scales, tags for scale variations
  FSF:=1.; RSF:=1.; QSF:=1.;
  SCALES STRICT_METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};
  CORE_SCALE VAR{PPerp2(p[2])};

  ALPHAQED_DEFAULT_SCALE=0.0

  % tags for process setup
  NJET:=3; LJET:=2,3; QCUT:=20;

  % me generator settings
  ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;
  LOOPGEN:=OpenLoops;
}(run)

(processes){
  Process 93 93 -> 22 93 93{NJET}
  Order (*,1)
  CKKW sqr(QCUT/E_CMS)/(1.0+sqr(QCUT/0.6)/PPerp2(p[2]))
  NLO_QCD_Mode MC@NLO {LJET}
  ME_Generator Amegic {LJET}
  RS_ME_Generator Comix {LJET}
  Loop_Generator LOOPGEN {LJET}
  PSI_ItMin 20000 {3}
  Integration_Error 0.99 {3}
  PSI_ItMin 50000 {4,5}
  Integration_Error 0.99 {4,5}
  End process
}(processes)

(selector){
  IsolationCut  22  0.1  2  0.10
  PTNLO 22  17  35
  RapidityNLO  22  -2.7  2.7
}(selector)
"""

genSeq.Sherpa_i.Parameters += [ "OL_PARAMETERS=redlib1=5=redlib2=5=write_parameters=1" ]

Sherpa_iOpenLoopsLibs = [ "ppaj", "ppajj" ]
Sherpa_iNCores = 240
