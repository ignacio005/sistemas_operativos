#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <signal.h>

void main(){
execl("./prog_B", "prog_B", (char*)0);
}
