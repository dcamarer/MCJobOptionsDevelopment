echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007_ui --maxEvents=200" --extFile 900007_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_2000.GRID.tar.gz --outDS user.dcamarer.run3_900007_ui_260524 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
