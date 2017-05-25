#!/bin/bash

cat << _end_ | gnuplot
set terminal pngcairo size 600,500 enhanced font 'Verdana,10'
set output 'Aleaotorio.png'
set title "Aleatorio"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Mejor Encontrado" w l, 'ejemplo.txt' using 2 t "Valores medios" w l,
_end_
