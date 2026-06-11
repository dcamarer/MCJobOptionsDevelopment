echo ""
date
echo ""

# Production of 3000 * 20 = 60000 events
# Events / second = 0.099,  per day = 8553.6, per week = 59875.2
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900004_ui --maxEvents=3000" --extFile 900004_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_140_280.GRID.tar.gz --outDS user.dcamarer.run3_900004_ui_260611 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
