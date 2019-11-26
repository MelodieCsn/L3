#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "math.h"

using namespace std;
typedef struct coord
{
  int abs;
  int ord;
} coord;

void affichageGraphique(int n, coord point[], int arbre[][2])
// Cree le fichier Exemple.ps qui affiche
// les points et l'arbre de Kruskal.
{
  ofstream output;
  output.open("Exemple.ps", ios::out);
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
  for (int i = 0; i < n - 1; i++)
  {
    output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord
           << " moveto" << endl;
    output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
           << " lineto" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << "showpage";
  output << endl;
}

void pointRandom(int n, coord point[]) //CRÉE UN POINT AUX COORDONNEES ALEATOIRES
{
  srand(time(NULL));
  for (int i = 0; i < 60 ; i++) //remplacer n par 60 pour exercice 2 
  {
    point[i].abs = floor(300+200*cos(i));
    point[i].ord = floor(400+150*(sin(i)-cos(i)));
    
    //cout << "(" << point[i].abs << "," << point[i].ord << ")" << endl;
  }
}

void distances(int n, int m, coord point[], int edge[][3]) 
{
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      edge[k][0] = i;
      edge[k][1] = j;
      edge[k][2] = abs(point[j].abs - point[i].abs) + abs(point[j].ord - point[i].ord);//(point[i].abs-point[j].abs)*(point[i].abs-point[j].abs);
      //cout << "la distance entre " << edge[k][0] << " et " << edge[k][1] << " est " << edge[k][2] << endl;
      k++;
    }
  }
}

void tri(int m, int edge[][3]) //TRIBULLE SIMPLE
{

  int nbcases = m - 1;
  while (nbcases != 0)
  {
    for (int i = 0; i < nbcases; i++)
    {
      if (edge[i][2] > edge[i + 1][2])
      {
        swap(edge[i][2], edge[i + 1][2]);
        swap(edge[i][0], edge[i + 1][0]);
        swap(edge[i][1], edge[i + 1][1]);
      }
    }

    nbcases -= 1;
  }

}

// UTILISATION QSORT
// inclure la bonne librairie
int
compare(const void * a,const void * b)
{
  return ((int*)a)[2] - ((int*)b)[2];
}

void
triRapide(int m, int edge[][3])
{
  qsort(edge,m,sizeof(edge[0]),compare);
}


void kruskal(int n, int m, int edge[][3], int arbre[][2])
{
  int *comp = new int[n];
  int h = 0;

  for (int i = 0; i < n; i++)
  {
    comp[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int x = edge[i][0];
    int y = edge[i][1];

    if (comp[x] != comp[y])
    {
      //cout << comp[x] << " est different de " << comp[y] << endl;
      arbre[h][0] = x; //on remplit l'arbre avec les id des sommets
      arbre[h][1] = y;
      h++;
      int aux = comp[x];
      for (int k = 0; k < n; k++)
      {
        if (comp[k] == aux)
        {
          comp[k] = comp[y];
        }
      }
    }
  }
}
// O(n2+mlogn)


void kruskalOpti(int n, int m, int edge[][3], int arbre[][2]){
  int* comp = new int[n];
  int h = 0;

  vector<vector<int> > sommets(n);

  for(int i = 0 ; i < n ; i++){
    comp[i] = i;
    vector<int> v; v.push_back(i);
    sommets[i] = v;
  }

  for(int i = 0; i < m; i++){

    int x = edge[i][0]; int y = edge[i][1];

    if(comp[x] != comp[y]){

      arbre[h][0] = x;
      arbre[h][1] = y;
      h++;

      if(sommets[comp[x]].size() > sommets[comp[y]].size())
        swap(x, y);

      int aux = comp[x];

      while(!sommets[aux].empty()){
        int z = sommets[aux].back();
        comp[z] = comp[y];
        sommets[comp[y]].push_back(z);
        sommets[aux].pop_back();
      }
    }
  }
  delete[] comp;
}
//O(mlogn)


int main()
{
  int n; //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m = n * (n - 1) / 2; // Le nombre de paires de points.
  coord point[n];          // Les coordonnees des points dans le plan.
  int edge[m][3];          // Les paires de points et le carre de leur longueur.
  int arbre[n - 1][2];     // Les aretes de l'arbre de Kruskal.

  pointRandom(n, point);
  distances(n, m, point, edge);
  triRapide(m, edge);
  kruskalOpti(n,m,edge,arbre);
  //kruskal(n, m, edge, arbre);
  affichageGraphique(n, point, arbre);

  //ATTENTION
  // POUR OPTIMISER AU MAX, IL FAUT UTILISER LA FONCTION FRUSKALOPTI ET LA FONCTION TRIRAPIDE

  return EXIT_SUCCESS;
}
