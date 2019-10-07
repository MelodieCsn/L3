#include "mm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


char* motSecret(){
    char* ms[4];
    srand(time(NULL));
    for(int i=0;i<5;i++) {
        if(i==4){
            ms[i]="/0";
        }
        else{
            ms[i]=rand()%10+"";
        }
    }
   return ms;
}

mm mm_creer(){
    struct mm m1 = {motSecret(),12};
}

void mm_detruire(mm);

int mm_test(mm jeu, char* essai);

int mm_nbessais(mm jeu);