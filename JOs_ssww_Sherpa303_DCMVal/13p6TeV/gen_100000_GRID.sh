echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:1234 --outputEVNTFile %OUT.EVNT.root --jobConfig=100000 --maxEvents=30000" --outDS user.dcamarer.run2_100000 --split 6 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""