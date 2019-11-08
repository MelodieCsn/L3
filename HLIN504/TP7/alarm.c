#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<unistd.h>

// 1ERE VERSION
// void gst (int s){
//     printf("trop taaaaaaaaaard ! \n");
//     exit(1);
// }

// int main(){
//     struct sigaction action;
//     action.sa_handler=gst;
//     sigaction(SIGALRM,&action,NULL);
//     printf("Voulez vous continuer ?");
//     alarm(10);
//     int i;
//     scanf("%d",&i);
//     alarm(0);
//     return 0;
// }

// 2EME VERSION
void gst (int s){
    static int i =1;
    switch(i){
        case 1 : printf("plus que 15 secondes ! \n"); alarm(10);
        break;
        case 2 : printf("plus 5 secondes ! \n"); alarm(5);
        break;
        case 3 : printf("trop taaaaaard ! \n"); exit(1);
    }
    i++;
}

int main(){
    struct sigaction action;
    action.sa_handler=gst;
    action.sa_flags= SA_RESTART;
    sigaction(SIGALRM,&action,NULL);
    printf("Voulez vous continuer ?");
    alarm(5);
    int i;
    scanf("%d",&i);
    alarm(0);
    return 0;
}