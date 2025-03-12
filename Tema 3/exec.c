#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
int main(int argc, char *argv[]){
int rt;
rt=fork();
if (rt==0){
execl("/bin/ls","ls",(char*)0);// hijo
}
// si pones else sacas otro hijo, es decir hermano del de arriba
if (fork() == 0){
execl("/bin/ps","ps",(char*)0); // nieto
}
while (wait(NULL)>0);

}



