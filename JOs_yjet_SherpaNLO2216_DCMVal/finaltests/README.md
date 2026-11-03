# Preparing the final tests

## Setup

source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh
asetup AthGeneration,23.6.49

## Running

Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701554 --outputEVNTFile=outputEVNTFile_701554_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701555 --outputEVNTFile=outputEVNTFile_701555_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701556 --outputEVNTFile=outputEVNTFile_701556_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701557 --outputEVNTFile=outputEVNTFile_701557_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701558 --outputEVNTFile=outputEVNTFile_701558_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701559 --outputEVNTFile=outputEVNTFile_701559_13TeV.root
Gen_tf.py --ecmEnergy=13000 --maxEvents=5 --firstEvent=1 --randomSeed=10 --jobConfig=701560 --outputEVNTFile=outputEVNTFile_701560_13TeV.root
