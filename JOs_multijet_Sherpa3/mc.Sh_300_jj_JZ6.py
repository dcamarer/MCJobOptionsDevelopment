include("Sherpa_i/Base_Fragment.py")

evgenConfig.description = "Merged 2->2 + 2->3 + 2->4 + 2->5 multijet production at LO in QCD"
evgenConfig.keywords = ['jets', 'dijet', 'LO', 'QCD', 'SM']
evgenConfig.contact  = ['luca.colangeli@mail.utoronto.ca']
evgenConfig.tune = "CT18NNLO"
evgenConfig.nEventsPerJob = 500

genSeq.Sherpa_i.RunCard="""
PDF_LIBRARY: LHAPDFSherpa
PDF_SET: CT18NNLO

PROCESSES:
- 93 93 -> 93 93 93{3}:
    Order: {QCD: Any, EW: 0}
    CKKW: 20
    Integration_Error: 0.02

SELECTORS:
- NJetFinder:
    N: 2
    PTMin: 10.0
    ETMin: 0.0
    R: 0.4
    Exp: -1

- NJetFinder:
    N: 1
    PTMin: 850.0
    ETMin: 0.0
    R: 0.4
    Exp: -1
"""

        
include("GeneratorFilters/FindJets.py")
CreateJets(prefiltSeq, 0.6)
AddJetsFilter(filtSeq, runArgs.ecmEnergy, 0.6)
JZSlice(6, filtSeq)
