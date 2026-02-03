include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/PDF4LHC21.py")

evgenConfig.description = "Electroweak W-W-jj+0,1j@LO with leptonic decays with a t-channel requirement to suppress triboson final states."
evgenConfig.keywords = ["SM", "diboson", "2lepton", "jets", "VBS"]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "daniel.camarero.munoz@cern.ch"]
evgenConfig.nEventsPerJob = 10000

genSeq.Sherpa_i.RunCard="""
ME_GENERATORS:
- Comix

WIDTH_SCHEME: Fixed

SCALES: VBF

MEPS:
  CORE_SCALE: VAR{PPerp(p[4])*PPerp(p[5])}

COMIX_DEFAULT_GAUGE: 0

# improve integration
PSI:
  ITMIN: 15000
  NOPT: 12

# Vector boson decay process
HARD_DECAYS:
  Enabled: true
  Mass_Smearing: 1
  Channels:
    -24,-12,11: {Status: 2}
    -24,-14,13: {Status: 2}
# Settings for polarized cross sections
  Pol_Cross_Section:
    Enabled: true
    Reference_System: [COM, PPFr]
    Weight1: W-.0_W-.T, W-.T_W-.0
    Weight2: W-.0_W-.T, W-.T_W-.0, W-.0_W-.0

# Vector boson production process
PROCESSES:
- 93 93 -> -24 -24 93 93 93{1}:
    Order: {QCD: 0, EW: 4}
    CKKW: 20

# Selection criteria
SELECTORS:
- FastjetSelector:
    Expression: Mass(p[4]+p[5])>400
    Algorithm: antikt
    N: 2
    PTMin: 15.0
    EtaMax: 5.5
    DR: 0.2
"""

genSeq.Sherpa_i.OpenLoopsLibs = []
genSeq.Sherpa_i.ExtraFiles = []
genSeq.Sherpa_i.NCores = 32
