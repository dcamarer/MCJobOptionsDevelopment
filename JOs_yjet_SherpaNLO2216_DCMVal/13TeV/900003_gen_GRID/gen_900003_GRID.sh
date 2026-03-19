echo ""
date
echo ""

# Needed to unpack and avoid libraries issues (e.g. Have to compile Amegic libraries, you probably want to run ./makelibs)
Gen_tf.py --ecmEnergy=13000 --randomSeed=9999 --jobConfig=900003 --outputEVNTFile=test.EVNT.root --maxEvents=1

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900003 --maxEvents=12500" --outDS user.dcamarer.run2_900003_260319 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
