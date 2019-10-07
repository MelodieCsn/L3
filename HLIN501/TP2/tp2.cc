#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "math.h"



using namespace std;
typedef struct coord{int abs; int ord;} coord;

void affichageGraphique(int n, coord point[], int arbre[][2])
// Cree le fichier Exemple.ps qui affiche
// les points et l'arbre de Kruskal.
{
  ofstream output;                           
  output.open("Exemple.ps",ios::out);
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
  for(int i=0;i<n-1;i++)
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

void pointRandom(int n, coord point[]){
    srand(time(NULL));
    for(int i=0; i<n; i++){
      point[i].abs=rand()%613;
      point[i].ord=rand()%793;
      cout<<"("<<point[i].abs<<","<<point[i].ord<<")"<<endl;
    }
  }

  void distances(int n, int m, coord point[], int edge[][3]){
    int k=0;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        edge[k][0] =i;
        edge[k][1] =j;
        edge[k][2] =abs(point[j].abs-point[i].abs*point[j].abs-point[i].abs)+ abs(point[j].ord*point[i].ord*point[j].ord*point[i].ord) ;
        cout<<"la distance entre "<<edge[k][0]<<" et "<<edge[k][1]<<" est "<<edge[k][2]<<endl;
      }
      k++;
    }
  }

  void tri(int m, int edge[][3]){

    int nbcases = m-2;
    while (nbcases != 0) {
        for(int i=0; i<nbcases; i++){
            if (edge[i][2]>edge[i+1][2]){
                swap(edge[i][2],edge[i+1][2]);
            }
          
        }

    nbcases-=1;    
    }
  }
  
  void kruskal(int n,int m, int edge[][3], int arbre[][2]){
	
  //int aux = 0, aux2 = 0;
  vector<vector<int> > sommets(n);
  for(int i = 0 ; i < n ; i++){
    arbre[i][2] = i;
    vector<int> v; 
    v.push_back(i);
    sommets[i] = v;
  }
  
  for(int i = 0; i < m; i++){

    int x = edge[i][0]; int y = edge[i][1];

    if(arbre[x][2] != arbre[y][2]){
      
      if(sommets[arbre[x][2]].size() > sommets[arbre[y][2]].size())
		    swap(x, y);

      int aux = arbre[x][2];

      while(!sommets[aux].empty()){
    		int z = sommets[aux].back();
        arbre[z][2] = arbre[y][2];
    		sommets[arbre[y][2]].push_back(z);
    		sommets[aux].pop_back();
      }
    }
  }
}
 
int main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 
  
pointRandom(n, point);
distances(n,m,point,edge);
tri(m,edge);
kruskal(n,m,edge,arbre);
affichageGraphique(n,point,arbre) ;


  

  return EXIT_SUCCESS;
}
