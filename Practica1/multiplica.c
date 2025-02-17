#include<stdio.h>
#include<stdlib.h> // libreria del atoi()
void main (int argc, char *argv[]){ // el argc cuenta el nº de carácteres q se guardan en el argv[]

if (argc < 3){ // filtro para q se metan como mínimo dos números
printf("Introduce dos números como mínimo.");
return;
}
// 2 * 3 = 6
// argc = 3   Posición 0: nombre_archivo, 1: 2, 2: 3   Tamaño: 3
int numeros[argc-1]; // el tamaño de los arrays se escriben dentro de [] 
// Posicion 0: 2, 1:3   Tamaño: 2

for(int i = 1; i < argc; i ++){
numeros[i - 1] = atoi(argv[i]); // atoi() convierte el array de char en un int
}

int resultado = 1;
for(int a = 0; a < argc - 1; a ++){
resultado *= numeros[a];
}

printf("El resultado de la multiplicación es: %d ", resultado);
}
