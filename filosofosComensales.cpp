#include<stdio.h>
#include<pthread.h>

using namespace std;

#define numFilosofos 5

void *filosofo (void *arg);

int main (void){
	printf("Iniciando programa de filosofos COmensales\n");
	printf("FILÓSOFOS:");
	pthread_t filosofos[numFilosofos];
	int id[numFilosofos];
	int i;
	
	for (int i=0; i < numFilosofos; i++){
		id[i]=i+1;
		pthread_create(&filosofos[i], NULL, &filosofo, &id[i];
	}

	return 0;
}
void *filosofo (void *arg){
	char *arg2 =(char*)arg;
	for (int i = 0;true; i++){
		printf("%s Estoy comiendo: %d \n", arg2, i);
	}
	return NULL;	
}
