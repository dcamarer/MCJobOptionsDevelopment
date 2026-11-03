# Shared Sherpa setup for the single-photon pT slices 701554-701560.
# Each including job option defines PT_MIN, PT_MAX, and INTEGRATION_ERROR.

genSeq.Sherpa_i.RunCard = (
    """
(run){
  # Perturbative scales
  FSF:=1.; RSF:=1.; QSF:=1.;
  SCALES STRICT_METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};
  CORE_SCALE VAR{PPerp2(p[2])};
  
  # ME generator settings
  ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;
  LOOPGEN:=OpenLoops;

  # Tags for process setup
  NJET:=3; LJET:=2,3; QCUT:=20.;

  # EW corrections setup
  ASSOCIATED_CONTRIBUTIONS_VARIATIONS=EW EW|LO1 EW|LO1|LO2 EW|LO1|LO2|LO3;
  METS_BBAR_MODE=5;
  KFACTOR VAR{132.346/137.03599976};

  # Speed and neg weight fraction improvements
  PP_RS_SCALE VAR{H_T2/4};
  NLO_CSS_PSMODE=1;
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
  PSI_ItMin 30000 {2,3};
  Integration_Error @@INTEGRATION_ERROR@@ {2,3};
  PSI_ItMin 50000 {4};
  Integration_Error @@INTEGRATION_ERROR@@ {4};
  PSI_ItMin 100000 {5};
  Integration_Error @@INTEGRATION_ERROR@@ {5};
  End process;
}(processes)

(selector){
  IsolationCut  22  0.1  2  0.10
  PTNLO 22  @@PT_MIN@@  @@PT_MAX@@
  RapidityNLO  22  -2.7  2.7
}(selector)
    """
    .replace("@@INTEGRATION_ERROR@@", str(INTEGRATION_ERROR))
    .replace("@@PT_MIN@@", str(PT_MIN))
    .replace("@@PT_MAX@@", str(PT_MAX))
)

genSeq.Sherpa_i.NCores = 12
genSeq.Sherpa_i.Parameters += [ "OL_PARAMETERS=ew_renorm_scheme=1 write_parameters=1" ]
genSeq.Sherpa_i.Parameters += [ "EW_SCHEME=3", "GF=1.166397e-5" ]
