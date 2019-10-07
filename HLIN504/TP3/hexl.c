#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char * argv[]) {
    int position = 0, nb ;
    char c[16];
    if(argc != 2) {
        printf("You need to run this program with exactly one argument!\n");
        return 1;
    }
    int input = open(argv[1] , O_RDONLY); //ouverture du fichier
    if(input < 0) {
        printf("Can't open %s\n" , argv[1]);
        return 2;
    }
    while(0 < (nb = read(input , &c , 16))) { //tant que on a pas lu 16 caractères
        printf("%8.8x : ", position); //on affiche la position 00000xx
        position += 16; // on passe position à 16
        for(int i = 0 ; i < nb ; i++) {
            char code = c[i];
            printf("%2.2hhx" , code); //on affiche le code avec un espace tous les 4 caractères
            if(i % 2)
                printf(" ");
        }
        if(nb < 16) { //si après ça on est toujours dans la boule
            for(int i = nb ; i < 16 ; i++) { //on met un espace
                printf("  ");
                if(i % 2)
                    printf(" ");
            }
        }

        printf(" "); // espace entre le code et l'affichage des vrais caractères
        //printf("%s",c);

        for(int i = 0 ; i < nb ; i++) {
            if(c[i] >= 0x20 && c[i] < 0x7F) //si le code est un caractère ascii
                printf("%c" , c[i]);
            else
                printf(".");
        }
        printf("\n");
    }
    close(input);
    return 0;
}