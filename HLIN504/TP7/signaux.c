#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>

// EXO 1
// void gst(int s){
//     printf("int Ctrl-C\n");
//     exit(1);
// }
// int main(){
//     struct sigaction action;
//     action.sa_handler=gst;
//     sigaction(SIGINT,&action,NULL);
//     while (1);
//     return 0;
// }

// EXO 2
// void gst(int s){
//     printf("int Ctrl-C\n");
//     exit(1);
// }
// int main(){
//     struct sigaction action;
//     action.sa_handler=SIG_IGN;
//     sigaction(SIGINT,&action,NULL);
//     while (1);
//     return 0;
// }

// EXO 3
struct sigaction action;
void gst(int s){
    action.sa_handler=SIG_DEL; // sig del pas reconnu ?
    sigaction(SIGINT,&action,NULL);
    printf("int Ctrl-C\n");
    exit(1);
}
int main(){
    action.sa_handler=gst;
    sigaction(SIGINT,&action,NULL);
    while (1);
    return 0;
}
