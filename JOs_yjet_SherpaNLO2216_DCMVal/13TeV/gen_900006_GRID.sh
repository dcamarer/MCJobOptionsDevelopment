echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:7777 --outputEVNTFile %OUT.EVNT.root --jobConfig=900006_ui --maxEvents=1000" --extFile 900006_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_500_1000.GRID.tar.gz --outDS user.dcamarer.run2_900006_260524 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
