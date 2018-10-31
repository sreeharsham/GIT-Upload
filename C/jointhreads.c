#include <stdio.h>
#include <pthread.h>
void *functionA (void*);

int counter = 0;

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, functionA, NULL);
	pthread_create(&t2, NULL, functionA, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
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
