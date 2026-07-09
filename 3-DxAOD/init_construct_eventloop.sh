echo ""
date
echo ""

cd ./build/
rm -rf *
asetup 25.2.100,AnalysisBase
cmake ../source/; 
make;
cd ../build/;
source x86_64-*/setup.sh
cd ../run/;

echo ""
date
echo ""
echo "C'est fini!"
echo ""
