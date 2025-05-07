#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * process(void * args){
    int i = * (int *)args;// Se convierte en un puntero de tipo * int, para obtener el valor id del hilo.
    printf("Soy el hilo %d\n", i);
    pthread_exit(0);
}

int main(void){
    pthread_t th[8];// Almacena ID de cada hilo
    int ids[8];// Guarda argumento de cada hilo.
    for(int i = 0; i < 8; i++){
        ids[i] = i;
        pthread_create(&th[i], NULL, process, &ids[i]); // 1) Puntero del id del hilo. 2) Siempre es NULL (atributos). 3) Función que ejecutará el hilo. 4) Argumento q se pasa a la función del hilo
        pthread_join(th[i], NULL); // 1) Puntero del id del hilo 2) Puntero del valor de retorno NULL.
    }

    return 0;
}

// Cambia el orden cada vez que se ejecuta, porque depende del sistema operativo que es el encargado de decidir cuando y en que orden cada hilo accede al CPU.
