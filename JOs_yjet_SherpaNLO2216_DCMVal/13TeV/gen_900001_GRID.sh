echo ""
date
echo ""

# Production of 10000 * 20 = 200000 events
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900001_ui --maxEvents=10000" --extFile 900001_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_17_35.GRID.tar.gz --outDS user.dcamarer.run2_900001_ui_260526 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
