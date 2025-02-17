#include<stdio.h>
#include<unistd.h> 

int restar(int *a){
*a = *a - 1; // *a trabajas con el valor de la variable
return *a;
}

void main(){
int var;
scanf("%d", &var);

while(var != 0){
var = restar(&var); // Ojo: es &var y no var, porq espera una dirección para el puntero
printf("var %d ", var);
fflush(stdout);
sleep(1);
}

}
