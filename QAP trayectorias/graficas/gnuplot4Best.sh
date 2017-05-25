#!/bin/bash

cat << _end_ | gnuplot
set term png 
set output "Best3Graficas.png"
set key right bottom
set xlabel "Cost"
set ylabel "Iteration"
plot 'ejemplo.txt' using 2 t "SA" w l,'ejemplo.txt' using 4 t "TS" w l,'ejemplo.txt' using 6 t "Grasp" w l, 'ejemplo.txt' using 8 t "IG" w l,
_end_
