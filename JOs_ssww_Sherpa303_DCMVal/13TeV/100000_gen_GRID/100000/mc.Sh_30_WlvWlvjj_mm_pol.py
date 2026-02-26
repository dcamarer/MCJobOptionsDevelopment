include("Sherpa_i/Base_Fragment.py")
include("Sherpa_i/PDF4LHC21.py")

evgenConfig.description = "Electroweak W-W-jj+0,1j@LO with leptonic decays."
evgenConfig.keywords = ["SM", "diboson", "2lepton", "jets", "VBS"]
evgenConfig.contact  = [ "yi.yu@cern.ch", "aram.apyan@cern.ch", "daniel.camarero.munoz@cern.ch"]
evgenConfig.nEventsPerJob = 10000

genSeq.Sherpa_i.RunCard="""
ME_GENERATORS:
- Comix

WIDTH_SCHEME: Fixed

SCALES: VBF

MEPS:
  CORE_SCALE: VAR{PPerp(p[4])*PPerp(p[5])}

COMIX_DEFAULT_GAUGE: 0

PARTICLE_DATA:
  5:
    Massive: 1

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
    Weight3:  W-.--_W-.++    
    Weight4:  W-.-+_W-.++
    Weight5:  W-.+-_W-.++
    Weight6:  W-.++_W-.++
    Weight7:  W-.-0_W-.++
    Weight8:  W-.+0_W-.++
    Weight9:  W-.00_W-.++
    Weight10: W-.0-_W-.++
    Weight11: W-.0+_W-.++
    Weight12: W-.--_W-.+-
    Weight13: W-.-+_W-.+-
    Weight14: W-.+-_W-.+-
    Weight15: W-.++_W-.+-
    Weight16: W-.-0_W-.+-
    Weight17: W-.+0_W-.+-
    Weight18: W-.00_W-.+-
    Weight19: W-.0-_W-.+-
    Weight20: W-.0+_W-.+-
    Weight21: W-.--_W-.-+
    Weight22: W-.-+_W-.-+
    Weight23: W-.+-_W-.-+
    Weight24: W-.++_W-.-+
    Weight25: W-.-0_W-.-+
    Weight26: W-.+0_W-.-+
    Weight27: W-.00_W-.-+
    Weight28: W-.0-_W-.-+
    Weight29: W-.0+_W-.-+    
    Weight30: W-.--_W-.--
    Weight31: W-.-+_W-.--
    Weight32: W-.+-_W-.--
    Weight33: W-.++_W-.--
    Weight34: W-.-0_W-.--
    Weight35: W-.+0_W-.--
    Weight36: W-.00_W-.--
    Weight37: W-.0-_W-.--
    Weight38: W-.0+_W-.--
    Weight39: W-.--_W-.+0
    Weight40: W-.-+_W-.+0
    Weight41: W-.+-_W-.+0
    Weight42: W-.++_W-.+0
    Weight43: W-.-0_W-.+0
    Weight44: W-.+0_W-.+0
    Weight45: W-.00_W-.+0
    Weight46: W-.0-_W-.+0
    Weight47: W-.0+_W-.+0
    Weight48: W-.--_W-.-0
    Weight49: W-.-+_W-.-0
    Weight50: W-.+-_W-.-0
    Weight51: W-.++_W-.-0
    Weight52: W-.-0_W-.-0
    Weight53: W-.+0_W-.-0
    Weight54: W-.00_W-.-0
    Weight55: W-.0-_W-.-0
    Weight56: W-.0+_W-.-0
    Weight57: W-.--_W-.00
    Weight58: W-.-+_W-.00
    Weight59: W-.+-_W-.00
    Weight60: W-.++_W-.00
    Weight61: W-.-0_W-.00
    Weight62: W-.+0_W-.00
    Weight63: W-.00_W-.00
    Weight64: W-.0-_W-.00
    Weight65: W-.0+_W-.00
    Weight66: W-.--_W-.0+
    Weight67: W-.-+_W-.0+
    Weight68: W-.+-_W-.0+
    Weight69: W-.++_W-.0+
    Weight70: W-.-0_W-.0+
    Weight71: W-.+0_W-.0+
    Weight72: W-.00_W-.0+
    Weight73: W-.0-_W-.0+
    Weight74: W-.0+_W-.0+
    Weight75: W-.--_W-.0-
    Weight76: W-.-+_W-.0-
    Weight77: W-.+-_W-.0-
    Weight78: W-.++_W-.0-
    Weight79: W-.-0_W-.0-
    Weight80: W-.+0_W-.0-
    Weight81: W-.00_W-.0-
    Weight82: W-.0-_W-.0-
    Weight83: W-.0+_W-.0-

# Vector boson production process
PROCESSES:
- 93 93 -> -24 -24 93 93 93{1}:
    Order: {QCD: 0, EW: 4}
    CKKW: 20

# Selection criteria
SELECTORS:
- FastjetSelector:
    Expression: Mass(p[4]+p[5])>110
    Algorithm: antikt
    N: 2
    PTMin: 15.0
    EtaMax: 5.5
    DR: 0.2
"""

genSeq.Sherpa_i.OpenLoopsLibs = []
genSeq.Sherpa_i.ExtraFiles = []
genSeq.Sherpa_i.NCores = 4
