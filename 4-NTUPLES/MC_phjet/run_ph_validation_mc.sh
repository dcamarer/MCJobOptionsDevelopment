#!/bin/bash

echo ""
date
echo ""

# Defining some variables:
program=$1
j=$2
mc=$3
ptmccut=$4
rad=$5
rew=$6
sfac=$7
swgt=$8

out=out/ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}_${j}.out
pos=pos/ph_validation_${mc}_pt${ptmccut}_r${rad}_wS${swgt}_wR${rew}_wSF${sfac}_${j}.root
echo $j >> fort.50
echo $out >> fort.50
echo $pos >> fort.50
echo $mc >> fort.50
echo $ptmccut >> fort.50
echo $rad >> fort.50
echo $rew >> fort.50
echo $sfac >> fort.50
echo $swgt >> fort.50

g++ -c $program.cc  `root-config --cflags --glibs`

g++ -o $program.exe $program.o `root-config --cflags --glibs`

./$program.exe

rm -f $program.exe $program.o fort.50

echo ""
date
echo ""
