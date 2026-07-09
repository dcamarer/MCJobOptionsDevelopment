echo ""
date
echo ""

cd ../build
asetup --restore
source x86_64-*/setup.sh
cmake --build ../build/
cd ../run/;

echo ""
date
echo ""
echo "C'est fini!"
echo ""
