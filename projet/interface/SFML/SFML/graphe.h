#pragma once
class graphe
{
	int** graph;
	int dim;
public:
	casetab* tableau;
	graphe(int, int, zone);
	~graphe();
	graphe(const graphe&);
	int  dijekstra(int, zone, int, int);
	int minimumDist(int dist[], bool Dset[]);
};