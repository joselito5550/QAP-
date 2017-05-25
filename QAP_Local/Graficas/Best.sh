#!/bin/bash

cat << _end_ | gnuplot
set terminal pngcairo size 600,500 enhanced font 'Verdana,10'
set output 'Best.png'
set title "Best Improvement"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 3 t "Current Best" w l, 'ejemplo.txt' using 4 t "Best Best" w l
_end_
