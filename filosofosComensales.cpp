#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//#include<iostream>

//using namespace std;

#define numFilosofos 5

void *filosofo (void *arg);
int var = 0;

pthread_mutex_t tenedor[5];

int main (void){
	printf("Iniciando programa de filosofos COmensales\n");
	printf("\tFILÓSOFOS:\n");
	pthread_t filosofos[numFilosofos];
	int id[numFilosofos];
	int i;
	
	
	//printf("variable = %d\n", var);
	for (int i = 0; i < numFilosofos; i++){
		pthread_mutex_init(&tenedor[i], NULL);
	}
	for (int i = 0; i < numFilosofos; i++){
		id[i] = i+1;
		pthread_create(&filosofos[i], NULL, &filosofo, &id[i]);
	}
	for (int i = 0; i < numFilosofos; i++){
		pthread_join(filosofos[i], NULL);
	}
	//printf("variable = %d\n", var);

	return 0;


}
void cogiendoTenedor (int a, int b){
	pthread_mutex_lock (&tenedor[b]);
	printf("El filósofo número %d está usando el tenedor %d \n", a,b);
}


void soltarTenedor (int s1, int s2){
	pthread_mutex_unlock(&tenedor[s1]);
	pthread_mutex_unlock(&tenedor[s2]);
}

void comiendo (int arg){
	int t1 = arg-1;
	int t2 = arg-2;
	if (t2 == -1){
		t2 = 4;
	}
	cogiendoTenedor(arg, t1);
	cogiendoTenedor(arg, t2);
	printf ("FILÓSOFO %d ESTA COMIENDO \n",arg);
	int alt = rand() % 10;
	sleep(alt);
	soltarTenedor(t1, t2);
}
void *filosofo (void *arg){
	int arg2 = *((int *)arg);
	for (int i=1; i <=  5; i++){
		var = var + 1;
		comiendo (arg2);
	}
	return NULL;	
}

