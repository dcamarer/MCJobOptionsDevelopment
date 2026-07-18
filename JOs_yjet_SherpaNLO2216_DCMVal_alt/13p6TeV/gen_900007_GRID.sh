echo ""
date
echo ""

# Production of 400 * 40 = 16000 events
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007_ui --maxEvents=400" --extFile 900007_ui/mc_13p6TeV.Sh_216_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.GRID.tar.gz --outDS user.dcamarer.run3_900007_ui_260711 --split 40 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
