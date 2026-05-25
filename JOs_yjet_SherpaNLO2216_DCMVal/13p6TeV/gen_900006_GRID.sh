echo ""
date
echo ""

# Production of 500 * 20 = 10000 events
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900006_ui --maxEvents=500" --extFile 900006_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_500_1000.GRID.tar.gz --outDS user.dcamarer.run3_900006_ui_260526 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
