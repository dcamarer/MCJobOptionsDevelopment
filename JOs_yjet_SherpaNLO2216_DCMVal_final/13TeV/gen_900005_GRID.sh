echo ""
date
echo ""

# Production of 1250 * 40 = 50000 events
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900005_ui --maxEvents=1250" --extFile 900005_ui/mc_13TeV.Sh_216_NNPDF30NNLO_SinglePhoton_pty_280_500.GRID.tar.gz --outDS user.dcamarer.run2_900005_ui_260711 --split 40 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
