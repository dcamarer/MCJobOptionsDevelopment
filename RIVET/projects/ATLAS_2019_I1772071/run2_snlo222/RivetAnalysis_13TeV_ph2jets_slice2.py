theApp.EvtMax = -1

import AthenaPoolCnvSvc.ReadAthenaPool

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from Rivet_i.Rivet_iConf import Rivet_i
rivet = Rivet_i()
import os
rivet.AnalysisPath = os.environ['PWD']

rivet.Analyses += [ 'ATLAS_2019_I1772071' ]
rivet.RunName = ''
rivet.HistoFile = "run2_snlo222_pty_35_70.yoda.gz"

# DESCRIPTION: put the cross section here in pb
rivet.CrossSection = 43976.0

# DESCRIPTION: ?
#rivet.IgnoreBeamCheck = True

# DESCRIPTION: skip theory variations
rivet.SkipWeights=False

job += rivet
