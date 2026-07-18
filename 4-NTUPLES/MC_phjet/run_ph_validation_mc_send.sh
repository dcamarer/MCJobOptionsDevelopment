#!/bin/bash

echo ""
date
echo ""

# Choose radius
rad="2"

######################

# Slice weight flag (my own)
swgt="yes"
#swgt="no"

# Reweighting flag
#rew="yes"
rew="no"

# Scale factors flag
#sfac="yes"
sfac="no"

######################

# Choose mc campaign

# SNLO
#mc="run2_sherpa2216"
#mc="run3_sherpa2216"
mc="sherpa222"

echo "Running over mc" $mc
echo ""

# name of source code
program=ph_validation_mc

if [ $mc = "run2_sherpa2216" ]
then
    
    for ptmccut in 17 35 70 140 280 500 1000
    do
        
        slcnum="00"
        if [ "$ptmccut" -eq 17 ]; then
            slcnum="01"
        elif [ "$ptmccut" -eq 35 ]; then
            slcnum="02"
        elif [ "$ptmccut" -eq 70 ]; then
            slcnum="03"
        elif [ "$ptmccut" -eq 140 ]; then
            slcnum="04"
        elif [ "$ptmccut" -eq 280 ]; then
            slcnum="05"
        elif [ "$ptmccut" -eq 500 ]; then
            slcnum="06"
        elif [ "$ptmccut" -eq 1000 ]; then
            slcnum="07"
        fi

        #Erase
        rm -f run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        #Creates it empty
        touch run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        
        ls /home/dcamarero/MCJobOptionsDevelopment/3-DxAOD/run/posNTP/NTP_run2_sherpa2216_TRUTH1.mcvalidation_${slcnum}.root > nrootfiles.txt
        
        # removing existing file
        rm -f files.txt
        # creating it empty
        touch files.txt

        for i in `cat nrootfiles.txt`
        do
            echo "fChain->Add(\"${i}\");" >> files.txt
        done
        
        for j in 01
        do
            ./run_ph_validation_mc.sh $program $j $mc $ptmccut $rad $rew $sfac $swgt >& run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
            rm -f files.txt nrootfiles.txt
        done
        
        echo "Processed"
        echo $ptmccut
        echo ""

    done

fi

if [ $mc = "run3_sherpa2216" ]
then
    
    for ptmccut in 17 35 70 140 280 500 1000
    do
        
        slcnum="00"
        if [ "$ptmccut" -eq 17 ]; then
            slcnum="01"
        elif [ "$ptmccut" -eq 35 ]; then
            slcnum="02"
        elif [ "$ptmccut" -eq 70 ]; then
            slcnum="03"
        elif [ "$ptmccut" -eq 140 ]; then
            slcnum="04"
        elif [ "$ptmccut" -eq 280 ]; then
            slcnum="05"
        elif [ "$ptmccut" -eq 500 ]; then
            slcnum="06"
        elif [ "$ptmccut" -eq 1000 ]; then
            slcnum="07"
        fi

        #Erase
        rm -f run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        #Creates it empty
        touch run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        
        ls /home/dcamarero/MCJobOptionsDevelopment/3-DxAOD/run/posNTP/NTP_run3_sherpa2216_TRUTH1.mcvalidation_${slcnum}.root > nrootfiles.txt
        
        # removing existing file
        rm -f files.txt
        # creating it empty
        touch files.txt

        for i in `cat nrootfiles.txt`
        do
            echo "fChain->Add(\"${i}\");" >> files.txt
        done
        
        for j in 01
        do
            ./run_ph_validation_mc.sh $program $j $mc $ptmccut $rad $rew $sfac $swgt >& run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
            rm -f files.txt nrootfiles.txt
        done
        
        echo "Processed"
        echo $ptmccut
        echo ""

    done

fi

if [ $mc = "sherpa222" ]
then
    
    for ptmccut in 17 35 70 140 280 500 1000
    do

        #ptmccut=17

        #Erase
        rm -f run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        #Creates it empty
        touch run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
        
        ls /userdata/dcamarero/ntuples/photon_validation_SNLO/snlo_222/user.dcamarer.sherpa222_TRUTH1.slice_${ptmccut}.v_01_16mar.dcamarer.TRUTH1_v05.root_EXT0_ANALYSIS/*.root > nrootfiles.txt
        # removing existing file
        rm -f files.txt
        # creating it empty
        touch files.txt

        for i in `cat nrootfiles.txt`
        do
            echo "fChain->Add(\"${i}\");" >> files.txt
        done
        
        for j in 01
        do
            ./run_ph_validation_mc.sh $program $j $mc $ptmccut $rad $rew $sfac $swgt >& run_ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}.log
            rm -f files.txt nrootfiles.txt
        done
        
        echo "Processed"
        echo $ptmccut
        echo ""

    done
    
fi

date
echo ""
echo "C'est fini!"
echo ""
