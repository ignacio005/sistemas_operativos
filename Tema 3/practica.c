#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
# define VUELTAS 10000000000
void funcion1(int sig){
kill(rt2, SIGUSR1)
}

void funcion2(int sig2){
kill(rt1, SIGUSR2)
}

int main (void){
int rt1 =fork();
if (rt1 == 0){//Hijo
int rt2 = fork();
if (rt2 == 0){
//Nieto
signal(SIGUSR2, funcion2);
}else{
signal(SIGUSR1, funcion1);
}
}else{
// Main
signal(SIGUSR1, funcion1);
}
while (wait(NULL)>0);
while (wait(NULL)>0);
for (int i=0; i<VUELTAS; i++){}
}
printf ("Fin del programa sin recibir la señal SIGUSR\n");
exit(EXIT_SUCCESS);
