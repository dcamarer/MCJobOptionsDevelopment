echo ""
date
echo ""

# Production of 4500 * 40 = 180000 events
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900004_ui --maxEvents=4500" --extFile 900004_ui/mc_13p6TeV.Sh_216_NNPDF30NNLO_SinglePhoton_pty_140_280.GRID.tar.gz --outDS user.dcamarer.run3_900004_ui_260711 --split 40 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
