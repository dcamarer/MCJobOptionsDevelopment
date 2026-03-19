echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:1234 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007 --maxEvents=800" --outDS user.dcamarer.run2_900007_260319 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
