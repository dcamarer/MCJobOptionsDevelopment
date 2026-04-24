# Practical instructions

## Analyses of interest

- [ATLAS_2017_I1645627 y+j](https://rivet.hepforge.org/analyses/ATLAS_2017_I1645627)
- [ATLAS_2019_I1772071 y+2j](https://rivet.hepforge.org/analyses/ATLAS_2019_I1772071)
- [ATLAS_2023_I2729396 ssWW 139/fb -- not yet official](https://gitlab.cern.ch/atlas-physics/pmg/rivet-routines/-/tree/master/STDM-2018-32_ssWWjj_139ifb)

### Compile a custom analysis (for non-official routines ⚠️)

```Console
rivet-build RivetMY_ANALYSIS.so MY_ANALYSIS.cc
```

For example, for the ssWW Run 2 analysis:

```Console
rivet-build RivetATLAS_2023_I2729396.so ATLAS_2023_I2729396.cc
```

## Input preparation (EVNT -> YODA)

https://gitlab.cern.ch/atlas/athena/-/blob/main/Generators/Rivet_i/README.md?ref_type=heads#running-rivet-over-a-local-evnt-file

Under the different projects I use scripts e.g. `athena local_j100000.py` to make this conversion

## Make plots

```Console
rivet-mkhtml --help
```

For a custom routine (⚠️): Environment variables are needed if you want to plot the data, otherwise pass the config *.plot

```Console
export RIVET_ANALYSIS_PATH=/afs/cern.ch/user/d/dcamarer/MCJobOptionsDevelopment/RIVET/projects/ATLAS_2023_I2729396/Routine
echo $RIVET_ANALYSIS_PATH
export RIVET_DATA_PATH=/afs/cern.ch/user/d/dcamarer/MCJobOptionsDevelopment/RIVET/projects/ATLAS_2023_I2729396/Routine
echo $RIVET_DATA_PATH
```

```Console
rivet-mkhtml --no-errs -o my_plots prediction1.yoda:"Title=MC 1" prediction2.yoda:"Title=MC 2"

rivet-mkhtml -o my_plots run2_snlo222/run2_sh222_stacked.yoda.gz:"Title=SNLO 2.2.2" run2/run2_stacked.yoda.gz:"Title=SNLO 2.2.16 [1-5]"

rivet-mkhtml -c Routine/ATLAS_2023_I2729396.plot -o my_plots_MC run2/run2_100000_WmWm.yoda.gz:"Title=100000 W-W-" run2/run2_100001_WpWp.yoda.gz:"Title=100001 W+W+"
rivet-mkhtml -c Routine/ATLAS_2023_I2729396.plot -o my_plots_MC run2/run2_polarised_stacked.yoda.gz:"Title=Polar W-W- + W+W+" run2/run2_100002_inclusive.yoda.gz:"Title=Inclusive ssWW"
```

## Merge YODA files

```Console
rivet-merge --help
```

When the inputs are independent (diff processes)

```Console
rivet-merge run2_* -o run2_stacked.yoda.gz
```

When the inputs are equivalent, with same random number (i.e. GRID outputs from a single DSID)

```Console
rivet-merge -e run2_* -o run2_stacked.yoda.gz
```

Alternative option (if the previous gives something like "Rivet.AnalysisHandler: WARN  Analysis 'ATLAS_2020_I1772071' not found.")

```Console
yodamerge -o run2_stacked.yoda.gz run2_*
```

## Scale a YODA file (probably not needed ⚠️)

Hopefully not needed due to the new EVNT -> YODA conversion step above.

To scale a YODA file by factor 10:

```Console
yodascale -c '.* 1000x' file_original.yoda
```

## Output further studies (YODA -> ROOT)

https://gitlab.cern.ch/atlas/athena/-/blob/main/Generators/Rivet_i/README.md?ref_type=heads#converting-yoda-files-to-root-format
