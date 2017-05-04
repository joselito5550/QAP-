#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoIteratedGreedy.eps"
set key right bottom
set xrange [0:]
set xlabel "Iteracion"
set ylabel "Beneficio"
plot 'ejemplo.txt' using 7 t "Mejor Encontrado" w l, 'ejemplo.txt' using 8 t "Valores medios" w l,
_end_
