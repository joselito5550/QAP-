#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoTodo.eps"
set title "Local Search"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Current First" w l, 'ejemplo.txt' using 2 t "Best First" w l,'ejemplo.txt' using 3 t "Current Best" w l,'ejemplo.txt' using 4 t "Best Best" w l
_end_
