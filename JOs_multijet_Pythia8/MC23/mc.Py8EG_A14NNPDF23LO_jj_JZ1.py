# JO for Pythia 8 jet jet JZ1 slice

evgenConfig.description = "Dijet truth jet slice JZ1, with the A14 NNPDF23 LO tune"
evgenConfig.keywords = ["QCD", "jets", "SM"]
evgenConfig.contact = ["amoroso@cern.ch", "jan.kretzschmar@cern.ch"]
evgenConfig.nEventsPerJob = 10000

include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("Pythia8_i/Pythia8_ShowerWeights.py")
genSeq.Pythia8.Commands += ["HardQCD:all = on",
                            "PhaseSpace:Bias2Selection=on",
                            "PhaseSpace:pTHatMin = 5."]

#include("GeneratorFilters/JetFilter_JZ1.py")
include("GeneratorFilters/FindJets.py")
CreateJets(prefiltSeq, 0.6)
AddJetsFilter(filtSeq, runArgs.ecmEnergy, 0.6)
include("GeneratorFilters/JetFilter_JZX.py")
JZSlice(1, filtSeq)
