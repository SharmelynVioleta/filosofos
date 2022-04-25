#include<stdio.h>
#include<pthread.h>

using namespace std;

#define numFilosofos 5

void *filosofo (void *arg);

pthread_mutex_t tenedor[5];
int var=0;
int main (void){
	printf("Iniciando programa de filosofos COmensales\n");
	printf("FILÓSOFOS:\n");
	pthread_t filosofos[numFilosofos];
	int id[numFilosofos];
	int i;
	
	
	printf("variable = %d\n", var);
	for (int i = 0; i< numFilosofos; i++){
		pthread_mutex_init(&tenedor[i], NULL);
	}
	for (int i = 0; i < numFilosofos; i++){
		id[i] = i+1;
		pthread_create(&filosofos[i], NULL, &filosofo, &id[i]);
	}
	for (int i = 0; i < numFilosofos; i++){
		pthread_join(filosofos[i], NULL);
	}
	printf("variable = %d\n", var);

	return 0;


}
void cogiendoTenedor (int fil, int think){
	pthread_mutex_lock (&tenedor[think]);
	printf("Filosofo %d cogio tenedor %d \n", fil,think);
}

void *filosofo (void *arg){
	char *arg2 =(char*)arg;
	for (int i = 0;true; i++){
		printf("%s Estoy comiendo: %d \n", arg2, i);
	}
	return NULL;	
}

