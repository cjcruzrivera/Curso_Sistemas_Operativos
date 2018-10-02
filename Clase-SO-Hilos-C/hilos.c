#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define HILOS 50000

void *printIdHilo(void*);

int main(int argc, char *argv[]) {
	pthread_t tid;
	int i;

	for (i = 0; i < HILOS ; i++) {
		pthread_create(&tid, NULL, printIdHilo, NULL);
		//pthread_join(tid, NULL);
	}

	return 0;
}

void *printIdHilo(void *null){
	pthread_t id;
	id = pthread_self();
	printf("Hola %u\n", id);
}