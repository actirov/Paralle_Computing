#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	int n_threads, thread_id;
	#pragma omp parallel private(n_threads, thread_id)
	{
		thread_id = omp_get_thread_num();
		printf("Thread %d says: Hello World \n", thread_id);
		if(thread_id == 0){

			n_threads= omp_get_num_threads();
			printf("Thread %d reports: the number of threads are %d\n", thread_id, n_threads);

		}



	}

	return 0;
}