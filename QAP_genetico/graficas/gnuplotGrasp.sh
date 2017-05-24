#!/bin/bash

cat << _end_ | gnuplot
set term png 
set output "graficoGrasp.png"
set key right bottom
set xrange [0:1000]
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 5 t "Mejor Encontrado" w l, 'ejemplo.txt' using 6 t "Valores medios" w l,
_end_
