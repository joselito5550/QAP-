#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoFirst.eps"
set title "First Improvement"
set key right bottom
set xlabel "Iteration"
set ylabel "Cost"
plot 'ejemplo.txt' using 1 t "Current First" w l, 'ejemplo.txt' using 2 t "Best First" w l
_end_
