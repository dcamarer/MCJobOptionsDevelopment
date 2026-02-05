include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/NNPDF30NNLO.py")

evgenConfig.description = "Sherpa gamma + 1,2j@NLO + 3,4j@LO with 280<pT_y<500."
evgenConfig.keywords = [ "SM", "photon", "jets", "NLO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "daniel.camarero.munoz@cern.ch" ]
evgenConfig.nEventsPerJob = 100

genSeq.Sherpa_i.RunCard="""
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
  NJET:=4; LJET:=2,3; QCUT:=20.;

  # EW corrections setup
  ASSOCIATED_CONTRIBUTIONS_VARIATIONS=EW EW|LO1 EW|LO1|LO2;
  EW|LO1|LO2|LO3;
  METS_BBAR_MODE=5;
  EW_SCHEME=3;
  GF=1.166397e-5;
  KFACTOR VAR{128.802/137.03599976};
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
  Integration_Error 0.10 {2,3,4,5,6,7,8};
  PSI_ItMin 30000 {2,3}
  PSI_ItMin 50000 {4,5,6}
  End process;
}(processes)

(selector){
  IsolationCut  22  0.1  2  0.10
  PTNLO 22  280  500
  RapidityNLO  22  -2.7  2.7
}(selector)
"""

genSeq.Sherpa_i.NCores = 24
genSeq.Sherpa_i.MemoryMB = 3000
genSeq.Sherpa_i.Parameters += [ "OL_PARAMETERS=write_parameters=1" ]
genSeq.Sherpa_i.Parameters += [ "EW_SCHEME=3", "GF=1.166397e-5" ]