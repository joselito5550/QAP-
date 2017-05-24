#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Iteración"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Current GA" w l, 'ejemplo.txt' using 2 t "Best GA" w l,
_end_
