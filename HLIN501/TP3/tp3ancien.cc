#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

bool isIn(int n, vector<int> vect){//renvoie true si l'entier n est dans le vecteur vect
  for(int i= 0; i < (int)vect.size(); i++){
    if(n == vect[i]){
      return true;
    }
  }
  return false;
}


void voisinsrandom(int n, int m, vector<int> voisins[]){
  
  int point1;
  int point2;
  bool pas_bon = false;

  srand(time(NULL));
  
  for (int i = 0; i < m; i++)
  {
    do{
      point1 = rand()%n;
      point2 = rand()%n;

      if ( point1 == point2 ){
        pas_bon = false;
        continue;
      }

      for( int i=0; i < voisins[point1].size(); i++){
        if ( voisins[point1][i] == point2 ){
          pas_bon = true;
          break;
        }
      }

      for( int i=0; i < voisins[point2].size(); i++){
        if ( voisins[point2][i] == point1 ){
          pas_bon = true;
          break;
        }
      }
    }
    while( pas_bon );

    voisins[point1].push_back(point2);
    voisins[point2].push_back(point1);
  }
} 
  // while(m > 0){
  //   srand(time(NULL));
  //   int numVois = rand() % n;
  //   int v = rand() % n;
  
  //   while(v == numVois)
  //     v = rand() % n;
    
  //   voisins[numVois].push_back(v);
    
  //   if(!isIn(v, voisins[numVois])){
  //     voisins[numVois].push_back(v);
  //     voisins[v].push_back(numVois);
  //   }

  //   // if(isIn(numVois, voisins[v])){
  //   //   voisins[v].pop_back();
  //   // }

  //   m--;
  // }


void parcoursLargeur(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[]){
  int* dv = new int[n];
  
  for(int i = 0 ; i < n ; i++){
    dv[i] = 0;
    ordre[i] = -1;
    pere[i] = -1;
    niveau[i] = -1;
  }
  
  int racine = 0; //choisie arbitrairement

  int t = 2;
  dv[racine] = 1;
  ordre[racine] = 1;
  pere[racine] = racine;
  niveau[racine] = 0;

  queue<int> AT;
  AT.push(racine);

  while(!AT.empty()){
    
    int v = AT.front();
    AT.pop();
    
    for(int i = 0 ; i < (int)voisins[v].size() ; i++){
      
      int x = voisins[v][i];
      
      if(dv[x] == 0){
        
        dv[x] = 1;
        AT.push(x);
        ordre[x] = t; t+=1;
        pere[x] = v;
        niveau[x] = niveau[v] + 1;
      }
    }
  }
  delete[] dv;
}

void ecritureniveaux(int n, int niveau[]){
	int* nbNiv = new int[n];
	int nbNotIn = 0;
	
	for(int i = 0 ; i < n ; i++){
		nbNiv[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		if(niveau[i] != -1)
			nbNiv[niveau[i]]++;
		else
			nbNotIn++;
	}
	for(int i = 0 ; i < n ; i++){
		if(nbNiv[i] != -1 && nbNiv[i] != 0)
      cout << "Il y a " << nbNiv[i] << " sommets au niveau " << i << endl;
  }
  if(nbNotIn)
    cout << "Il y a " << nbNotIn << " sommets qui ne sont pas dans la composante de 0." << endl;

  delete[] nbNiv;
}

int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.
  voisinsrandom(n,m,voisins);
  cout << "voisins = {";
  for(int i = 0 ; i < n ; i++){
    cout << "{ ";
    for(int j = 0 ; j < (int)voisins[i].size() ; j++){
      cout << voisins[i][j] << " ";
    }
    cout << "}";
  }
  cout << "}\n";

  // parcoursLargeur(n, voisins, niveau, ordre, pere);
  // ecritureniveaux(n, niveau);
 
  return EXIT_SUCCESS;
}
