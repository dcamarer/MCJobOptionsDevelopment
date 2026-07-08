#!/bin/bash

# Note: this script needs to be run in the same folder where the inputs are located. The script will create the output files in the same folder.
# - ATLAS Instructions here: https://atlas-software.docs.cern.ch/analysis/analysis_tutorial/AnalysisSWTutorial/mc_truth_derivation/

echo ""
date
echo ""

# Working mode from input argument
wmode=${1}

if [[ -z "${wmode}" ]]; then
	echo "ERROR: missing working mode"
	echo "Usage: $0 <wmode>"
	echo "  1 = SHERPA 2.2.16 Run 2 samples"
	echo "  2 = SHERPA 2.2.16 Run 3 samples"
	echo "  3 = SHERPA 2.2.2"
	exit 1
fi

if [[ "${wmode}" != "1" && "${wmode}" != "2" && "${wmode}" != "3" ]]; then
	echo "ERROR: invalid working mode '${wmode}'"
	echo "Allowed values: 1, 2, 3"
	exit 1
fi

echo "Running with wmode = ${wmode}"
echo ""

if [ $wmode -eq "1" ]; then
    
	OUTNAME=Sh_2216_SinglePhoton_valid

	for ((k=900001;k<=900007;k++))
	do
		echo "OUTPUTNAME = ${OUTNAME}"
		
		if [ $k -eq "900001" ]; then
				ptstring=17_35
		elif [ $k -eq "900002" ]; then
				ptstring=35_70
		elif [ $k -eq "900003" ]; then
				ptstring=70_140
		elif [ $k -eq "900004" ]; then
				ptstring=140_280
		elif [ $k -eq "900005" ]; then
				ptstring=280_500
		elif [ $k -eq "900006" ]; then
				ptstring=500_1000
		elif [ $k -eq "900007" ]; then
				ptstring=1000_E_CMS			
		fi

		FILE_IN=run2_Sh2216_${k}.EVNT.root
		FILE_OUT=run2.${k}.${OUTNAME}_pty_${ptstring}.TRUTH1_v01.root		

		echo "FILE IN      = ${FILE_IN}"
		echo "FILE OUT     = ${FILE_OUT}"
		echo ""
		
		Derivation_tf.py --inputAODFile ${FILE_IN} --outputDAODFile ${FILE_OUT} --formats TRUTH1
		
		echo ""

	done
    
elif [ $wmode -eq "2" ]; then
    
	OUTNAME=Sh_2216_SinglePhoton_valid

	for ((k=900001;k<=900007;k++))
	do
		echo "OUTPUTNAME = ${OUTNAME}"
		
		if [ $k -eq "900001" ]; then
				ptstring=17_35
		elif [ $k -eq "900002" ]; then
				ptstring=35_70
		elif [ $k -eq "900003" ]; then
				ptstring=70_140
		elif [ $k -eq "900004" ]; then
				ptstring=140_280
		elif [ $k -eq "900005" ]; then
				ptstring=280_500
		elif [ $k -eq "900006" ]; then
				ptstring=500_1000
		elif [ $k -eq "900007" ]; then
				ptstring=1000_E_CMS			
		fi
	
		FILE_IN=run3_Sh2216_${k}.EVNT.root
		FILE_OUT=run3.${k}.${OUTNAME}_pty_${ptstring}.TRUTH1_v01.root

		echo "FILE IN      = ${FILE_IN}"
		echo "FILE OUT     = ${FILE_OUT}"
		echo ""
		
		Derivation_tf.py --inputAODFile ${FILE_IN} --outputDAODFile ${FILE_OUT} --formats TRUTH1
		
		echo ""

	done
    
elif [ $wmode -eq "3" ]; then
    
	OUTNAME=Sherpa_222_NNPDF30NNLO_SinglePhoton

	for ((k=364544;k<=364547;k++))
	do
		echo "OUTPUTNAME = ${OUTNAME}"
		
		if [ $k -eq "364541" ]; then
				ptstring=17_35
				tags=e6788_s3126_r10724
		elif [ $k -eq "364542" ]; then
				ptstring=35_70
				tags=e6788_s3126_r10724
		elif [ $k -eq "364543" ]; then
				ptstring=70_140
				tags=e5938_s3126_r10724
		elif [ $k -eq "364544" ]; then
				ptstring=140_280
				tags=e5938_s3126_r10724
		elif [ $k -eq "364545" ]; then
				ptstring=280_500
				tags=e5938_s3126_r10724
		elif [ $k -eq "364546" ]; then
				ptstring=500_1000
				tags=e5938_s3126_r10724
		elif [ $k -eq "364547" ]; then
				ptstring=1000_E_CMS
				tags=e6068_s3126_r10724
		fi
		
		FILE_IN=mc20_13TeV.${k}.${OUTNAME}_pty_${ptstring}.recon.AOD.${tags}
		FILE_OUT=user.dcamarer.${k}.${OUTNAME}_pty_${ptstring}.TRUTH1_v01.root		

		echo "INDS       = ${FILE_IN}"
		echo "OUTDS      = ${FILE_OUT}"
		echo ""
		
		Derivation_tf.py --inputAODFile ${FILE_IN} --outputDAODFile ${FILE_OUT} --formats TRUTH1
		
		echo ""

	done
    
fi

date

echo ""
echo "C'est fini!"
echo ""
