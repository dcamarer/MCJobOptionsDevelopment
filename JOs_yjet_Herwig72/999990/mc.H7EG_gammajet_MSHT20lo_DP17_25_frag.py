# Note: updated for Run 3 studies in 2023 by Daniel Camarero

## Initialise Herwig7 for run with built-in matrix elements
include("Herwig7_i/Herwig7_BuiltinME.py")
include("Herwig7_i/Herwig7_EvtGen.py")

## Provide config information
evgenConfig.generators += ["Herwig7"]
evgenConfig.tune        = "H7.2-Default"
evgenConfig.description = "Photon+jet production with H71UE default tune"
evgenConfig.keywords = ["QCD", "photon", "jets"]
evgenConfig.contact  = [ "jan.kretzschmar@cern.ch", "daniel.camarero.munoz@cern.ch" ]
evgenConfig.nEventsPerJob = 10

## hard process setup
Herwig7Config.add_commands("set /Herwig/Partons/RemnantDecayer:AllowTop Yes")
Herwig7Config.me_pdf_commands(order="LO", name="MSHT20lo_as130")

command = """
insert /Herwig/MatrixElements/SubProcess:MatrixElements[0] /Herwig/MatrixElements/MEQCD2to2
set /Herwig/UnderlyingEvent/MPIHandler:IdenticalToUE 0
set /Herwig/Cuts/JetKtCut:MinKT 8.5*GeV
"""

print (command)

Herwig7Config.add_commands(command)

include("GeneratorFilters/DirectPhotonFilter.py")
filtSeq.DirectPhotonFilter.NPhotons = 1
filtSeq.DirectPhotonFilter.Ptmin = [ 17000. ]
filtSeq.DirectPhotonFilter.Ptmax = [ 25000. ]
filtSeq.DirectPhotonFilter.OrderPhotons = True

## run the generator
Herwig7Config.run(shower_var=False)