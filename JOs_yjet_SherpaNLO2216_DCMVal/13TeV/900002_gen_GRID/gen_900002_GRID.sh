echo ""
date
echo ""

# Needed to unpack and avoid libraries issues (e.g. Have to compile Amegic libraries, you probably want to run ./makelibs)
Gen_tf.py --ecmEnergy=13000 --randomSeed=9999 --jobConfig=900002 --outputEVNTFile=test.EVNT.root --maxEvents=1

echo ""
echo " ===> DCM : Local generation done"

./makelibs

echo ""
echo " ===> DCM : ./makelibs done"

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900002 --maxEvents=20000" --outDS user.dcamarer.run2_900002_260319 --split 10 --maxCpuCount 259200

echo ""
echo " ===> DCM : Grid generation job submission"

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
