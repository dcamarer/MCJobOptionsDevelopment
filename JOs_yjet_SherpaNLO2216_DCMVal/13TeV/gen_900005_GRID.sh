echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900005 --maxEvents=5000" --extFile 900005/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_280_500.GRID.tar.gz --outDS user.dcamarer.run2_900005_260325_v2 --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
