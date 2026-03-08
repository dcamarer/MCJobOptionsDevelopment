#based on 361033
evgenConfig.description = "Inelastic minimum bias, with the A2 MSTW2008LO tune and EvtGen"

evgenConfig.keywords = ["QCD", "minBias", "SM"]

# Note: The tune used here (A2 MSTW2008LO) is not the standard one for high pT physics.  It is what we use for pile up at the start of run 2.  For standard high pT physics samples for MC15/run2 please see the A14 NNPDF23LO tune

include("Pythia8_i/Pythia8_A2_MSTW2008LO_EvtGen_Common.py")

genSeq.Pythia8.Commands += ["SoftQCD:inelastic = on"]

evgenConfig.nEventsPerJob = 1000
