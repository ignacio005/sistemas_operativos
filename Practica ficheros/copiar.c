#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char *argv[]){
if(argc != 3){
printf("Escribe dos txt.");
}
int origen = open(argv[1], O_RDWR, 0666);
int destino = open(argv[2], O_RDWR, 0666);

char letra;
while(read(origen, &letra, 1) == 1){
write(destino, &letra, 1);
}
printf("Copiado en %s\n", argv[2]);

}
