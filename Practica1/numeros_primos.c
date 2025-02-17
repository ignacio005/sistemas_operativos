#include <stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[]){

void primo(int n){ // Se basa en contar cuantas exactas tienes, solo dos entre 1 y si mismo

int exactas = 0;
for (int i = 1; i <= n; i ++){

if (n % i == 0){
exactas ++;
}
}

if (exactas == 2){
printf("Es primo el número %d. ", n);
} else {
printf("No es primo el número %d. ", n);
}
}

if (argc < 2){
printf("Introduce como mínimo un número.");
return;
}

int numeros[argc - 1];
for (int i = 1; i < argc; i ++){
numeros[i - 1] = atoi(argv[i]);
}

for (int i = 0; i < argc - 1; i ++){
int numero = numeros[i]; 
primo(numero);
}
}
