#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoBest.eps"
set title "Best Improvement"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 3 t "Current Best" w l, 'ejemplo.txt' using 4 t "Best Best" w l
_end_
