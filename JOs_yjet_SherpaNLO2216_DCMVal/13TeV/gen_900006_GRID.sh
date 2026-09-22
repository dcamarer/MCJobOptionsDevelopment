echo ""
date
echo ""

# Production of 1000 * 20 = 20000 events
# Part 1 - 9999
# Part 2 - 8888
pathena --trf "Gen_tf.py --ecmEnergy=13000 --randomSeed %RNDM:9999 --outputEVNTFile %OUT.EVNT.root --jobConfig=900006_ui --maxEvents=1000" --extFile 900006_ui/mc_13TeV.Sh_2216_NNPDF30NNLO_SinglePhoton_pty_500_1000.GRID.tar.gz --outDS user.dcamarer.run2_900006_ui_260617 --split 20 --maxCpuCount 259200

echo ""
date
echo ""
echo "C'est fini!"
echo ""
