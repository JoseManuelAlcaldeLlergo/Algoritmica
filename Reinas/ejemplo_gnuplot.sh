#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Numero de reinas"
set ylabel "Tiempo empleado (microseg)"
plot 'Datos.txt' using 1:2 t "Tiempos Reales" w l, 'Datos.txt' using 1:3 t "Tiempos Estimados" w l, 'Datos.txt' 
_end_
