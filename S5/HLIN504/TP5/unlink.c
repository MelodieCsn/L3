#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int n, char*argv[]){
    int err=unlink(argv[1]);
    
    if(err<0){
        fprintf(stderr, "erreur à la suppression de %s \n", argv[1]);
        fprintf(stderr,"erreur numero %d, identifiant %s \n",errno,strerror(errno));
    }
    else{
        printf("suppression de %s reussie",argv[1]);
    }
}