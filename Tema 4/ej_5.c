#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * process(void * args){
    int letra= * (char *)args;// Se convierte en un puntero de tipo * int, para obtener el valor id del hilo.
    for(int i = 0; i < 3; i++){
    	printf("%c\n", letra);
    
    }
    pthread_exit(0);
}

int main(void){
    pthread_t th[3];// Almacena ID de cada hilo
    char letra[3] = {'A', 'B', 'C'};// Guarda argumento de cada hilo.
    for(int i = 0; i < 3; i++){
        pthread_create(&th[i], NULL, process, &letra[i]); // 1) Puntero del id del hilo. 2) Siempre es NULL (atributos). 3) Función que ejecutará el hilo. 4) Argumento q se pasa a la función del hilo
        pthread_join(th[i], NULL); // 1) Puntero del id del hilo 2) Puntero del valor de retorno NULL.
    }

    return 0;
}

// Ejercicio 6
//El resultado es cualquier combinación de 8 números del 0 al 7 con descansos de un segundo.
