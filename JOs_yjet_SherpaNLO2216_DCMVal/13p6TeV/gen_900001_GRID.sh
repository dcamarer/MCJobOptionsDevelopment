echo ""
date
echo ""

# Production of 7500 * 20 = 150000 events
# Events / second = 0.236, per day = 20438.4, per week = 143068.8
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900001_ui --maxEvents=7500" --extFile 900001_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_17_35.GRID.tar.gz --outDS user.dcamarer.run3_900001_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
