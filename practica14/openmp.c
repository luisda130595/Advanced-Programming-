#include <stdio.h>
#include <omp.h>
#deifne SIZE 2000

int main(){
	
	int a[SIZE], b[SIZE], c[SIZE];
	int i;
	int tid;
	int chunk = 20;
	
	#pragma omp paraller private(i) shared(a,b,chunk){
		tid = omp_get_thread_num();
		printf("I am %d\n",tid);
		#pragma for schedule(dynamic, chunk) nowait
		for(i=0;i<SIZE;i++){
			a[i] = i;
			b[i] = i;
		}
	}
	
	
	
	#pragma omp parallel private(i) shared(a,b,chunk)
	{
		tid = omp_get_thread_num();
		printf("I am %d\n",tid);
		for(i=0; i<SIZE; i++){
			c[i] = a[i]*b[i];
		}
		
	}
	
	return 0;
}