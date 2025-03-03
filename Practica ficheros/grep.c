#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char *argv[]){

if(argc != 3){
printf("Escribe un string para buscar y un archivo.");
}

int fd = open(argv[2], O_RDWR, 0666);

char buffer[1024];  // Buffer para leer cada porción del archivo (linea)
int bytes_leidos;
char *busca = argv[1];  // La palabra a buscar

// Leer el archivo con read()
while ((bytes_leidos = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
buffer[bytes_leidos] = '\0';  // Asegurarse de que el contenido del string esté terminado en '\0' para utilizar strstr

// Buscar si la palabra está en el buffer (linea)
if (strstr(buffer, busca)) {
printf("Encontrado: %s", buffer);  // Imprimir la línea que contiene la palabra
}

}
}
