#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define N 100000

int cuenta = 0; // contador
int turno = 1; // resta: 0, suma: 1
void * suma(void * arg){
	for (int i = 1; i<= N; i++){
		while(turno != 0); //candado: espera q sea su turno
		cuenta = cuenta + 1; //SC
		turno = 1; //llave: le pasa el turno a resta
	
	}
}

void * resta(void * arg){
	for (int i = 1; i<= N; i++){
		while(turno != 1); //candado: espera q sea su turno
		cuenta = cuenta - 1; //SC
		turno = 0; //llave: le pasa el turno a suma
	
	}
}

void main (){
	pthread_t h1, h2; // ID cada hilo
	
	pthread_create(&h1, NULL, suma, NULL); //Crea el hilo
	pthread_create(&h2, NULL, resta, NULL);
	pthread_join(h1, NULL); //Espera a que el hilo termine
	pthread_join(h2, NULL);
	
	printf("Valor final de cuenta: %d", cuenta);

}
