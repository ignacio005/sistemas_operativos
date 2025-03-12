#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

void main(){
printf("Soy padre mi ppid %d \n", getpid());
for(int i=1; i < 9 ; i++){
int rt = fork();

if(rt == 0){ // filtro para evitar q los hijos se conviertan en padres
             // (rt != 0) para q los hijos se conviertan en padres
printf("Soy Hijo %d, mi ppid %d y mi pid %d \n", i, getppid(), getpid());
break;
}
}
sleep(1); // para guardar el estado del padre o while(wait(NULL)>0)
}
