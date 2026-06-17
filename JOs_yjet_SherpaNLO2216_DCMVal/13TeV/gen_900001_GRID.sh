echo ""
date
echo ""

# Production of 7500 * 20 = 150000 events
# Part 1 - 7777
# Part 2 - 6666
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:6666 --outputEVNTFile %OUT.EVNT.root --jobConfig=900001_ui --maxEvents=7500" --extFile 900001_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_17_35.GRID.tar.gz --outDS user.dcamarer.run2_900001_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
