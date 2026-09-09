#!/bin/bash

echo ""
date
echo ""

#jetscale="PF"
jetscale="EM"

vv="01_28jun"

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
#mc="sherpa2212_TRUTH1_EnhpTy_pTy10_140"
mc="sherpa2212_TRUTH1_EnhpTy_pTy140_ECMS"
#
#mc="sherpa222_TRUTH1"

echo "Running over: "$mc
echo ""

for run in 01 # SNLO 2211
#for run in 01 02 03 04 05 06 07 # SNLO 222
do
    
    dir1=/home/dcamarero/Doc/photon_validation_SNLO/level3_xAOD/ntuples_MC_TRUTH1/source/MyAnalysis/Root/configFile
    rm -f $dir1
    dir2=/home/dcamarero/Doc/photon_validation_SNLO/level3_xAOD/ntuples_MC_TRUTH1/source/MyAnalysis/share/input_sample_grid.py
    rm -f $dir2
    
    if [ $mc  = "sherpa2211_TRUTH1_PTV2" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950195.Sh_2211_SinglePhoton_EnhPTV2_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi   
    
    if [ $mc  = "sherpa2211_TRUTH1_HTPTV2" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950196.Sh_2211_SinglePhoton_EnhMaxHTPTV2_valid.TRUTH1_v03.root_EXT0'"
	fi	
	
    fi   
    
    if [ $mc  = "sherpa2211_TRUTH1_HTPTV2_normalised" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950398.Sh_2211_SinglePhoton_EnhMaxHTPTV2_20e4_valid.TRUTH1_v02.root_EXT0/'"
	fi	
	
    fi
    
    if [ $mc  = "sherpa2211_TRUTH1_ST2" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950442.Sh_2211_SinglePhoton_ST2_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi 
    
    if [ $mc  = "sherpa2211_TRUTH1_ST2_2pTy2" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950444.Sh_2211_SinglePhoton_ST2_2pTy2_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi   
    
    if [ $mc  = "sherpa2211_TRUTH1_ST2_4pTy2" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950445.Sh_2211_SinglePhoton_ST2_4pTy2_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi   
    
    if [ $mc  = "sherpa2211_TRUTH1_ST2_pTy4" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950443.Sh_2211_SinglePhoton_ST2_pTy4_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi  
    
    if [ $mc  = "sherpa2211_TRUTH1_EnhpTy" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950504.Sh_2211_SinglePhoton_EnhpTy_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi    
    
    if [ $mc  = "sherpa2211_TRUTH1_EnhpTy_pTy17_140" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950505.Sh_2211_SinglePhoton_EnhpTy_pTy17_140_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi    
    
    if [ $mc  = "sherpa2211_TRUTH1_EnhpTy_pTy140_ECMS" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.950506.Sh_2211_SinglePhoton_EnhpTy_pTy140_ECMS_valid.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi

    if [ $mc  = "sherpa2212_TRUTH1_EnhpTy_pTy10_140" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=10
	    sample_dir="sample_name = 'user.dcamarer.700671.Sh_2212_SinglePhoton_EnhpTy_pTy10_140.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi    
    
    if [ $mc  = "sherpa2212_TRUTH1_EnhpTy_pTy140_ECMS" ]
    then
	
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.700672.Sh_2212_SinglePhoton_EnhpTy_pTy140_ECMS.TRUTH1_v01.root_EXT0/'"
	fi	
	
    fi

    if [ $mc  = "sherpa222_TRUTH1" ]
    then       
	
	# slice 17_35
	if [ $run = '01' ]
	then	    
	    ptmccut=17
	    sample_dir="sample_name = 'user.dcamarer.364541.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_17_35.TRUTH1_v05.root_EXT0'"
	fi

	# slice 35_70
	if [ $run = '02' ]
	then	    
	    ptmccut=35
	    sample_dir="sample_name = 'user.dcamarer.364542.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_35_70.TRUTH1_v05.root_EXT0'"
	fi
	
	# slice 70_140
	if [ $run = '03' ]
	then	    
	    ptmccut=70
	    sample_dir="sample_name = 'user.dcamarer.364543.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_70_140.TRUTH1_v05.root_EXT0'"
	fi
	
	# slice 140_280
	if [ $run = '04' ]
	then	    
	    ptmccut=140
	    sample_dir="sample_name = 'user.dcamarer.364544.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_140_280.TRUTH1_v05.root_EXT0'"
	fi
	
	# slice 280_500
	if [ $run = '05' ]
	then	    
	    ptmccut=280
	    sample_dir="sample_name = 'user.dcamarer.364545.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_280_500.TRUTH1_v05.root_EXT0'"
	fi
	
	# slice 500_1000
	if [ $run = '06' ]
	then	    
	    ptmccut=500
	    sample_dir="sample_name = 'user.dcamarer.364546.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_500_1000.TRUTH1_v05.root_EXT0'"
	fi
	
	# slice 1000_CMS
	if [ $run = '07' ]
	then	    
	    ptmccut=1000
	    sample_dir="sample_name = 'user.dcamarer.364547.Sherpa_222_NNPDF30NNLO_SinglePhoton_pty_1000_E_CMS.TRUTH1_v05.root_EXT0'"
	fi
	
    fi
    
    # output filename
    outmcg="outmcg = 'user.dcamarer.${mc}.slice_${ptmccut}.v_${vv}.%in:name[2]%.%in:name[5]%.%in:name[6]%'"

    out=mc_${run}_${mc}_grid.out
    #rm -f $out
    
    echo ""
    echo "static const double ptmccut = $ptmccut;" >> $dir1
    echo "static const string out = \"$out\";" >> $dir1
    echo "static const string m_type = \"$mc\";" >> $dir1
    echo "static const string jetscale = \"$jetscale\";" >> $dir1
    echo "configFile:"
    more $dir1
    echo ""
    echo $sample_dir >> $dir2
    echo $outmcg >> $dir2
    echo "input_sample_grid.py:"
    more $dir2
    echo ""
    
    cd ../build/
    make; 
    cd ../run;
    
    echo ""
    echo "Framework built:"
    echo ""
    echo "Running ..."
    echo ""
    
    rm -rf dir${run}_${mc}_grid output${run}_${mc}_grid.log    
    ATestSubmit_eljob.py --submission-dir=dir${run}_${mc}_grid >& output${run}_${mc}_grid.log
   
    date    
    echo ""
    
done
