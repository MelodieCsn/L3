#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string.h>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

//CREATION DES POINTS AVEC COORDONNEES RANDOM

void pointRandom(int n,coord point[]){

  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    point[i].abs = rand() % 613;
    point[i].ord = rand() % 793;
    cout << "(" << point[i].abs << "," << point[i].ord << ")" << endl;
  }
}

// CALCUL DES DISTANCES ENTRE DEUX POINTS

float distance(coord p1,coord p2){
  float x = abs(p2.abs-p1.abs)*abs(p2.abs-p1.abs);
  float y = abs(p2.ord-p1.ord)*abs(p2.ord-p1.ord);
  float res = sqrt(x+y);
  return res;
}

// FONCTIONS D'AFFICHAGE DES VECTEURS

void affichageVector( vector<int> v ){
  int i=0;
  cout << "[ ";
  while( i < v.size() - 1 ){
    cout << v[i] << ", ";
    i++;
  }
  cout << v[i] <<" ]" << endl;
}

void affichageAllVector(int n, vector<int> v[] ){
  cout << "\n## AFFICHAGE DES VOISINS" << endl;
  for( int i=0; i < n; i++ ){
    cout << "Sommet " << i << " : ";
    if( v[i].size() == 0 ) { cout << "[ ]" << endl; }
    else{ affichageVector(v[i]); }
  }
}

// FONCTION QUI REMPLI LE VECTEUR DES VOISINS SELON LA DISTANCE ENTRE LES POINTS

void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m){
  m=0;
   for(int i=0; i<n; i++){
     for(int j=i+1; j<n; j++){
        if(dmax>=distance(point[i],point[j])){
          voisin[i].push_back(j);
          voisin[j].push_back(i);
          m++;
        }
     }
   }
}


void voisins2arete(int n,vector<int>voisin[],int arete[][2]){
int cpt=0;
for(int i=0; i<n;i++){
  for(int j=0; j<voisin[i].size();j++){
    if(i<voisin[i][j]){
    arete[cpt][0]=i;
    arete[cpt][1]=voisin[i][j];
    cpt++;
    }
  }
}
}


void affichageGraphique(int n,int m,coord point[],int arete[][2],string name){

// Cree le fichier de nom name qui affiche
// les points et l'arbre 
  ofstream output;
  output.open(name, ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;
  for (int i = 0; i < n; i++)
  {
    output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" << endl;
    output << "0 setgray" << endl;
    output << "fill" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << endl;
  for (int i = 0; i < n; i++)
  {
    output << point[arete[i][0]].abs << " " << point[arete[i][0]].ord
           << " moveto" << endl;
    output << point[arete[i][1]].abs << " " << point[arete[i][1]].ord
           << " lineto" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << "showpage";
  output << endl;
}


bool existe(int n,int dis[],bool traite[],int &x){
  bool res= false;
  for(int i=0; i<n; i++){
    if(traite[i]==0 && dis[i]<)
  }

}
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){
  int racine = 0;
  int d[n];
  for(int i=0; i<n; i++){
    d[i]=0;
    traite[i]=0;
  }

}
int construireArbre(int n,int arbre[][2],int pere[]);

int
main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=300;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2];                 // Les aretes du graphe

  pointRandom(n,point);
  voisins(n,dmax,point,voisin,m);
  affichageAllVector(n,voisin);
  voisins2arete(n,voisin,arete);
  affichageGraphique(n,m,point, arete,"affichage.ps");
  return EXIT_SUCCESS;
}
