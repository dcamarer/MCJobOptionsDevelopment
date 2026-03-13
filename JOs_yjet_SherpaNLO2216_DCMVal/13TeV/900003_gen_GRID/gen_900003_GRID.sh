echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:1234 --outputEVNTFile %OUT.EVNT.root --jobConfig=900003 --maxEvents=5000" --outDS user.dcamarer.run2_900003_260313 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
