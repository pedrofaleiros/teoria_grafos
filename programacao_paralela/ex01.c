#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main() {

	int num_steps = 1000000;
	int num_threads = 0;

	printf("\nNUM THREADS: ");
	scanf("%d", &num_threads);

	double pi, *sum, step;

	sum = malloc(sizeof(double) * num_threads);

	step = 1.0/(double) num_steps;

	omp_set_num_threads(num_threads);

	double t1, t2;

	t1 = omp_get_wtime();

	#pragma omp parallel
	{
		int i;
		int id = omp_get_thread_num();
		int num = omp_get_num_threads();

		double x;

		for(i = id, sum[id] = 0.0; i < num_steps; i = i + num){
			x = (i+0.5)*step;
			sum[id] += 4.0/(1.0+x*x);
		}
	}

	t2 = omp_get_wtime();

	for(int i = 0; i < num_threads; i++){
		pi += sum[i] * step;
	}

	printf("\nTime: %lf", t2-t1);
	printf("\npi: %lf\n", pi);


	return 0;
}