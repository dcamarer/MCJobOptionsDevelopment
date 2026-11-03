include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/NNPDF30NNLO.py")

evgenConfig.description = "Sherpa gamma + 1,2j@NLO + 3,4j@LO with 70<pT_y<140."
evgenConfig.keywords = [ "SM", "photon", "jets", "NLO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "daniel.camarero.munoz@cern.ch" ]
evgenConfig.nEventsPerJob = 500

PT_MIN = 70
PT_MAX = 140
INTEGRATION_ERROR = 0.10

include("sherpa_common.py")
