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

## Make plots

```Console
rivet-mkhtml --help
```

## HTML

```Console
rivet-mkhtml --no-weights --errs -c ATLAS_2020_I1772071.plot -o my_plots_MC prediction1-scaled.yoda.gz:"Title=MC 1" prediction2-scaled.yoda.gz:"Title=MC 2"
```

## Output further studies (YODA -> ROOT)

https://gitlab.cern.ch/atlas/athena/-/blob/main/Generators/Rivet_i/README.md?ref_type=heads#converting-yoda-files-to-root-format
