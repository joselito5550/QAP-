#!/bin/bash

cat << _end_ | gnuplot
set terminal pngcairo size 600,500 enhanced font 'Verdana,10'
set output 'First.png'
set title "First Improvement"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Current First" w l, 'ejemplo.txt' using 2 t "Best First" w l
_end_
