# Proyecto Clausura

This is a paralell implementation of the Bag of Words algorithm utilizing MPI.

## How to run

### Pre-requisites

+ C++
+ Bash
+ An MPI installation

### Execution
Execute the `run.sh` file on the terminal to see the time it takes for each implementation to execute.

## Files

+ Source code
  + `bow_paral_final.cpp` The paralell MPI implementation of the BOW algorithm
  + `bow_serial_final.cpp` The serial implementation of the BOW algorithm
+ Executables
  + `bow_paral_final` Executable of the corresponding source file
  + `bow_serial_final` Executable of the corresponding source file
  + `run.sh` Bash script to run both executables
+ Results
  + `serial_bow.csv` The resulting serial BOW matrix
  + `arreglo_paralelo.csv` The resulting parallel BOW matrix
+ Misc
  + `data.csv` Data of 3 trial runs of each implementation
  + `grafica.png` A chart based on the aforementioned data
  + `makefile` A makefile utility

All `.txt` files form the corpus data.
