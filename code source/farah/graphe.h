class graphe 
{
  int** graph ;
  int dim;   
  public : 
  graphe(int ,int ,zone ); 
  ~graphe();
  graphe (const graphe &); 
  void dijekstra(int,zone,int ,int); 
  int minimumDist(int dist[], bool Dset[]); 
}; 