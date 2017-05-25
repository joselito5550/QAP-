#!/bin/bash

cat << _end_ | gnuplot
set terminal pngcairo size 600,500 enhanced font 'Verdana,10'
set output 'Genetico.png'
set key right bottom
set xlabel "Iteración"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Current GA" w l, 'ejemplo.txt' using 2 t "Best GA" w l,
_end_
