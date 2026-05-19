echo ""
date
echo ""

pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:8888 --outputEVNTFile %OUT.EVNT.root --jobConfig=900003 --maxEvents=6250" --extFile 900003/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_70_140.GRID.tar.gz --outDS user.dcamarer.run3_900003_260517 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
