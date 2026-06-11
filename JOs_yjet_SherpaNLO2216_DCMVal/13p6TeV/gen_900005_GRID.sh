echo ""
date
echo ""

# Production of 500 * 20 = 20000 events
# Events / second = 0.017, per day = 1468.8, per week = 10281.6
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900005_ui --maxEvents=500" --extFile 900005_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_280_500.GRID.tar.gz --outDS user.dcamarer.run3_900005_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
