#!/bin/bash

echo ""
date
echo ""

mc="run2_sherpa2216_TRUTH1"
#mc="run3_sherpa2216_TRUTH1"

echo "Running over: "$mc
echo ""

for run in 01
#for run in 01 02 03 04 05 06 07 # SNLO 2216
do

    dir1=/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/3-DxAOD/source/MyAnalysis/Root/configFile
    rm -f $dir1
    dir2=/home/dcamarero/PostDoc/PMG/MCJobOptionsDevelopment/3-DxAOD/source/MyAnalysis/share/input_sample_local.py
    rm -f $dir2

    if [ $mc = "run2_sherpa2216_TRUTH1" ]
    then
	
        sample_dir="inputFilePath = '/userdata/dcamarero/validation_results/photonjet_validation_Sherpa2216/TRUTH1/13TeV/'"

        # slice 17_35
        if [ $run = '01' ]
        then	    
            ptmccut=17            
            derivation_dir="inputFileName = 'run2.900001.Sh_2216_SinglePhoton_valid_pty_17_35.TRUTH1_v01.root'"
        fi

        # slice 35_70
        if [ $run = '02' ]
        then	    
            ptmccut=35
            derivation_dir="inputFileName = 'run2.900002.Sh_2216_SinglePhoton_valid_pty_35_70.TRUTH1_v01.root'"
        fi
        
        # slice 70_140
        if [ $run = '03' ]
        then	    
            ptmccut=70
            derivation_dir="inputFileName = 'run2.900003.Sh_2216_SinglePhoton_valid_pty_70_140.TRUTH1_v01.root'"
        fi
        
        # slice 140_280
        if [ $run = '04' ]
        then	    
            ptmccut=140
            derivation_dir="inputFileName = 'run2.900004.Sh_2216_SinglePhoton_valid_pty_140_280.TRUTH1_v01.root'"
        fi
        
        # slice 280_500
        if [ $run = '05' ]
        then	    
            ptmccut=280
            derivation_dir="inputFileName = 'run2.900005.Sh_2216_SinglePhoton_valid_pty_280_500.TRUTH1_v01.root'"
        fi
        
        # slice 500_1000
        if [ $run = '06' ]
        then	    
            ptmccut=500
            derivation_dir="inputFileName = 'run2.900006.Sh_2216_SinglePhoton_valid_pty_500_1000.TRUTH1_v01.root'"
        fi
        
        # slice 1000_CMS
        if [ $run = '07' ]
        then	    
            ptmccut=1000
            derivation_dir="inputFileName = 'run2.900007.Sh_2216_SinglePhoton_valid_pty_1000_E_CMS.TRUTH1_v01.root'"
        fi

    fi

    if [ $mc = "run3_sherpa2216_TRUTH1" ]
    then
	
        sample_dir="inputFilePath = '/userdata/dcamarero/validation_results/photonjet_validation_Sherpa2216/TRUTH1/13p6TeV/'"

        # slice 17_35
        if [ $run = '01' ]
        then	    
            ptmccut=17            
            derivation_dir="inputFileName = 'run3.900001.Sh_2216_SinglePhoton_valid_pty_17_35.TRUTH1_v01.root'"
        fi

        # slice 35_70
        if [ $run = '02' ]
        then	    
            ptmccut=35
            derivation_dir="inputFileName = 'run3.900002.Sh_2216_SinglePhoton_valid_pty_35_70.TRUTH1_v01.root'"
        fi
        
        # slice 70_140
        if [ $run = '03' ]
        then	    
            ptmccut=70
            derivation_dir="inputFileName = 'run3.900003.Sh_2216_SinglePhoton_valid_pty_70_140.TRUTH1_v01.root'"
        fi
        
        # slice 140_280
        if [ $run = '04' ]
        then	    
            ptmccut=140
            derivation_dir="inputFileName = 'run3.900004.Sh_2216_SinglePhoton_valid_pty_140_280.TRUTH1_v01.root'"
        fi
        
        # slice 280_500
        if [ $run = '05' ]
        then	    
            ptmccut=280
            derivation_dir="inputFileName = 'run3.900005.Sh_2216_SinglePhoton_valid_pty_280_500.TRUTH1_v01.root'"
        fi
        
        # slice 500_1000
        if [ $run = '06' ]
        then	    
            ptmccut=500
            derivation_dir="inputFileName = 'run3.900006.Sh_2216_SinglePhoton_valid_pty_500_1000.TRUTH1_v01.root'"
        fi
        
        # slice 1000_CMS
        if [ $run = '07' ]
        then	    
            ptmccut=1000
            derivation_dir="inputFileName = 'run3.900007.Sh_2216_SinglePhoton_valid_pty_1000_E_CMS.TRUTH1_v01.root'"
        fi

    fi

    out=mc_${run}_${mc}.out
    #rm -f $out
    
    echo "static const double ptmccut = $ptmccut;" >> $dir1
    echo "static const string out = \"$out\";" >> $dir1
    echo "static const string m_type = \"$mc\";" >> $dir1
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
    mv $nn posNTP/NTP_${mc}.mcvalidation_${run}.root
    rm -rf ! storfile_ntp

    rm -rf ! configFile
    
    date
    echo ""
    echo "C'est fini!"
    echo ""
    
done
