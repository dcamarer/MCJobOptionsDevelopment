echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007 --maxEvents=2000" --extFile 900007/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_2000.GRID.tar.gz --outDS user.dcamarer.run3_900007_260503 --split 10 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
