#include <stdio.h>
#include <stdlib.h>

void par(int n){
int k = n % 2;
if (k == 0){
printf("El número %d es par. ", n);
} else{
printf("El número %d es impar.", n);
}

}

void main(int argc, char *argv[]){
if (argc < 2){
printf("Introduce como mínimo un número.");
}

int numeros [argc - 1];
for (int i = 1; i < argc; i ++){
numeros[i - 1] = atoi(argv[i]);
}

for (int i = 0; i < argc - 1; i ++){
int numero = numeros[i];
par(numero);
}

}
