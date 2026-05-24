echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900004_ui --maxEvents=2000" --extFile 900004_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_140_280.GRID.tar.gz --outDS user.dcamarer.run2_900004_260524 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
