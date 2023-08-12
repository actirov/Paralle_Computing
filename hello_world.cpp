// Your First C++ Program

// gcc holamundo.cpp -o holamundo -fopenmp

#include <iostream>
#include <omp.h>

int main() {
    std::cout << "Mi programa de OpenMP!";
    int thread_id = 0;
    omp_set_num_threads(4);

    #pragma omp parallel private(thread_id)
    {
        std::cout << "Numero de hilos: " << omp_get_num_threads();
        thread_id = omp_get_thread_num();
        /* Si es el hilo maestro*/
        if (thread_id ==0){
            std::cout << "Numero de hilos: " << omp_get_num_threads() << "\n";
        }
        std::cout << "Soy hilo " << thread_id << "\n";


    }

    return 0;
}