## To merge a set of EVNT files from a local or Grid generation:

# Standard setup for e.g. release used for Sherpa 2.2.16

setupATLAS
asetup AthGeneration,23.6.49,here

# Combine all input files (e.g. for run2_900007)

mkdir COMBO_EVNT; cd COMBO_EVNT;
EVNTMerge_tf.py --inputEVNTFile ../run2_900007_part* --outputEVNT_MRGFile run2_Sh2216_900007.EVNT.root

# You'll need to compute the cross-section of the sample from the averaging of the log.generate parts

