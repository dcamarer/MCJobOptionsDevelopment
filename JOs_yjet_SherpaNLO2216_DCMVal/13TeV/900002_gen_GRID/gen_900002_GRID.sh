echo ""
date
echo ""

cd 900002
./makelibs
cd ../
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900002 --maxEvents=20000" --outDS user.dcamarer.run2_900002_260319 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
