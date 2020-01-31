#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    // if(argc != 2){
    //     fprintf(stderr,"Il faut 2 paramètres\n");
    //     exit(1);
    // }
    // int buffer[16];
    // int r=mkfifo("monfifo",S_IRWXU);
    // int in=open("monfifo",O_RDONLY);
    // int n=read(in,s,TAILLE);
    // int out = open("monfifo", O_WRONLY) ;

    // close(in);
    // close(r);

    pid_t pid;
    switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            // code du fils, autre fork de processus qui se lance
            pid=fork();
            switch(pid){
                case 0 :
                    //printf();
                    break;
                default:
                    //printf();
                    break ;
                }   
        default:{  // c’est le parent pinit
            int buffer[16];
            int r=mkfifo("monfifo",S_IRWXU);
            int fifo=open("Pinit",S_IRWXU);
            int tubejeton[2];
            int s=pipe(tubejeton);
            char jeton='c';
            write(tubejeton[1],&jeton,sizeof(char));
            
            }  
        }
    }

return 0;
}
