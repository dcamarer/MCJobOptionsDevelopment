include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/NNPDF30NNLO.py")

evgenConfig.description = "Sherpa gamma + 1,2j@NLO + 3,4j@LO with 140<pT_y<280."
evgenConfig.keywords = [ "SM", "photon", "jets", "NLO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "daniel.camarero.munoz@cern.ch" ]
evgenConfig.nEventsPerJob = 200

PT_MIN = 140
PT_MAX = 280
INTEGRATION_ERROR = 0.10

include("sherpa_common.py")
