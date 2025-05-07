#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(){
int fd = open("archivo.txt", O_CREAT | O_RDWR, 0666); 
char mensaje[] = "Creando el primer archivo.";
write(fd, mensaje, strlen(mensaje));// No se pone &mensaje porque el array mensaje ya es puntero.

lseek(fd, 0, SEEK_SET); //Mover el puntero de lectura/escritura al inicio del archivo para leer. Esta al final por haber escrito antes

char letra;
while(read(fd, &letra, 1) == 1){ //lee letra de una en una y termina de leer cuando es 0
putchar(letra); // printf("%c", letra); o write(1, &c, 1)
fflush(stdout);
sleep(1);
}



}
