echo ""
date
echo ""

# Production of 10000 * 10 = 100000 events
# Part 1: RNDM:9999
# Production of 20000 * 10 = 200000 events
# Part 2: RNDM:8888

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:8888 --outputEVNTFile %OUT.EVNT.root --jobConfig=801166 --maxEvents=20000" --outDS user.dcamarer.run3_801166_ui_090926_ext1 --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
