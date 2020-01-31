#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char*argv[]){
    struct stat buff;
    if(argc != 2){
        fprintf(stderr,"nb d'arguments incorrect !\n");
        exit(1);
    }
    int k = lstat(argv[1], &buff);
    if(k<0){
        fprintf(stderr,"erreur sur %s\n",argv[1]);
        exit(1);
    }
    else if(S_ISREG(buff.st_mode)){
        printf("fichier régulier !\n");
    }
    else if(S_ISDIR(buff.st_mode)){
        printf("répertoire !\n");
    }
    else if((buff.st_mode & S_IFMT) == S_IFLNK){
        printf("lien !\n");
    }
    else{
        printf("autre type\n");
    }


}