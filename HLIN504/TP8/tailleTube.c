#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<unistd.h>

int main(){
    int tube[2];
    int r=pipe(tube);
    int cpt=0;
    char c='c';
    while(1){
        write(tube[1],&c,sizeof(char));
        cpt++;
        printf("cpt : %d\n",cpt);
    }
    return 0;
}