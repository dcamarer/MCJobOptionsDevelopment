echo ""
date
echo ""

# Production of 15000 * 10 = 150000 events
# Part 1: RNDM:9999

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=801166 --maxEvents=10000" --outDS user.dcamarer.run3_801166_ui_090926 --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
