#include <stdio.h>
#include <pthread.h>
void *functionA (void*);

int counter = 0;

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;

int main() {
	pthread_t tid[10];
	int i = 0, j = 0;
	for(i = 0; i < 10; i++) {
		pthread_create(&tid[i], NULL, functionA, NULL);
	}
	
	for(j = 0; j < 10; j++) {
		pthread_join(tid[j], NULL);
	}
	
	printf("Final counter value: %d\n", counter);
	return(0);
}

void *functionA(void *arg) {
	printf("Thread number: %d\n", pthread_self());
	pthread_mutex_lock(&mutexA);
	counter++;
	pthread_mutex_unlock(&mutexA);
	return 0;
}
