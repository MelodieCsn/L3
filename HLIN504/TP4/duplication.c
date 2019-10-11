#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
int globale = 1234;
int main(){
    int locale=6789;
    int tab[4];
    for(int i=0; i<4; i++){
        tab[i]=0;
    }

    pid_t pid;
    switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            printf("du descendant : valeur de retour de fork() : %d\n", pid);
            printf("du descendant : je suis %d de parent %d \n", getpid(),getppid()) ;
            locale=0; globale=0; tab[0]=1;
            printf("locale=%d, globale=%d, tab[0]=%d", locale, globale, tab[0]);
            break ;
        }
        default:{  // c’est le parent
            // int status;
            // wait(&status);
            printf("du parent : valeur de retour de fork() : %d\n", pid);
            printf("du parent : je suis %d de parent %d \n",getpid(), getppid());
            printf("locale=%d, globale=%d, tab[0]=%d", locale, globale, tab[0]);
            
            break ;
        }
    }
}// MORALITE : LE WAIT PERMET DE SYNCHRONISER ET SAVOIR QUEL PROCESSUS SE FAIT DANS QUEL ORDRE, 
//DONC ICI LE WAIT PERMET DE DIRE A L'ORDI D'ATTENDRE QUE LE FILS AIT FINI DE S'EXECTUTER POUR PASSER AU PERE