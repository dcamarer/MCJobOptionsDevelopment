#!/bin/bash

echo ""
date
echo ""

#jetscale="PF"
jetscale="EM"

#mc="sherpa2211_TRUTH1_PTV2"
#mc="sherpa2211_TRUTH1_HTPTV2"
#mc="sherpa2211_TRUTH1_HTPTV2_normalised"
#mc="sherpa2211_TRUTH1_ST2"
#mc="sherpa2211_TRUTH1_ST2_2pTy2" 
#mc="sherpa2211_TRUTH1_ST2_4pTy2" 
#mc="sherpa2211_TRUTH1_ST2_pTy4"
#mc="sherpa2211_TRUTH1_EnhpTy"
#mc="sherpa2211_TRUTH1_EnhpTy_pTy17_140"
#mc="sherpa2211_TRUTH1_EnhpTy_pTy140_ECMS"
mc="sherpa2212_TRUTH1_EnhpTy_pTy10_140"
#mc="sherpa2212_TRUTH1_EnhpTy_pTy140_ECMS"
#
#mc="sherpa222_TRUTH1"

echo "Running over: "$mc
echo ""

for run in 01
do

    dir1=/home/dcamarero/Doc/photon_validation_SNLO/level3_xAOD/ntuples_MC_TRUTH1/source/MyAnalysis/Root/configFile
    rm -f $dir1
    dir2=/home/dcamarero/Doc/photon_validation_SNLO/level3_xAOD/ntuples_MC_TRUTH1/source/MyAnalysis/share/input_sample_local.py
    rm -f $dir2

    if [ $mc = "sherpa2211_TRUTH1_PTV2" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/home/dcamarero/Doc/photon_validation_SNLO/level2_TRUTH1/run_local/'"
	derivation_dir="inputFileName = 'DAOD_TRUTH1.user.dcamarer.950195.Sh_2211_SinglePhoton_EnhPTV2_valid.TRUTH1_v01.root'"

    fi

    # NOT PREPARED
    if [ $mc = "sherpa2211_TRUTH1_HTPTV2" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/'"
	derivation_dir="inputFileName = ''"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_HTPTV2_normalised" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/HTPTV2_normalised/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27025423.EXT0._000211.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_ST2" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/ST2/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27294522.EXT0._000037.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_ST2_2pTy2" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/ST2_2pTy2/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27294562.EXT0._000050.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_ST2_4pTy2" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/ST2_4pTy2/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27294569.EXT0._000024.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_ST2_pTy4" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/ST2_pTy4/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27294556.EXT0._000058.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_EnhpTy" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/EnhpTy/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27903827.EXT0._000012.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_EnhpTy_pTy17_140" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/EnhpTy_pTy17_140/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27903911.EXT0._000021.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2211_TRUTH1_EnhpTy_pTy140_ECMS" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2211/EnhpTy_pTy140_ECMS/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.27903935.EXT0._000022.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2212_TRUTH1_EnhpTy_pTy10_140" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2212/EnhpTy_pTy10_140/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.29464640.EXT0._000001.DAOD_TRUTH1.pool.root'"

    fi
    
    if [ $mc = "sherpa2212_TRUTH1_EnhpTy_pTy140_ECMS" ]
    then
	
	ptmccut=17

	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid2212/EnhpTy_pTy140_ECMS/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.29464652.EXT0._000010.DAOD_TRUTH1.pool.root'"

    fi

    if [ $mc = "sherpa222_TRUTH1" ]
    then

	ptmccut=17
	
	# TESTING 17_35
	sample_dir="inputFilePath = '/userdata3/dcamarero/samples/SAMPLES_VALIDATION/sherpanlo_valid222/user.dcamarer/'"
	derivation_dir="inputFileName = 'user.dcamarer.24527834.EXT0._000709.DAOD_TRUTH1.pool.root'"

    fi
    
    out=mc_${run}_${mc}.out
    #rm -f $out
    
    echo "static const double ptmccut = $ptmccut;" >> $dir1
    echo "static const string out = \"$out\";" >> $dir1
    echo "static const string m_type = \"$mc\";" >> $dir1
    echo "static const string jetscale = \"$jetscale\";" >> $dir1
    echo "configFile:"
    more $dir1
    echo ""
    echo $sample_dir >> $dir2
    echo "input_sample_local.py:"
    echo $derivation_dir >> $dir2
    echo "input_derivation_local.py:"
    more $dir2
    echo ""

    cd ../build/
    make; 
    cd ../run;
    
    echo ""
    echo "Framework rebuilt:"
    echo ""
    echo "Running ... "
    echo ""
    
    rm -rf dir${run}_${mc} output${run}_${mc}.log
    ATestRun_eljob.py --submission-dir=dir${run}_${mc} >& output${run}_${mc}.log
    
    ls dir${run}_${mc}/* | grep hist | grep .root > storfile
    pp=$(cat storfile)
    mv $pp pos/dat_${run}_${mc}.root
    rm -rf ! storfile 

    ls dir${run}_${mc}/data-ANALYSIS/* | grep .root > storfile_ntp
    nn=$(cat storfile_ntp)
    mv $nn posNTP/NTP_${mc}.photonVBF_${run}.root
    rm -rf ! storfile_ntp

    rm -rf ! configFile
    
    date
    echo ""
    echo "C'est fini!"
    echo ""
    
done
