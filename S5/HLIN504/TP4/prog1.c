#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main(int argc, char* argv[]){
    printf("P1 avant recouvrement, nom%s, pid%d\n", argv[0], getpid());
    execl("/home/e20160001412/L3/HLIN504/TP4/test","prog2.c",NULL);
}