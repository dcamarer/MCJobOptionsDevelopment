echo ""
date
echo ""

# Production of 4000 * 20 = 80000 events
# Events / second = 0.129, per day = 11136, per week = 77952
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900002_ui --maxEvents=4000" --extFile 900002_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_35_70.GRID.tar.gz --outDS user.dcamarer.run2_900002_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
