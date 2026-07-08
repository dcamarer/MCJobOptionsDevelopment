#!/bin/bash

echo ""
date
echo ""

#  eq -> equal to
# -ne -> not equal to
# -lt -> less than
# -le -> less than or equal to
# -gt -> greater than
# -ge -> greater than or equal

# Working mode
wmode=1 # SHERPA 2.2.16 Run 2 samples
#wmode=2 # SHERPA 2.2.16 Run 3 samples
#wmode=3 # SHERPA 2.2.2 

if [ $wmode -eq "1" ]; then
    
	OUTNAME=Sh_2211_SinglePhoton_EnhPTV2_valid

	for ((k=950195;k<=950195;k++))    
	do
		echo "OUTPUTNAME = ${OUTNAME}"
		
		if [ $k -eq "950195" ]; then
			#ptstring=8_17
			tags=e8312
		fi
		
		FILE_IN=/userdata3/dcamarero/samples/sherpanlo_valid950195/mc15_valid.950195.Sh_2211_SinglePhoton_EnhPTV2_valid.evgen.EVNT.e8312/EVNT.24216481._000001.pool.root.1
		FILE_OUT=user.dcamarer.${k}.${OUTNAME}.TRUTH1_v01.root

		echo "INDS       = ${FILE_IN}"
		echo "OUTDS      = ${FILE_OUT}"
		echo ""
				
		Reco_tf.py --inputEVNTFile ${FILE_IN} --outputDAODFile ${FILE_OUT} --reductionConf TRUTH1

		echo ""
	done
    
elif [ $wmode -eq "2" ]; then
    
	OUTNAME=Sh_2211_SinglePhoton_EnhMaxHTPTV2_valid

	for ((k=950196;k<=950196;k++))    
	do

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
		
		#FILE_IN=mc20_13TeV.${k}.${OUTNAME}_pty_${ptstring}.recon.AOD.${tags}
		FILE_OUT=user.dcamarer.${k}.${OUTNAME}_pty_${ptstring}.TRUTH1_v01.root		

		echo "INDS       = ${FILE_IN}"
		echo "OUTDS      = ${FILE_OUT}"
		echo ""
		
		Reco_tf.py --inputAODFile ${FILE_IN} --outputDAODFile ${FILE_OUT} --reductionConf TRUTH1
		
		echo ""

	done
    
fi

date

echo ""
echo "C'est fini!"
echo ""
