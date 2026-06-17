echo ""
date
echo ""

# Production of 4500 * 20 = 90000 events
# Part 1 - 7777
# Part 2 - 6666
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:6666 --outputEVNTFile %OUT.EVNT.root --jobConfig=900004_ui --maxEvents=4500" --extFile 900004_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_140_280.GRID.tar.gz --outDS user.dcamarer.run2_900004_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
