#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t aforo;
sem_t sofas;
sem_t silla;
sem_t peluquero;
sem_t cliente_duerme;
sem_t mutex;

void *cortar(void *arg){

	int contador = 0;
	while(contador<50){
		
		int num =*(int *)arg;
		sem_wait(&mutex);
		sem_wait(&peluquero);
		printf("Peluquero %d", num);
		sleep(5);
		contador ++;
		sem_post(&cliente_duerme);
		sem_post(&mutex);
	
	}
}


void *pasar(void *arg){

	int num =*(int *)arg;
	num++;
	sem_wait(&aforo); // mientras este lleno
	printf("Soy %d", num);
	fflush(stdout);
	sleep(2);
	sem_wait(&sofas); // mientras este lleno
	sem_wait(&silla); // mientras este lleno
	sem_post(&sofas); // liberas el sofa para el q haya salido se llene
	sem_post(&peluquero); // Peluquero corta el pelo
	sem_wait(&cliente_duerme); // se duerme al cliente
	sem_post(&silla); // se deja libre la silla
	sem_post(&aforo); // se permite el paso de más gente
	
}




void main (){

pthread_t clientes[50];
pthread_t h_peluquero[3];

sem_init(&aforo, 0, 20);
sem_init(&sofas, 0, 4);
sem_init(&silla, 0, 3);
sem_init(&peluquero, 0, 0);
sem_init(&cliente_duerme, 0, 0);
sem_init(&mutex, 0, 1);


for(int i = 0; i<50; i++){
	
	pthread_create(&clientes[i], NULL, pasar, (void *)&i);
	sleep(1);
	
}

for(int i = 0; i<3; i++){
	
	pthread_create(&h_peluquero[i], NULL, cortar, (void *)&i);
	sleep(1);
	
}

for(int i = 0; i<50; i++){

	pthread_join(clientes[i], NULL);
	
}

for(int i = 0; i<3; i++){

	pthread_join(h_peluquero[i], NULL);
	
}

}
