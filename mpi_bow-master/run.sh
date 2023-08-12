#!/bin/bash
echo "Ejecutando serial"
./bow_serial_final
echo "Ejecutando paralelo"
~/opt/usr/local/bin/mpiexec -n 7 ./bow_paral_final