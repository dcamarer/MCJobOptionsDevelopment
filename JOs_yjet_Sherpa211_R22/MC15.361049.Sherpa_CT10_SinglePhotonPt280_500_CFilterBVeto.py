include("MC15JobOptions/Sherpa_CT10_Common.py")

evgenConfig.description = "gamma + 1,2,3,4 jets with 280<pT_y<500"
evgenConfig.keywords = ["SM", "photon"]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "frank.siegert@cern.ch" ]
evgenConfig.minevents = 1000
evgenConfig.inputconfcheck = "Sherpa_CT10_SinglePhotonPt280_500"

evgenConfig.process="""
(run){
  % scales, tags for scale variations
  FSF:=1.; RSF:=1.; QSF:=1.;
  SCALES METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};
  CORE_SCALE VAR{PPerp2(p[2])};

  % tags for process setup
  NJET:=3; QCUT:=20;
}(run)

(processes){
  Process 93 93 -> 22 93 93{NJET};
  Order_EW 1;
  CKKW sqr(QCUT/E_CMS)/(1.0+sqr(QCUT/0.6)/PPerp2(p[2]));
  Scales LOOSE_METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2} {7,8};
  End process;
}(processes)

(selector){
  PT  22  280 500
  IsolationCut  22  0.3  2  0.025;
}(selector)
"""

# Set up hadron filters
include("MC15JobOptions/BHadronFilter.py")
include("MC15JobOptions/CHadronFilter.py")
filtSeq += HeavyFlavorBHadronFilter
filtSeq += HeavyFlavorCHadronFilter
filtSeq.Expression = "(HeavyFlavorCHadronFilter) and (not HeavyFlavorBHadronFilter)"
