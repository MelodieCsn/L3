#include "mm.h"
#include <stdio.h>
#include <unistd.h>
/** Fonction principale de la version console du jeu Mastermind
 */  

mm mm_creer(){
  mm jeu = malloc(sizeof(struct mm));
  jeu->nbessais=0;
  for (int i=0; i<TAILLE; i++)
    jeu->secret[i]='0'+rand()%10;
  jeu->secret[TAILLE]='\0';
  return jeu;
}

void mm_detruire(mm){
  free(mm);
}

int mm_test(mm jeu, char* essai);// modifier valeur d'essai for dans valeur secrete, si nb position exacte, sinon si ds autre mot endroit mal placé

int mm_nbessais(mm jeu){
  return jeu->nbessais
}

int main(){




  char* m1=motSecret();
  printf("le mot secret est %s/n",m1);
  // printf("taille mm : %d; taille struct mm : %d\n", sizeof(mm), sizeof(struct mm));
 // mm j=mm_creer();	
	// printf("%s\n",j->secret);
//   char saisie[1024];
//   int res, CONTINUER=1;
//   printf("Vous devez tenter de découvrir une combinaison secrète de %d chiffres [0-9] en saisissant répétitivement des mots de %d chiffres et en exploitant les réponses fournies. Bonne chance !\n", TAILLE, TAILLE);
//   do {
//     printf("?");
//     scanf("%s",saisie);
//     res=mm_test(j,saisie);
//     if (res==-1)
//       printf("Erreur de saisie !\n");
//     else if (res==0)
//       printf("Aucune lettre correcte !\n");
//     else {
//       printf("%d lettres bien placées, %d lettres mal placées !\n", res/(TAILLE+1),res%(TAILLE+1));
//       if(res/(TAILLE+1)==TAILLE){
//         printf("BRAVO ! Vous avez réussi en %d  essais !\n",mm_nbessais(j));
//         CONTINUER=0;
//       }
//     }
//   } while(CONTINUER);
  return 0;
}
