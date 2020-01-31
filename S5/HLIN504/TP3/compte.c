#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char * argv[]) { //ne prend pas en compte les caractères spéciaux type î
    int nb_char = 0;
    int chaine[256];
    char c;

    if(argc != 2) {
        printf("Erreur\n");
        return 1;
    }
    int f = open(argv[1],0);
    if(f < 0) {
        printf("ouverture impossible de %s\n" , argv[1]);
        return 2;
    }
    for(int i = 0 ; i < 256 ; i++)
        chaine[i] = 0;
    while(0 < read(f , &c , 1)) {
        if(chaine[(int)c]==0){
            chaine[(int)c]=1;
            nb_char++;
        }
    }
    close(f);
    printf("Il y a %d caractères différents" , nb_char);
    for(int j = 0 ; j < 256 ; j++)
        if(chaine[j]==1)
            printf("%c : %d\n" , j , chaine[j]);
    printf("\n");
    return 0;
}
