echo ""
date
echo ""

# Production of 7500 * 20 = 150000 events
# Events / second = 0.256, per day = 22118.4, per week = 154828.8
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900003_ui --maxEvents=7500" --extFile 900003_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_70_140.GRID.tar.gz --outDS user.dcamarer.run2_900003_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
