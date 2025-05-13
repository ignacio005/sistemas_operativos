#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t termo_lleno;
sem_t pedir_cafe;
sem_t hacer_cafe;
sem_t recibir_cafe;
int n_cafes = 1;

void *trabajo (void *arg){
	int num = *(int *) arg;
	sem_wait(&termo_lleno);
	printf("Está trabajando el trabajador %d. \n", num);
	sleep(10);
	sem_post(&pedir_cafe);
}

void *cafe (void *arg){
	while (n_cafes < 20){
		sem_wait(&pedir_cafe);
		sem_post(&hacer_cafe);
		sem_wait(&hacer_cafe);
		printf("Dolce está haciendo el café.\n");
		sleep(5);
		n_cafes ++;
		sem_post(&recibir_cafe);		
	}
}

void *repartir (void *arg){
	while (n_cafes < 20){
		sem_wait(&recibir_cafe);
		printf("El café se está repartiendo.\n");
		sleep(10);
		sem_post(&termo_lleno);
	}
}




void main (){
pthread_t programador[20];
pthread_t dolce;
pthread_t repartidor;

sem_init (&termo_lleno, 0, 1); // comienza a trabajar al estar el termo lleno al inicio
sem_init (&pedir_cafe, 0, 0); // espera a ser despertado por el trabajador
sem_init (&hacer_cafe, 0, 0); // espera a ser despertado por el repartidor
sem_init(&recibir_cafe, 0, 0);

for (int i = 0; i < 20; i++){
	pthread_create(&programador[i], NULL, trabajo, (void*)&i);
	sleep(1);
}
pthread_create(&dolce, NULL, cafe, NULL);
pthread_create(&repartidor, NULL, repartir, NULL);

for (int i= 0; i < 20; i++){
	pthread_join(programador[i], NULL);
}
pthread_join(dolce, NULL);
pthread_join(repartidor, NULL);

}

