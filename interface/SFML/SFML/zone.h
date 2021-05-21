#pragma once
#include <stack>
class zone
{
private:
	int  nombre_col;
	int  nombre_lign;
	int  nombre_obs;
	casetab positioni;
	casetab positionf;
	casetab** matrice;
	char** matrice2;
public:
	casetab* alea;
	int ili;
	int icol;
	int fli;
	int fcol;
	zone();
	zone(int, int, int);
	~zone();
	zone(const zone&);
	zone operator=(zone);
	char getponderation(int, int);
	int getnombre_col();
	int getnombre_lign();
	int getnombre_obs();
	casetab getpositioni();
	casetab getpositionf();
	casetab getmatrice(int, int);
	casetab* obstacles_alea(int);
	char getmatrice2(int i, int j);
	void  setnombre_col(int);
	void  setnombre_lign(int);
	void  setnombre_obs(int);
	void  setpositioni(casetab);
	void  setpositionf(casetab);
	void  setmatrice(int, int, char);
	void  position_obs();
	bool  modifier_case(casetab, int, int, char);
	casetab modifier_alea_case();
	void  afficher_zone();
	bool  existe(casetab);
	casetab* liste_objet();
	void changer_matrice2();
	int recherche(int, int);
	casetab recherche2(int);
	//la matrice est constituée par les casses de plus la ponderation est faite par v=vide , i=initial, f=final, o=obstacle 
};