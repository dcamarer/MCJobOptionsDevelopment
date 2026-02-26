echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:1234 --outputEVNTFile %OUT.EVNT.root --jobConfig=100002 --maxEvents=10000" --outDS user.dcamarer.run2_100002_260227 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
