echo ""
date
echo ""

#pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=100002 --maxEvents=1000" --outDS user.dcamarer.run2_100002_260319 --split 10 --maxCpuCount 259200
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9998 --outputEVNTFile %OUT.EVNT.root --jobConfig=100002 --maxEvents=250" --outDS user.dcamarer.run2_100002_260321_bis --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
