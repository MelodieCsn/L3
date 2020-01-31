#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
    // if(argc != 2){
    //     fprintf(stderr,"Il faut 2 paramètres\n");
    //     exit(1);
    // }
    int r=mkfifo("monfifo",S_IRWXU);
//return 0;
}
