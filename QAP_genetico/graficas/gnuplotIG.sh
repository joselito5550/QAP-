#!/bin/bash

cat << _end_ | gnuplot
set term png 
set output "graficoIteratedGreedy.png"
set key right bottom
set xrange [0:1500]
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 7 t "Mejor Encontrado" w l, 'ejemplo.txt' using 8 t "Valores medios" w l,
_end_
