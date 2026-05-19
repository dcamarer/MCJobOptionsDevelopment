echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007 --maxEvents=2000" --extFile 900007/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_2000.GRID.tar.gz --outDS user.dcamarer.run2_900007_260325_v2 --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
