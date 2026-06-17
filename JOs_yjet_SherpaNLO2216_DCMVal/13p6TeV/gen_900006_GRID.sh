echo ""
date
echo ""

# Production of 1000 * 20 = 20000 events
# Part 1 - 7777
# Part 2 - 6666
pathena --trf "Gen_tf.py --ecmEnergy=13600 --randomSeed %RNDM:6666 --outputEVNTFile %OUT.EVNT.root --jobConfig=900006_ui --maxEvents=1000" --extFile 900006_ui/mc_13p6TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_500_1000.GRID.tar.gz --outDS user.dcamarer.run3_900006_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
