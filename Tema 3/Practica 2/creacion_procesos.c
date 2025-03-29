#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>

//2d)
void funcion4(){
    int fd = open("cat.txt", O_CREAT | O_RDWR, 0666);
    char texto[] = "Hola.";
    write(fd, texto, strlen(texto));
    lseek(fd, 0, SEEK_SET);
    char letra;
    while(read(fd, &letra, 1) == 1){
    write(1, &letra, 1);
    }
}

//2d)
void funcion3() {
    char mensaje[] = "Soy P6";
    for (int i = 0; mensaje[i] != '\0'; i++) {
        write(1, &mensaje[i], 1);
        sleep(1); 
    }
}

//2c)
void funcion2() {
    char texto[] = "He recibido una señal de mi proceso padre \n";
    write(1, texto, strlen(texto)); // 1 por pantalla
}

//2b)
void funcion1() {
    char texto[] = "Soy el proceso P3 y he recibido una señal del proceso P5 \n";
    write(1, texto, strlen(texto)); // 1 por pantalla
}

int main() {
    // Variables para almacenar los PIDs de P3 y P5
    int pidP3;
    int pidP5;  
    //Main
    printf("Soy el proceso %d y mi padre es %d \n", getpid(), getppid());
    int variable = 0;

    if (fork() == 0) {
        //P1
        printf("Soy el proceso P1 %d y mi padre es %d \n", getpid(), getppid());
        variable++;
        printf("Variable P1: %d \n", variable);
        exit(0);
    } else if (fork() == 0) { //hijo
        //P2
        printf("Soy el proceso P2 %d y mi padre es %d \n", getpid(), getppid());
        variable++;
        printf("Variable P2: %d \n", variable);
        // 2a)
        int fd = open("arch.txt", O_CREAT | O_RDWR, 0666);
        close(fd);
        exit(0);
    } else if ((pidP3 = fork()) == 0) {
        //P3
        printf("Soy el proceso P3 %d y mi padre es %d \n", getpid(), getppid());
        variable++;
        printf("Variable P3: %d \n", variable);
        
        // Configurar la señal para recibirla de P5
        signal(SIGUSR1, funcion1);
        
        // Crear P5 (nieto)
        if ((pidP5 = fork()) == 0) {
            // P5
            printf("Soy el proceso P5 %d y mi padre es %d \n", getpid(), getppid());
            
            // Configurar la señal para recibirla de P3
            signal(SIGUSR1, funcion2);
            
            sleep(1);  // esperar antes de enviar la señal
            
            // P5 envía la señal a P3
            kill(getppid(), SIGUSR1);  // Enviar señal a P3
            exit(0);
            
        } else {
            // P3 envía señal a P5
            kill(pidP5, SIGUSR1);  // Enviar señal a P5 desde P3
            exit(0);
        }
    } else if (fork() == 0) {
        //P4
        printf("Soy el proceso P4 %d y mi padre es %d \n", getpid(), getppid());
        execl("/bin/ls", "ls", (char *)0);
        exit(0);
    } else if (fork() == 0) {
        //P6
        printf("Soy el proceso P6 %d y mi padre es %d \n", getpid(), getppid());
        signal(SIGUSR1, funcion3);// Para q reciba señal del terminal
        pause();
        exit(0);
    }

    while (wait(NULL) > 0); // Esperar a que los hijos terminen
    printf("\nVariable final: %d \n", variable);
    funcion4();
    return 0;
}


//1b) Depende del sistema operativo que proceso va primero.

//1c) El valor de la variable en el proceso final es 0, porque el proceso padre no le afecta los cambios realizados por los hijos, cada proceso tiene su propio espacio de memoria independiente después de fork.

