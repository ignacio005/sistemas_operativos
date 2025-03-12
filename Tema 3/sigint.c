#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
# define VUELTAS 10000000000
void Salir (int sig)
{
switch (sig)// en sing llega lo q devuelve la señal y para distinguir más de una el swich
{
case(SIGTERM):
printf("Saliendo del programa al recibir la señal SIGTERM\n");
exit(EXIT_SUCCESS);
case(SIGINT):
printf("Saliendo del programa al recibir la señal SIGINT\n");
exit(EXIT_SUCCESS);
break;
}
}
int main (void)
{
int i; // Si hubiera dos SIGTERM o SIGINT haria caso al último
signal(SIGINT,Salir); 
signal(SIGTERM, Salir);// SIGTERM mata cualquier proceso 
for (i=0; i<VUELTAS; i++){}
printf ("Fin del programa sin recibir la señal SIGTERM\n");
exit(EXIT_SUCCESS);
}

//Para ejecutar:
//./sigterm &
//4511 (devuelve del primer comando)
//kill -SIGTERM [pid (4511)]
//o
//Ctrl + c
