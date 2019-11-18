// #include<stdio.h>
// #include<stdlib.h>
// #include<signal.h>
// #include<errno.h>
// #include<unistd.h>


// void crible(int in[2]){
//     pipe(in);
//     close(in[1]);
//     int p;
//     if(0!= read(in[0],&p,sizeof(int)))){
//         printf("%d",p);
//         int out[2];
//         pipe(out);
//         int fils;
//         switch(fils=fork()){
//             case -1 : 
//                 fprintf(stderr,"erreur fork"); 
//                 exit(1);
//                 break;
//             case 0 : 
//                 close(in[0]); 
//                 crible(out); 
//                 break;
//             default : 
//                 close(out[0]);
//                 int i;
//                 while(i=read(in[0], &i, sizeof(int))){
//                     if(i%p != 0){
//                         write(out[1], &i, sizeof(int));
//                     }
//                 }
//                 close(in[0]);
//                 close(out[1]);
//                 break;
//         }
//     }
// }


// int main(int argc, char const *argv[]){

// int borne;
// if(argc !=2 ){
//     fprintf(stderr,"syntaxe : %s\n",argv[0]); 
//     exit(2);
// }
// else if((borne=atoi(argv[1]))<2){
//     fprintf(stderr, "syntaxe : n entier > 2\n");
//     exit(2);
// }

// int tube[2],pid_t fils;
// if(pipe(tube)== -1){
//     perror("pb de tube \n");
//     exit(1);
// }

// switch(fils=fork()){
//     case 0 : crible(tube[0]);
//     for(int i=2; i<=borne; i++){
//         write(tube[1],void*, &i,sizeof(int));
//         close(tube[1]);
//     }
// }
// return 0;
// }

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void crible(int in[2]){
    close(in[1]);
    int P;
    int r = read(in[0],&P,sizeof(int));
    if(r<=0){
        if(r<0)
            fprintf(stderr,"Erreur de read n°1.\n");
        return;
    }
    if(P!=0){
        printf("%i\n",P);
        int out[2];
        pipe(out);
        pid_t f = fork();
        if(f==0){
            close(in[0]);
            crible(out);
        }
        else{
            if(f>0){
                close(out[0]);
                int i;
                while(r = read(in[0],&i,sizeof(int))){
                    if(r<=0){
                        if(r<0)
                            fprintf(stderr,"Erreur de read n°2.\n");
                        return;
                    }
                    if(i%P!=0)
                        write(out[1],&i,sizeof(int));
                }
                close(in[0]);
                close(out[1]);
                wait(0);
                }
            else
                fprintf(stderr, "Erreur du fork.\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    if(argc != 2){
        fprintf(stderr,"Il faut 2 paramètres THO-MAS.\n");
        exit(1);
    }

    int borne = atoi(argv[1]);
    if(borne < 2){
        fprintf(stderr,"Entier < 2.\n");
        exit(1);
    }

    int tube[2];
    if(pipe(tube) < 0){
        fprintf(stderr, "Erreur d'ouverture.\n");
        exit(1);
    }

    pid_t fils;
    switch(fils = fork()){
        case -1:
            fprintf(stderr, "Erreur sur le fork.\n");
            break;
        case 0:
            crible(tube);
            exit(0);
            break;
        default:
            close(tube[0]);
            for (int i=2; i<borne; i++){
                write(tube[1],&i,sizeof(int));
            }
            close(tube[1]);
            wait(0);
            break;
    }
}