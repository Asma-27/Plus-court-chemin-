class zone
{
  private:
  int  nombre_col ; 
  int  nombre_lign; 
  int  nombre_obs;  
  casetab positioni;
  casetab positionf; 
  casetab** matrice; 
  char** matrice2; 
  public:
  int ili;
  int icol;  
  int fli;
  int fcol;
  zone(int ,int ,int ); 
  ~zone();  
  zone (const zone &); 
  zone operator=(zone); 
  int getnombre_col(); 
  int getnombre_lign(); 
  int getnombre_obs(); 
  char getmatrice2(int, int ); 
  casetab getpositioni(); 
  casetab getpositionf(); 
  casetab getmatrice(int ,int );
  void  setnombre_col(int); 
  void  setnombre_lign(int); 
  void  setnombre_obs(int ); 
  void  setpositioni(casetab); 
  void  setpositionf(casetab); 
  void  setmatrice(int ,int ,char  );
  void  position_obs();  
  void  modifier_case(casetab,char); 
  void  modifier_alea_case(casetab); 
  void  afficher_zone(); 
  bool  existe (casetab);
  casetab* liste_objet(); 
  void changer_matrice2(); 
  int recherche(int ,int ); 
  void  recherche2(int ); 
  //la matrice est constituée par les casses de plus la ponderation est faite par v=vide , i=initial, f=final, o=obstacle 
}; 