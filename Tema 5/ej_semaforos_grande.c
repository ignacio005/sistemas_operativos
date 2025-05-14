#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t huecos;
sem_t datos;
sem_t mutex;
int contador_datos = 0;

void *producir(void *arg) {
    int num = *(int *)arg;
    sem_wait(&huecos);

    printf("Soy el productor %d\n", num);

    sem_wait(&mutex);
    contador_datos++; // Sección crítica
    sem_post(&mutex);

    sleep(1); // Simula el tiempo de producción

    sem_post(&datos);
}

void *consumir(void *arg) {
    sem_wait(&datos);

    printf("Soy el consumidor\n");

    sem_wait(&mutex);
    contador_datos--; // Sección crítica
    sem_post(&mutex);

    sleep(2); // Simula el tiempo de consumo

    sem_post(&huecos);
}

int main() {
    pthread_t productores[20];
    pthread_t consumidor;
    int h_id[20];

    sem_init(&huecos, 0, 5); // Hay 5 huecos en el buffer
    sem_init(&datos, 0, 0);
    sem_init(&mutex, 0, 1);

    // Creo todos los productores
    for (int i = 0; i < 20; i++) {
        h_id[i] = i + 1;
        pthread_create(&productores[i], NULL, producir, &h_id[i]);
    }

    // Espero a que todos los productores terminen
    for (int i = 0; i < 20; i++) {
        pthread_join(productores[i], NULL);
    }
    
    while(contador_datos >= 5){
    	consumir();
    }
    
    pthread_create(&consumidor, NULL, consumir, NULL);
    pthread_join(consumidor, NULL);

}

