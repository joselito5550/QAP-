#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico4graficas.eps"
set key right bottom
set xlabel "Currect"
set ylabel "Best"
plot 'ejemplo.txt' using 1 t "CurrentSA" w l, 'ejemplo.txt' using 2 t "BestSA" w l,'ejemplo.txt' using 3 t "" w l,'ejemplo.txt' using 4 t "S" w l,'ejemplo.txt' using 5 t "" w l,'ejemplo.txt' using 6 t "S" w l,'ejemplo.txt' using 7 t "" w l,'ejemplo.txt' using 8 t "S" w l,
_end_
