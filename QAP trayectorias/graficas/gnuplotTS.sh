#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoTabuSearch.eps"
set key right bottom
set xrange [0:500]
set xlabel "Iteracion"
set ylabel "Beneficio
plot "ejemplo.txt" using 3 t "Current TS" w l, "ejemplo.txt" using 4 t "Best TS" w l,
_end_
