#!/bin/bash

cat << _end_ | gnuplot
set term png 
set output "graficoTabuSearch.png"
set key right bottom
set xrange [0:1500]
set xlabel "Iteracion"
set ylabel "Coste"
plot "ejemplo.txt" using 3 t "Current TS" w l, "ejemplo.txt" using 4 t "Best TS" w l,
_end_
