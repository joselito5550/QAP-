#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoGrasp.eps"
set key right bottom
set xrange [0:1000]
set xlabel "Iteracion"
set ylabel "Beneficio"
plot 'ejemplo.txt' using 5 t "Mejor Encontrado" w l, 'ejemplo.txt' using 6 t "Valores medios" w l,
_end_