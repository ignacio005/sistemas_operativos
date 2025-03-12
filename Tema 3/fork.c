#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

void main(){
int pid = fork();
printf("Padre: %d y Hijo: %d ", getppid(), getpid());
sleep(1);
}
