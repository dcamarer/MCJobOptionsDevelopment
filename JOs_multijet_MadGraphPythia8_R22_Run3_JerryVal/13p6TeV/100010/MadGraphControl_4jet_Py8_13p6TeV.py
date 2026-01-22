# Import all of the necessary methods to use MadGraph
from MadGraphControl.MadGraphUtils import *
from MadGraphControl.MadGraph_NNPDF30NLO_Base_Fragment import *

# Some includes that are necessary to interface MadGraph with Pythia
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("Pythia8_i/Pythia8_MadGraph.py")

HTDict = {0:0,1:100,2:200,3:300,4:500,5:700,6:1000,7:1500,8:2000,9:4000,10:6000,11:8000,12:13600}
multDict = {0:1.1,1:1.2,2:2.2,3:4.0,4:5.0,5:6.0,6:7.0,7:8.0,8:9.0,9:10.0,10:10.0,11:10.0,12:10.0}

# Number of events to produce
safety = multDict[slice]
# safety = 1.15
nevents = runArgs.maxEvents * safety
nevents = runArgs.maxEvents * safety if runArgs.maxEvents > 0 else evgenConfig.nEventsPerJob * safety

gridpack_mode=True

# Here is where we define the commands that will be passed to MadGraph

# Import the sm
process = """
import model sm
"""

# Define the physics process to be simulated
process += """
generate p p > j j @0
add process p p > j j j @1
add process p p > j j j j @2
"""

# This defines the MadGraph outputs
process += """
output -f
"""

merging_scale = 30.0

# Define the process and create the run card from a template
process_dir = new_process(process)
settings = {
    'run_tag': "'A14N23LO'",
    'asrwgtflavor': 5,
    'ptj': 0.0,
    'drjj': 0.0 ,
    'drjl': 0.4,
    'xqcut': 10.0,
    'htjmin': HTDict[slice-1],
    'htjmax': HTDict[slice],
    'dparameter': 0.4,
    'maxjetflavor': 5,
    'ktdurham': merging_scale,
    'ickkw': 0, 
    # 'use_syst':'T',
    # 'sys_scalefact':'0.5 1 2',
    'sys_alpsfact': 'None',
    'sys_matchscale': 'None',
    'dynamical_scale_choice': 1,
    'auto_ptj_mjj': 'F',
    'nevents':nevents, 
    }
modify_run_card(process_dir=process_dir,runArgs=runArgs,settings=settings)

# Create the param card and modify some parameters from their default values
modify_param_card(process_dir=process_dir)

# Do the event generation
generate(process_dir=process_dir,runArgs=runArgs,grid_pack=gridpack_mode)

arrange_output(process_dir=process_dir, runArgs=runArgs)

# Commands for CKKW Matching in Pythia
PYTHIA8_nJetMax=2
PYTHIA8_TMS=merging_scale
PYTHIA8_Dparameter=0.4
PYTHIA8_Process="pp>jj"
PYTHIA8_nQuarksMerge=5

include("Pythia8_i/Pythia8_CKKWL_kTMerge.py")
genSeq.Pythia8.Commands += ["Merging:usePythiaQRenHard = off",
                            "Merging:usePythiaQFacHard = off"]