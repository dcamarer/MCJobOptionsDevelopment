# JO for Pythia 8 jet jet JZ11 slice

evgenConfig.description = "Dijet truth jet slice JZ11, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch"]





include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["HardQCD:all = on",
                            "PhaseSpace:Bias2Selection=on",
                            "PhaseSpace:pTHatMin = 3500."]


include("MC15JobOptions/JetFilter_JZ11.py")
evgenConfig.minevents = 1000





