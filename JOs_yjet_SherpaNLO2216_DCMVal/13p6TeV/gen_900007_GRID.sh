echo ""
date
echo ""

# Production of 400 * 20 = 8000 events
# Part 1 - 7777
# Part 2 - 6666
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:6666 --outputEVNTFile %OUT.EVNT.root --jobConfig=900007_ui --maxEvents=400" --extFile 900007_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.GRID.tar.gz --outDS user.dcamarer.run3_900007_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
