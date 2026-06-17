echo ""
date
echo ""

# Production of 1250 * 20 = 25000 events
# Part 1 - 7777
# Part 2 - 6666
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:6666 --outputEVNTFile %OUT.EVNT.root --jobConfig=900005_ui --maxEvents=1250" --extFile 900005_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_280_500.GRID.tar.gz --outDS user.dcamarer.run2_900005_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
