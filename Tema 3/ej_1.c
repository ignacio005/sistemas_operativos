#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <signal.h>

void tratamiento(int sig) {
    printf("En el manejador de señales, ejecutando ps\n");
    execl("/bin/ps", "ps", "-l", (char*)0);
}

int main(void) {
    int pid = fork();

    if (pid == 0) {
        // Proceso hijo
        printf("Haz el primer ps\n");

        // Configura el manejador de señales
        signal(SIGUSR1, tratamiento);

        printf("Ahora lanzar la señal\n");
        printf("%s%d\n", "El PID del proceso hijo es ", getpid());

        // Pausa para esperar la señal
        sleep(15); // Esperar para recibir la señal
    } else {
        // Proceso padre
        sleep(1); // Asegúrate de que el hijo haya configurado la señal
        kill(pid, SIGUSR1); // Enviar la señal SIGUSR1 al hijo
    }

    // Esperar que el hijo termine
    while (wait(NULL) > 0);

}
//Antes de la imágen el hijo esta esperando la señal y después ejecuta el proceso ps
