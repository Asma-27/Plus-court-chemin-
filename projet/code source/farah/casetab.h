class casetab
{
  private:
  int  pos_col; 
  int  pos_lign; 
  char ponderation; 
  public:
  void setpos_col(int); 
  void setpos_lign(int);
  void setponderation(char);  
  char getponderation(); 
  int  getpos_col(); 
  int  getpos_lign(); 
  casetab operator=(casetab); 
  friend std::ostream & operator<< (std::ostream & o ,  casetab & c );
  friend std::istream & operator>>( std::istream  &input, casetab &c ) ;
  casetab(); 
  ~casetab(); 
};