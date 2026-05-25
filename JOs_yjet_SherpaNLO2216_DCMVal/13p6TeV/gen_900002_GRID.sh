echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900002_ui --maxEvents=5000" --extFile 900002_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_35_70.GRID.tar.gz --outDS user.dcamarer.run3_900002_ui_260524 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
