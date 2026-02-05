include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/NNPDF30NNLO.py")

evgenConfig.description = "Sherpa gamma + 1,2j@NLO + 3,4j@LO with 17<pT_y<35."
evgenConfig.keywords = [ "SM", "photon", "jets", "NLO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "daniel.camarero.munoz@cern.ch" ]
evgenConfig.nEventsPerJob = 1000

genSeq.Sherpa_i.RunCard="""
# Perturbative scales
MEPS:
  CORE_SCALE: VAR{PPerp2(p[2])}
SCALES: METS{MU_F2}{MU_R2}{MU_Q2}
ALPHAQED_DEFAULT_SCALE: 0.0

# ME generator settings
ME_GENERATORS: [Comix, Amegic, OpenLoops]

# Tags for process setup
TAGS: {QCUT: 20, NJET: 4, LJET:2,3}

PROCESSES:
- 93 93 -> 22 93 93{$(NJET)};
  Order: {QCD: Any, EW: 1}
  CKKW: ...

  




SELECTORS:
- [IsolationCut, 22, 0.1, 2, 0.10]
- [PT, 22, 17, 35]
- [Y, 22, -2.7, 2.7]
"""

genSeq.Sherpa_i.NCores = 32
genSeq.Sherpa_i.Parameters += [ "OL_PARAMETERS=write_parameters=1" ]
genSeq.Sherpa_i.Parameters += [ "EW_SCHEME=3", "GF=1.166397e-5" ]

/////////
// OLD //
/////////

genSeq.Sherpa_i.RunCard="""
(processes){
  CKKW sqr(QCUT/E_CMS)/(1.0+sqr(QCUT/0.6)/PPerp2(p[2]));
  Associated_Contributions EW|LO1|LO2|LO3 {LJET};
  NLO_QCD_Mode MC@NLO {LJET};
  ME_Generator Amegic {LJET};
  RS_ME_Generator Comix {LJET};
  Loop_Generator LOOPGEN {LJET};
  Integration_Error 0.10 {2,3,4,5,6,7,8};
  PSI_ItMin 30000 {2,3}
  PSI_ItMin 50000 {4,5,6}  
}(processes)
"""