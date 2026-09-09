# JO for Pythia 8 jet jet JZ0 slice

evgenConfig.description = "Dijet truth jet slice JZ0, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch"]


include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["SoftQCD:inelastic = on"]

include("MC15JobOptions/JetFilter_JZ0.py")
evgenConfig.minevents = 1000





