# JO for Pythia 8 jet jet JZ4 slice

evgenConfig.description = "Dijet truth jet slice JZ4, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch"]





include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["HardQCD:all = on",
                            "PhaseSpace:Bias2Selection=on",
                            "PhaseSpace:pTHatMin = 150."]

include("MC15JobOptions/JetFilter_JZ4.py")
evgenConfig.minevents = 1000





