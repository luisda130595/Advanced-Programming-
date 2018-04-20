#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 20

void * helloWorld(void *){
	long * id = (long)p;
	char *msg (char *)malloc(25*sizeof(char));
	sprintf(msg, "Hello World %ld\n",id);
	printf("Hello World %ld\n",id);
	return NULL;
}

int main(){
	pthread_t threads[NUM_THREADS];
	long i;
	char *msg;
	
	for(i=0; i<NUM_THREADS; i++){
		pthread_create(&thread[i],NULL,helloWorld,(void *)i);
	}
	
	for(i=0; i<NUM_THREAD; i++){
		pthread_join(threads[i],(void *)&msg);
		printf("%s",msg);
	}
	return 0;
}