echo ""
date
echo ""

# Need to create and make the libs for the GRID
#sherpaTarCreator.py 900001 --ecm 13.0 -o getOpenLoops
#sherpaTarCreator.py 900001 --ecm 13.0 -o createLibs
#sherpaTarCreator.py 900001 --ecm 13.0 -o makelibs

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900001 --maxEvents=15000" --outDS user.dcamarer.run2_900001_260320 --split 10 --maxCpuCount 259200

# --nFilesPerJob 1

echo ""
date
echo ""
echo "C'est fini!"
echo ""
