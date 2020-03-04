using namespace std;
#include<string>
#include<iostream>

template<typename T>
void echange(T& e1, T& e2)
    {T aux=e1; e1=e2; e2=aux;}

template<typename Type>
void triBulles(Type T[], int tailleT)
{
    int i=tailleT-2,j; bool ech=true;
    while (i>=0 && ech){
        ech=false;
        for (j=0; j<=i; j++)
            if (T[j]>T[j+1])
                {echange(T[j],T[j+1]); ech=true;}
        i--;
    }
}

int main(){
    string tab[5] = {"aaa","eee","fff","ccc","ddd"};
    triBulles(tab,5);
    for(int i=0; i<5 ; i++){
        cout<<tab[i]<<endl;
    }
}