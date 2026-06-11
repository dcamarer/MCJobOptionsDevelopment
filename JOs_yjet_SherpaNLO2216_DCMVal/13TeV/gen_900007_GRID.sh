echo ""
date
echo ""

# Production of 200 * 20 = 4000 events
# Events / second = 0.006, per day = 518.4, per week = 3628.8
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007_ui --maxEvents=200" --extFile 900007_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.GRID.tar.gz --outDS user.dcamarer.run2_900007_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
