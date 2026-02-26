include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/PDF4LHC21.py")

evgenConfig.description = "Electroweak same-sign llvvjj+0,1j@LO."
evgenConfig.keywords = ["SM", "diboson", "2lepton", "jets", "VBS"]
evgenConfig.contact  = [ "yi.yu@cern.ch", "aram.apyan@cern.ch", "daniel.camarero.munoz@cern.ch"]
evgenConfig.nEventsPerJob = 1000

genSeq.Sherpa_i.RunCard="""
ME_GENERATORS:
- Comix

SCALES: VBF

MEPS:
  CORE_SCALE: VAR{PPerp(p[6])*PPerp(p[7])}

COMIX_DEFAULT_GAUGE: 0

PARTICLE_DATA:
  5:
    Massive: 1

# improve integration
PSI:
  ITMIN: 25000
  NOPT: 15

# Vector boson production process
PROCESSES:
- 93 93 -> -12 11 -12 11 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20
- 93 93 -> -12 11 -14 13 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20
- 93 93 -> -14 13 -14 13 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20
- 93 93 -> 12 -11 12 -11 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20
- 93 93 -> 12 -11 14 -13 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20
- 93 93 -> 14 -13 14 -13 93 93 93{1}:
    Order: {QCD: 0, EW: 6}
    CKKW: 20

# Selection criteria
SELECTORS:
- FastjetSelector:
    Expression: Mass(p[6]+p[7])>110
    Algorithm: antikt
    N: 2
    PTMin: 15.0
    EtaMax: 5.5
    DR: 0.2
"""

genSeq.Sherpa_i.OpenLoopsLibs = []
genSeq.Sherpa_i.ExtraFiles = []
genSeq.Sherpa_i.NCores = 16
