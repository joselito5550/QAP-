#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficaEnfriamiento.eps"
set key right bottom
set xlabel "Iteracion"
set ylabel "Beneficio"
plot 'ejemplo.txt' using 1 t "Mejor Encontrado" w l, 'ejemplo.txt' using 2 t "Valores medios" w l,
_end_
