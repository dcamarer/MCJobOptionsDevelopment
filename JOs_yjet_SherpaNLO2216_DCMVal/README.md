# Work on the UIs

The first (second) parameter is the number of cores (beam energy).

## Run 2 sequence:

```Console
nohup ./1.createLibs.sh 1 6500.0 >& 1.createLibs.nohup.log &
nohup ./2.makelibs.sh 4 6500.0 >& 2.makelibs.nohup.log &
cd ecm13TeV; ln -s ../Process Process;
nohup ./3.integrate.sh 48 6500.0 >& 3.integrate.nohup.log &
nohup ./4.makeTarball.sh >& 4.makeTarball.nohup.log &
nohup ./5.EvntGenTest.sh 1 6500.0 >& 5.EvntGenTest.nohup.log &
```

## Run 3 sequence:

```Console
nohup ./1.createLibs.sh 1 6800.0 >& 1.createLibs.nohup.log &
nohup ./2.makelibs.sh 4 6800.0 >& 2.makelibs.nohup.log &
cd ecm13p6TeV; ln -s ../Process Process;
nohup ./3.integrate.sh 48 6800.0 >& 3.integrate.nohup.log &
nohup ./4.makeTarball.sh >& 4.makeTarball.nohup.log &
nohup ./5.EvntGenTest.sh 1 6800.0 >& 5.EvntGenTest.nohup.log &
```