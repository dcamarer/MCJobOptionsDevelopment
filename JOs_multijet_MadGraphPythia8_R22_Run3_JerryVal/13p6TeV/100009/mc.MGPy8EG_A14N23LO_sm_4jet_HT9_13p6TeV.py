slice = 9

evgenConfig.description = 'madgraph+pythia8, 4-jet slice HT9'
evgenConfig.contact = [ "Jerry Wu <yqjerry.wu@mail.utoronto.ca>" ]
evgenConfig.keywords += ['QCD', 'SM', 'jets']

evgenConfig.nEventsPerJob = 10000
include("MadGraphControl_4jet_Py8_13p6TeV.py")