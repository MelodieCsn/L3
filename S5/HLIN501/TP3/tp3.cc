#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;


 //Affiche tout les éléments d'un vecteur
 
void affichageVector( vector<int> v ){
  int i=0;
  cout << "[ ";
  while( i < v.size() - 1 ){
    cout << v[i] << ", ";
    i++;
  }
  cout << v[i] <<" ]" << endl;
}


//Affiche tout les éléments de chaque vecteur

void affichageAllVector(int n, vector<int> v[] ){
  cout << "\n## AFFICHAGE DES VOISINS" << endl;
  for( int i=0; i < n; i++ ){
    cout << "Sommet " << i << " : ";
    if( v[i].size() == 0 ) { cout << "[ ]" << endl; }
    else{ affichageVector(v[i]); }
  }
}

//Affichage de parcoursLargeur()

void affichePL(int voisin, int ordre, int pere, int niveau){
  (voisin == -1)? cout << "RACINE : 0" : cout << "VOISIN : "<< voisin << " - PERE : "<< pere;
  cout << " - NIVEAU : "<< niveau;
  cout << " - ORDRE : "<< ordre << endl;
}

// Affichage de parcoursProfondeur()
 
void affichePP(int voisin, int ordre, int pere, int niveau){
  (voisin == -1)? cout << "RACINE : 0" : cout << "VOISIN : "<< voisin << " - PERE : "<< pere;
  cout << " - NIVEAU : "<< niveau;
  cout << " - ORDRE : "<< ordre << endl;
}

//Affiche le nombre de sommet à chaque niveau

void afficheNiveau(int n, int niveau[]){
  cout << "\n## AFFICHAGE DES NIVEAUX " << endl;

  //Compteur du nombre de composante n'appartenant pas à la racine
  int nbNotIn = 0;

  //On crée un tableau permettant de savoir combien il y a de composante à chaque niveau

  int nbNiv[n]; for(int i=0; i < n; i++){ nbNiv[i] = 0; }

  //Si niveau[i] == -1 => N'est pas dans la composante
  //Sinon on incrémente car on a trouvé un sommet en plus

  for( int i=0; i < n; i++){
    if ( niveau[i] == -1 ){ nbNotIn++; }
    else{ nbNiv[niveau[i]]++; }
  }

  //Affichage des résultats
   
  for( int i=1; i < n; i++){
    if ( nbNiv[i] != 0 ){ cout << "Il y a " << nbNiv[i] << " sommet(s) au niveau " << i << endl; }
  }
  cout << "Il y a " << nbNotIn << " sommet(s) qui ne sont pas dans la composante de 0." << endl;
}

//On crée les voisins de chaque sommet

void voisinRandom(int n, int m, vector<int>voisins[]){

  int point1;
  int point2;
  bool pas_bon = false;

  srand(time(NULL));
  
  for (int i = 0; i < m; i++)
  {
    do{
      point1 = rand()%n;
      point2 = rand()%n;

      while ( point1 == point2 ){//pour pas avoir de doublons
        point1 = rand()%n;
        pas_bon = false;
      }
      
      for( int i=0; i < voisins[point1].size(); i++){
        if ( voisins[point1][i] == point2 ){//pour que si x est voisin de y, on mette y dans les voisins de x aussi
          pas_bon = true;
          break;
        }
      }

      for( int i=0; i < voisins[point2].size(); i++){//idem en symétrie avec y
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




/**
 * @brief On parcours l'arbre dans le sens de la largeur
 * 
 * @param n 
 * @param voisins 
 * @param niveau 
 * @param ordre 
 * @param pere 
 */
void parcoursLargeur(int n, vector<int> voisins[], int niveau[], int ordre[], int pere[]){

  /**
   * @brief On initialise dv
   * 
   */
  int* dv = new int[n];
  for(int i = 0 ; i < n ; i++){
    dv[i] = 0;
    ordre[i] = -1;
    pere[i] = -1;
    niveau[i] = -1;
  }

  /**
   * @brief Choix de la racine (ici 0)
   * 
   */
  int racine = 0;
  dv[racine] = 1;
  ordre[racine] = 1;
  pere[racine] = racine;
  niveau[racine] = 0;
  cout << "\n## PARCOURS EN LARGEUR " << endl;
  affichePL(-1, ordre[racine], pere[racine], niveau[racine]);
  
  /**
   * @brief Compteur pour dire à quel moment on a vu notre élément
   * 
   */
  int t = 2;

  /**
   * @brief on crée une file, puis on lui rajoute la racine
   * 
   */
  queue<int> AT;
  AT.push(racine);

  /**
   * @brief Tant que la file n'est pas vide
   * 
   */
  while( !AT.empty() ){
    
    int v = AT.front(); // on mémorise l'élement en haut de la file
    AT.pop(); // on l'enlève

    int size = (int)voisins[v].size();

    for( int i=0; i < size ; i++){

      int x = voisins[v][i];

      if ( dv[x] == 0 ){
        dv[x] = 1;
        AT.push(x);
        ordre[x] = t;
        t++;
        pere[x] = v;
        niveau[x] = niveau[v] + 1;

        affichePL(voisins[v][i], ordre[x], pere[x], niveau[x]);
      }
    }
  }
  delete[] dv;
}

/**
 * @brief On parcours l'arbre dans le sens de la profondeur
 * 
 * @param n 
 * @param voisins 
 * @param niveau 
 * @param ordre 
 * @param pere 
 */
void parcoursProfondeur(int n, vector<int> voisins[], int niveau[], int ordre[], int pere[]){

  /**
   * @brief On initialise dv
   * 
   */
  int* dv = new int[n];
  for(int i = 0 ; i < n ; i++){
    dv[i] = 0;
    ordre[i] = -1;
    pere[i] = -1;
    niveau[i] = -1;
  }

  /**
   * @brief Choix de la racine (ici 0)
   * 
   */
  int racine = 0;
  dv[racine] = 1;
  ordre[racine] = 1;
  pere[racine] = racine;
  niveau[racine] = 0;
  cout << "\n## PARCOURS EN PROFONDEUR " << endl;
  affichePL(-1, ordre[racine], pere[racine], niveau[racine]);
  
  /**
   * @brief Compteur pour dire à quel moment on a vu notre élément
   * 
   */
  int t = 2;

  /**
   * @brief on crée une file, puis on lui rajoute la racine
   * 
   */
  stack<int> AT;
  AT.push(racine);

  /**
   * @brief Tant que la file n'est pas vide
   * 
   */
  while( !AT.empty() ){
    
    int v = AT.top(); // on mémorise l'élement en haut de la file
    AT.pop(); // on l'enlève

    int size = (int)voisins[v].size();

    for( int i=0; i < size ; i++){

      int x = voisins[v][i];

      if ( dv[x] == 0 ){
        dv[x] = 1;
        AT.push(x);
        ordre[x] = t;
        t++;
        pere[x] = v;
        niveau[x] = niveau[v] + 1;

        affichePP(voisins[v][i], ordre[x], pere[x], niveau[x]);
      }
    }
  }

  delete[] dv;
}

int main() {
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

  voisinRandom(n, m, voisins);
  affichageAllVector(n, voisins);
  parcoursLargeur(n, voisins, niveau, ordre, pere);
  afficheNiveau(n, niveau);
  parcoursProfondeur(n, voisins, niveau, ordre, pere);
  afficheNiveau(n, niveau);

  return EXIT_SUCCESS;
}