echo ""
date
echo ""

# Production of 5000 * 20 = 100000 events
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900003_ui --maxEvents=5000" --extFile 900003_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_70_140.GRID.tar.gz --outDS user.dcamarer.run3_900003_ui_260526 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
