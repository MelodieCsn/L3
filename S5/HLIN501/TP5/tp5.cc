#include <iostream>
#include <vector>

using namespace std;

const int N=6;
const int INF=9999;                      //La valeur infinie.    

void floydWarshall(int longueur[][N],int dist[][N],int chemin[][N]){
    for(int i=0; i<N; i++){
      dist[i][i]=0;
      chemin[i][i]=i;
      for(int j=0;j<N;j++){
        if(longueur[i][j]<INF){
          dist[i][j]=longueur[i][j];
          chemin[i][j]=j;
        }
        else{
          dist[i][j]=INF;
          chemin[i][j]=-1;
        }
      }
    }
    for(int k=0;k<N;k++){
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(dist[i][j]>dist[i][k]+dist[k][j]){
            dist[i][j]=dist[i][k]+dist[k][j];
            chemin[i][j]=chemin[i][k];
          }
        }
      }
    }
    for(int i=0; i<N; i++){
      if(dist[i][i]){
        cout<<"Il existe un cycle orienté de poids <0"<<endl;
      }
    }
  }
void affichage(int dist[][N],int chemin[][N]){
  int n = N;
	for(int i = 0 ; i < n ; i++){
		cout << "{";
		for(int j = 0 ; j < n ; j++){
			cout << chemin[i][j] << " ";
		}
		cout << "\b}" << endl;
	}
}
void itineraire(int i,int j,int chemin[][N]){
  
	int next = i;
	cout << "Depart: " << i << endl;
	cout << "Destination: " << j << endl;
	cout << "Itineraire: " << i << " ";

	while(next != j && next != -1){
		next = chemin[next][j];

		if(next != -1)
			cout << next << " ";
		else
			cout << endl << "Chemin impossible, réexecutez le programme pour faire un nouveau tirage des arcs";
	}
	cout << endl;
}

void fermetureTransitive(int arc[][N], int fermeture[][N]){

	int n = N;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			fermeture[i][j] = arc[i][j];
		}
	}

	for(int k = 0; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(arc[i][k] && arc[k][j]){
         			fermeture[i][j] = 1; 
      			}
  			}
		}
	}
}


void printfermeture(int fermeture[][N]){
	
	int n = N;
	for(int i = 0 ; i < n ; i++){
		cout << "{";
		for(int j = 0 ; j < n ; j++){
			cout << fermeture[i][j] << " ";
		}
		cout << "\b}" << endl;
	}
}

void compFortConnexe(int n, int fermeture[][N]){
  vector<int> comp[n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
          if ((fermeture[i][j] == 1) && (fermeture[j][i] == 1))
          {
              comp[i].push_back(j);
          }
      }
    }
    cout<<"Les composantes fortements connexes sont :";
    for (int i = 0; i < n; i++)
    {
        // On regarde si le sommet est une source
        if ( fermeture[i][i] == 0 ){
          cout << "{" << i << "} ";   
        }

        if (!comp[i].empty() && (comp[i][0] >= i))
        {
            cout<<"{ ";
            for (int j = 0; j < comp[i].size(); j++)
            {
                cout << comp[i][j] << " ";
            }
            cout<<"}";
        }
    }
    cout << endl;
}


int
main()
{

  int longueur[N][N]={{0,2,INF,4,INF},   //Les longueurs des arcs.
		      {INF,0,2,INF,INF}, //longueur[i][j]=INF si l'arc ij n'existe pas
		      {INF,INF,0,2,INF},
		      {INF,-3,INF,0,2},
		      {2,INF,INF,INF,0}};                
  int dist[N][N];            //Le tableau des distances.
  int chemin[N][N];         //Le tableau de la premiere etape du chemin de i a j.
  int arc[N][N]={{0,0,0,1,0,1},
                 {1,0,1,1,0,0},
                 {0,0,0,1,0,0},
                 {0,0,0,0,1,1},
                 {0,0,1,0,0,1},
                 {0,0,1,0,0,0}};
  int fermeture[N][N];



  // floydWarshall(longueur,dist,chemin); METTRE N=5 POUR LES UTILISER
  // affichage(dist,chemin);  
  // itineraire(0,4,chemin);
  fermetureTransitive(arc,fermeture);
  printfermeture(fermeture);
  compFortConnexe(N,fermeture);

  return EXIT_SUCCESS;
}
