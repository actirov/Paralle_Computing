#include <iostream>
#include <omp.h>
using namespace std;
int main(int argc, char** argv){

    const int N = 1000;
    float a[N];
    float b[N];
    float c[N];
    long start = 0;
    long end = 0;
    int i = 0;
    int thread_id = 0;
    int chunk_size = 100;

    for (i = 0; i<N; i++){

        a[i] = i * 1.0;
        b[i] = i * 1.0;

    }

    omp_set_num_threads(2);
    start = omp_get_wtime();

    #pragma omp parallel shared(a, b, c, chunk_size) private(thread_id, i)
    {
        thread_id = omp_get_thread_num();
        cout << "Hilo " << thread_id << "\n";
        if (thread_id == 0) {
            cout << "Numero de hilos: " << omp_get_num_threads() << "\n";

        }

        #pragma omp for schedule(dynamic, chunk_size)
        for (i = 0; i < N; i++){

            c[i] = a[i] + b[i];
            cout << "c[" << i << "]" << c[i] << " " << thread_id << "\n";


        }



    }
    end = omp_get_wtime();
    cout << "Tiempo: " << end - start;



}