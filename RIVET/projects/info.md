# Practical instructions

## Analyses of interest

- [ATLAS_2017_I1645627 y+j](https://rivet.hepforge.org/analyses/ATLAS_2017_I1645627)
- [ATLAS_2019_I1772071 y+2j](https://rivet.hepforge.org/analyses/ATLAS_2019_I1772071)
- [ATLAS_2023_I2729396 ssWW 139/fb -- not yet official](https://gitlab.cern.ch/atlas-physics/pmg/rivet-routines/-/tree/master/STDM-2018-32_ssWWjj_139ifb)

### Compile a custom analysis (for not official routines)

```Console
rivet-build Rivet_MY_ANALYSIS.so MY_ANALYSIS.cc
```

## Input preparation (EVNT -> YODA)

https://gitlab.cern.ch/atlas/athena/-/blob/main/Generators/Rivet_i/README.md?ref_type=heads#running-rivet-over-a-local-evnt-file

Under the different projects I use scripts e.g. `athena local_j100000.py` to make this conversion

## Make plots

```Console
rivet-mkhtml --help
```

```Console
rivet-mkhtml --no-weights --errs -c ATLAS_2023_I2729396.plot -o my_plots_MC prediction1-scaled.yoda.gz:"Title=MC 1" prediction2-scaled.yoda.gz:"Title=MC 2"
```

## Merge YODA files (probably not needed)

```Console
rivet-merge -e -o my_merged_output.yoda.gz MY_GRID_OUTPUT/*
rivet-merge -o my_stacked_outpyt.yoda.gz process1.yoda.gz:12.34 process2.yoda.gz:4.56
```

Alternative option (if the previous gives something like "Rivet.AnalysisHandler: WARN  Analysis 'ATLAS_2020_I1772071' not found.")

```Console
yodamerge -o my_merged_output.yoda.gz MY_GRID_OUTPUT/*
```

## Scale a YODA file (probably not needed)

Hopefully not needed due to the new EVNT -> YODA conversion step above.

To scale a YODA file by factor 10:

```Console
yodascale -c '.* 10x' file_original.yoda
```

## Output further studies (YODA -> ROOT)

https://gitlab.cern.ch/atlas/athena/-/blob/main/Generators/Rivet_i/README.md?ref_type=heads#converting-yoda-files-to-root-format
