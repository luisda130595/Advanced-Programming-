#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_THREADS 20

int varglobal;
sem_t sema;

void * helloWorld(void *p){
	long id = (long)p;
	printf("Hello World %ld\n",id);
	sem_wait(&sema);
	varglobal += 100;
	sem_post(&sema);
	return NULL;
}

int main(){
	pthread_t threads[NUM_THREADS];
	long i;
	varglobal = 0;
	sem_init(&sema,0,1);
	
	for(i=0; i<NUM_THREADS; i++){
		pthread_create(&threads[i],NULL,helloWorld,(void *)i);
	}
	
	for(i=0; i<NUM_THREADS; i++){
		pthread_join(threads[i],NULL);
	}
	return 0;
}