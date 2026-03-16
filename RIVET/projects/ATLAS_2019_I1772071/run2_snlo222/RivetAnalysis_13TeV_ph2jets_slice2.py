theApp.EvtMax = -1

import AthenaPoolCnvSvc.ReadAthenaPool

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from xAODEventInfoCnv.xAODEventInfoCnvConf import xAODMaker__EventInfoCnvAlg
job += xAODMaker__EventInfoCnvAlg()

from Rivet_i.Rivet_iConf import Rivet_i
rivet = Rivet_i()
import os
rivet.AnalysisPath = os.environ['PWD']

rivet.Analyses += [ 'ATLAS_2019_I1772071' ]
rivet.RunName = ''
rivet.HistoFile = 'run2_snlo222_pty_35_70.yoda.gz'
rivet.CrossSection = 43976.0 # xsec in pb
#rivet.IgnoreBeamCheck = True
#rivet.SkipWeights = True
job += rivet