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

void affichageGraphique(int n, int m, coord point[], int tab[][2], string name){
  ofstream output;                           
  output.open(name,ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  
  int taille = 0;
  if ( name == "Arbre.ps"){
    taille = n;
  }
  else{
    taille = m;
  }
  for(int i=0;i<taille;i++){
    output << point[tab[i][0]].abs << " " << point[tab[i][0]].ord << " moveto" << endl;
    output << point[tab[i][1]].abs << " " << point[tab[i][1]].ord << " lineto" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << "showpage";
  output << endl;
}

//CREATION DES POINTS AVEC COORDONNEES RANDOM

void pointRandom(int n,coord point[]){
  cout << "\n## AFFICHAGE DES POINTS" << endl;
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

// FONCTION D'AFFICHAGE DE DISTANCES
void affichagedistances(int n, coord point[]){
  cout << "\n## AFFICHAGE DES DISTANCES" << endl;
  for(int i=0; i<n;i++){
    for(int j=0; j<i+1;j++){
        cout<<"distance entre (" << point[i].abs << "," << point[i].ord << ") et (" << point[j].abs << "," << point[j].ord << ") est "<<distance(point[i],point[j])<<endl;
    }
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


bool existe(int n,int d[],int traite[],int &x){ // true si on trouve un x pas encore traité
  int min=1000001;
  bool res= false;
  for(int i=0; i<n; i++){
    if(traite[i]==0){
      res=true;
      if(d[i]<min){
        x=i;
      }
    }
  }
  return res;
}

void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){
  int racine = 0;
  int d[n];
  int traite[n];
  int x;

  for(int i=0; i<n; i++){
    d[i]=1000000;
    traite[i]=0;
  }
  pere[0] = racine;
  d[racine] = 0;
  
  while(existe(n,d,traite,x)){
    traite[x]=1;
    for(int j=0;j<voisin[x].size();j++){
      if(traite[j]==0 && (d[voisin[x][j]] > d[x]+distance(point[x],point[voisin[x][j]])) ) {
        d[voisin[x][j]]=d[x]+distance(point[x],point[voisin[x][j]]);
        pere[voisin[x][j]]=x;
      }
    }
  }
}


int construireArbre(int n,int arbre[][2],int pere[]){
  int k = 0;
  for(int i = 0; i < n; i++){
    arbre[i][0] = i;
    arbre[i][1] = pere[i];
    k++;
  }
  return k;
}

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
  affichagedistances(n,point);
  voisins2arete(n,voisin,arete);
  dijkstra(n,voisin,point,pere);
  construireArbre(n, arbre, pere);

  affichageGraphique(n,m,point, arete,"affichage.ps");
  return EXIT_SUCCESS;
}
