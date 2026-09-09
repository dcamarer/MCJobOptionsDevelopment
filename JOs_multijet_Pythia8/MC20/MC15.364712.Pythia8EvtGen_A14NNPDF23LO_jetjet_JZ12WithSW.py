# JO for Pythia 8 jet jet JZ12 slice

evgenConfig.description = "Dijet truth jet slice JZ12, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch"]





include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["HardQCD:all = on",
                            "PhaseSpace:Bias2Selection=on",
                            "PhaseSpace:pTHatMin = 4200."]



include("MC15JobOptions/JetFilter_JZ12.py")
evgenConfig.minevents = 100





