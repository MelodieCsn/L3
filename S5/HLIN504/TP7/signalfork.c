#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<unistd.h>

void gst(int s)
{
    printf("Mes enfants sont morts, je vais mourir aussi %d\n",getpid());
}

int main(){
    struct sigaction action;
    action.sa_handler=gst;
    action.sa_flags= SA_RESTART;
    sigaction(SIGCHLD,&action,NULL);
    pid_t pid;
    switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            printf("je suis un des fils qui va mourir, voici mon id en cadeau d'adieu : %d\n",getpid());
            break ;
        }
        default:{  // c’est le parent
            printf("je suis le pere : %d\n",getpid());
            pid=fork();
            wait(NULL);
            switch(pid){
                case 0 :
                    printf("je suis un des fils qui va mourir, voici mon id en cadeau d'adieu : %d\n",getpid());
                    break;
                default:
                    printf("toujours le père %d\n",getpid());
                    wait(NULL);
            }
        }  
    }
    return 0;
}