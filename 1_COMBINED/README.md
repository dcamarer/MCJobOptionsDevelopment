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

### Sherpa 2.2.16 NLO photon + jets

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

### Pythia8 multijet

```Console
setupATLAS -c centos7
asetup AthGeneration,23.6.3,here
```

```Console
EVNTMerge_tf.py --inputEVNTFile ../run3_801166_part* --outputEVNT_MRGFile run3_801166.EVNT.root
```

## Compute the sample cross-section by averaging the log.generate parts

### Sherpa 2.2.16 NLO photon + jets

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

### Pythia8 multijet

grep "| Processed " log.generate_part*
grep "cross" log.generate_part*
grep "INFO Filter Efficiency = " log.generate_part*

All subjobs have cross-section (nb) = 7.858e+07

- 801166 : events = 10x10000 + 10x20000 = 300000

log.generate_part01:11:49:37 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026263 [10000 / 380765]
log.generate_part02:13:06:48 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025856 [10000 / 386760]
log.generate_part03:12:32:02 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025717 [10000 / 388852]
log.generate_part04:12:15:06 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025648 [10000 / 389900]
log.generate_part05:12:32:21 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025629 [10000 / 390179]
log.generate_part06:12:21:44 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026065 [10000 / 383661]
log.generate_part07:13:14:29 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026223 [10000 / 381338]
log.generate_part08:11:35:22 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025816 [10000 / 387351]
log.generate_part09:11:48:33 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026304 [10000 / 380177]
log.generate_part10:11:58:07 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025674 [10000 / 389497]
log.generate_part11:16:57:34 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026084 [20000 / 766749]
log.generate_part12:17:17:01 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026112 [20000 / 765926]
log.generate_part13:17:17:27 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026098 [20000 / 766332]
log.generate_part14:17:05:37 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026109 [20000 / 766017]
log.generate_part15:15:30:59 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025988 [20000 / 769579]
log.generate_part16:17:45:33 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026254 [20000 / 761780]
log.generate_part17:16:57:47 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026130 [20000 / 765393]
log.generate_part18:16:33:21 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026185 [20000 / 763807]
log.generate_part19:16:49:26 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.025982 [20000 / 769766]
log.generate_part20:15:03:45 Py:EvgenFilterSeq    INFO Filter Efficiency = 0.026237 [20000 / 762282]

It should be 

300000 / (380765 + 386760 + 388852 + 389900 + 390179 + 383661 + 381338 + 387351 + 380177 + 389497 + 766749 + 765926 + 766332 + 766017 + 769579 + 761780 + 765393 + 763807 + 769766 + 762282) = 0.02605046095856491831

So 2.605046e-02