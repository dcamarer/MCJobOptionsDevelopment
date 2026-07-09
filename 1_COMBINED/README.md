# To merge a set of EVNT files from a local or Grid generation:

## Standard setup for e.g. release used for Sherpa 2.2.16

```Console
setupATLAS
asetup AthGeneration,23.6.49,here
```

## Combine all input files (e.g. for run2_900007)

```Console
mkdir COMBO_EVNT; cd COMBO_EVNT;
```

For the Run 2 samples:

```Console
EVNTMerge_tf.py --inputEVNTFile ../run2_900001_part* --outputEVNT_MRGFile run2_Sh2216_900001.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900002_part* --outputEVNT_MRGFile run2_Sh2216_900002.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900003_part* --outputEVNT_MRGFile run2_Sh2216_900003.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900004_part* --outputEVNT_MRGFile run2_Sh2216_900004.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900005_part* --outputEVNT_MRGFile run2_Sh2216_900005.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900006_part* --outputEVNT_MRGFile run2_Sh2216_900006.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run2_900007_part* --outputEVNT_MRGFile run2_Sh2216_900007.EVNT.root
```

For the Run 3 samples:

```Console
EVNTMerge_tf.py --inputEVNTFile ../run3_900001_part* --outputEVNT_MRGFile run3_Sh2216_900001.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900002_part* --outputEVNT_MRGFile run3_Sh2216_900002.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900003_part* --outputEVNT_MRGFile run3_Sh2216_900003.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900004_part* --outputEVNT_MRGFile run3_Sh2216_900004.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900005_part* --outputEVNT_MRGFile run3_Sh2216_900005.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900006_part* --outputEVNT_MRGFile run3_Sh2216_900006.EVNT.root
EVNTMerge_tf.py --inputEVNTFile ../run3_900007_part* --outputEVNT_MRGFile run3_Sh2216_900007.EVNT.root
```

## Compute the sample cross-section by averaging the log.generate parts

For the Run 2 samples:

```Console
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900001_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900002_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900003_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900004_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900005_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900006_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900007_merging/",40)'
```

Results:

- **900001 :** events = 300000, xsec (nb) = 296.1161446776
- **900002 :** events = 230000, xsec (nb) = 33.5378645278883
- **900003 :** events = 300000, xsec (nb) = 3.575765450338
- **900004 :** events = 150000, xsec (nb) = 0.29805978056574
- **900005 :** events = 35000, xsec (nb) = 0.0173283436938171
- **900006 :** events = 30000, xsec (nb) = 0.00111853366340933
- **900007 :** events = 12000, xsec (nb) = 2.08355533615433e-05

Total statistics: 300000*2 + 230000 + 150000 + 35000 + 30000 + 12000 = 1 057 000 events

For the Run 3 samples:

```Console
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900001_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900002_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900003_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900004_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900005_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900006_merging/",40)'
root -l -q 'averagexsec.C("/eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13p6TeV/PROD_sherpaTarCreator/900007_merging/",40)'
```

Results:

- **900001 :** events = 300000, xsec (nb) = 310.32386595705
- **900002 :** events = 230000, xsec (nb) = 35.423878046302
- **900003 :** events = 300000, xsec (nb) = 3.79918676603325
- **900004 :** events = 150000, xsec (nb) = 0.32366425630798
- **900005 :** events = 35000, xsec (nb) = 0.0185982042850464
- **900006 :** events = 30000, xsec (nb) = 0.001278100925494
- **900007 :** events = 12000, xsec (nb) = 2.7071366785235e-05

Total statistics: 300000*2 + 230000 + 150000 + 35000 + 30000 + 12000 = 1 057 000 events