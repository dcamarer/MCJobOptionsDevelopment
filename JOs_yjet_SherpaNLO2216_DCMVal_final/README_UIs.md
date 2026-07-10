# Work on the UIs

The first (second) parameter is the number of cores (beam energy).

## Run 2 sequence:

```Console
nohup ./1.createLibs.sh 1 6500.0 >& 1.createLibs.log &
nohup ./2.makelibs.sh 4 6500.0 >& 2.makelibs.log &
cd ecm13TeV; ln -s ../Process Process;
nohup ./3.integrate.sh 3 6500.0 >& 3.integrate.log &
nohup ./4.makeTarball.sh >& 4.makeTarball.log &
nohup ./5.EvntGenTest.sh 1 6500.0 >& 5.EvntGenTest.log &
```

## Run 3 sequence:

```Console
nohup ./1.createLibs.sh 1 6800.0 >& 1.createLibs.log &
nohup ./2.makelibs.sh 4 6800.0 >& 2.makelibs.log &
cd ecm13p6TeV; ln -s ../Process Process;
nohup ./3.integrate.sh 3 6800.0 >& 3.integrate.log &
nohup ./4.makeTarball.sh >& 4.makeTarball.log &
nohup ./5.EvntGenTest.sh 1 6800.0 >& 5.EvntGenTest.log &
```