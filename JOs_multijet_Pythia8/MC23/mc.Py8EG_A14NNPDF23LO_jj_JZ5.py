# JO for Pythia 8 jet jet JZ5 slice

evgenConfig.description = "Dijet truth jet slice JZ5, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch", "jan.kretzschmar@cern.ch"]
evgenConfig.nEventsPerJob = 10000

include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("Pythia8_i/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["HardQCD:all = on",
                            "PhaseSpace:Bias2Selection=on",
                            "PhaseSpace:pTHatMin = 350."]

#include("GeneratorFilters/JetFilter_JZ5.py")
include("GeneratorFilters/FindJets.py")
CreateJets(prefiltSeq, 0.6)
AddJetsFilter(filtSeq, runArgs.ecmEnergy, 0.6)
include("GeneratorFilters/JetFilter_JZX.py")
JZSlice(5, filtSeq)
