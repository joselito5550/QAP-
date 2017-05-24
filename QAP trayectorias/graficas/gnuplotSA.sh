#!/bin/bash

cat << _end_ | gnuplot
set term png 
set output "graficaEnfriamiento.png"
set key right bottom
set xlabel "Iteracion"
set ylabel "Coste"
plot 'ejemplo.txt' using 1 t "Mejor Encontrado" w l, 'ejemplo.txt' using 2 t "Valores medios" w l,
_end_
