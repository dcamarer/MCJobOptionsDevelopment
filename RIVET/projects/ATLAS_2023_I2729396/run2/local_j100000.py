theApp.EvtMax = -1

import re, os, glob

evntfiles=[]
xssum=0.
effsum=0.
nfiles=0

period="run2"
dir="/eos/user/d/dcamarer/PostDoc/Run3_ssWW_polarisation/Sherpa3/13TeV/v1/100000_merging/100000_parts"
for part in range(1, 7):  # 1 to 6 inclusive
    evntfile=dir+"/" + period + "_100000_part" + str(part) + ".EVNT.root"
    if os.path.exists(evntfile):
        with open(dir+"/log.generate_part" + str(part)) as logfile:
            for line in logfile:
                xsline = re.findall(r'MetaData: cross-section', line)
                if xsline:
                    xsline = line.split(' ')[4]
                    xssum += float(xsline)
                    evntfiles.append(evntfile)
                    nfiles += 1
                effline = re.findall(r'MetaData: GenFiltEff', line)
                if effline:
                    effline = line.split(' ')[4]
                    effsum += float(effline)

import AthenaPoolCnvSvc.ReadAthenaPool
svcMgr.EventSelector.InputCollections = evntfiles

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from xAODEventInfoCnv.xAODEventInfoCnvConf import xAODMaker__EventInfoCnvAlg
job += xAODMaker__EventInfoCnvAlg()

from Rivet_i.Rivet_iConf import Rivet_i

rivet = Rivet_i()
rivet.Analyses += [ 'ATLAS_2023_I2729396' ]
rivet.RunName = ''
rivet.HistoFile = 'run2_100000_WmWm.yoda.gz'
print (xssum/float(nfiles) * effsum/float(nfiles))
rivet.CrossSection = xssum/nfiles * effsum/nfiles
#rivet.IgnoreBeamCheck = True
#rivet.SkipWeights=True
job += rivet
