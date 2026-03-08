evgenConfig.description = "Pythia8 inelastic minimum bias events with the A3 NNPDF23LO tune and EvtGen, no filters."
evgenConfig.keywords = ["QCD", "minBias", "SM"]
evgenConfig.contact  = [ "jeff.dandoy@cern.ch", "jan.kretzschmar@cern.ch", "judith.katzy@cern.ch"]
evgenConfig.nEventsPerJob = 50000

include("Pythia8_i/Pythia8_Base_Fragment.py")

genSeq.Pythia8.Commands += [
    "Tune:ee = 7",
    "Tune:pp = 14",
    "PDF:pSet=LHAPDF6:NNPDF23_lo_as_0130_qed",
    "MultipartonInteractions:bProfile = 2",
    "MultipartonInteractions:pT0Ref = 2.45",
    "MultipartonInteractions:ecmPow = 0.21",
    "MultipartonInteractions:coreRadius = 0.55",
    "MultipartonInteractions:coreFraction = 0.9",
    "SigmaDiffractive:PomFlux = 4",
    "SigmaDiffractive:PomFluxEpsilon = 0.07",
    "SigmaDiffractive:PomFluxAlphaPrime = 0.25",
    "ColourReconnection:range = 1.8",
    "SigmaElastic:rho = 0.0",
    "SigmaDiffractive:mode = 0",
    "SigmaTotal:sigmaXB = 6.416",
    "SigmaTotal:sigmaAX = 6.416",
    "SigmaTotal:sigmaXX = 8.798",
    "SigmaTotal:sigmaAXB = 0.",
    "SigmaDiffractive:OwnbMinDD = 5."
	]

evgenConfig.tune = "A3 NNPDF23LO"

include("Pythia8_i/Pythia8_EvtGen.py")

genSeq.Pythia8.Commands += [ "SoftQCD:inelastic = on" ]

