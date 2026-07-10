echo ""
date
echo ""

# Production of 7500 * 40 = 300000 events
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900001_ui --maxEvents=7500" --extFile 900001_ui/mc_13p6TeV.Sh_216_NNPDF30NNLO_SinglePhoton_pty_17_35.GRID.tar.gz --outDS user.dcamarer.run3_900001_ui_260711 --split 40 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
