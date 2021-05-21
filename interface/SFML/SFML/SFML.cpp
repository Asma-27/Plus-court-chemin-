#include <iostream>
#include <sstream> 
#include <stack>
#include <ostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/audio.hpp"
#include <locale>
#include <string.h>
#include <time.h>
#include "casetab.h"
#include "zone.h"
#include "graphe.h" 
#include <windows.h>
// effacer pour deuxieme fenetre 
// nombre d obstacle 10 ne veut pas s'executer 
// probleme 4 6
// collage du code de la partie obstacle ecrite 
using namespace std;
/****************  partie des case ****************/
ostream& operator<< (ostream& o, casetab& c)
{
    o << "(" << c.getpos_lign() << " ," << c.getpos_col() << ") " << endl;
    return o;
}
istream& operator>>(istream& input, casetab& c)
{
    input >> c.pos_col >> c.pos_lign >> c.ponderation;
    return input;
}
char casetab::getponderation()
{
    return(this->ponderation);

}
casetab::~casetab()
{
    
}
void casetab::setpos_col(int i)
{
    this->pos_col = i;
}
void casetab::setpos_lign(int j)
{
    this->pos_lign = j;
}
casetab::casetab()
{
    this->pos_col = 0; 
    this->pos_lign = 0; 
}
void casetab::setponderation(char ch)
{
    this->ponderation = ch;
}
int casetab::getpos_col()
{
    return(this->pos_col);
}
int casetab::getpos_lign()
{
    return(this->pos_lign);
}
casetab casetab::operator=(casetab c)
{
    this->pos_col = c.pos_col;
    this->pos_lign = c.pos_lign;
    this->ponderation = c.ponderation;
    return(*this);
}

/****************partie des zones ****************/
char zone::getponderation(int i, int j)
{
    return(this->matrice[i][j].getponderation());
}

void zone::setnombre_col(int i)
{
    this->nombre_col = i;
}
void zone::setnombre_lign(int i)
{
    this->nombre_lign = i;
}
void zone::setnombre_obs(int i)
{
    this->nombre_obs = i;
}
void zone::setpositioni(casetab c1)
{
    this->positioni = c1;
}
void zone::setpositionf(casetab c1)
{
    this->positionf = c1;
}
void zone::setmatrice(int i, int j, char p)
{
    if ((i > this->nombre_lign) || (j < nombre_col))
    {
        this->matrice[i][j].setponderation(p);
    }
    else
    {
        std::cout << "c est en dehors de la matrice veuillez refaire ";
    }
}
int zone::getnombre_col()
{
    return(this->nombre_col);
}
int zone::getnombre_lign()
{
    return(this->nombre_lign);
}
int zone::getnombre_obs()
{
    return(this->nombre_obs);
}
casetab zone::getpositioni()
{
    return(this->positioni);
}
casetab zone::getpositionf()
{
    return(this->positionf);
}
casetab zone::getmatrice(int i, int j)
{
    casetab c1;
    c1 = this->matrice[i][j];
    return(c1);
}
char zone::getmatrice2(int i, int j)
{
    char c1;
    c1 = this->matrice2[i][j];
    return(c1);
}
zone::zone(const zone& z)
{
    nombre_col = z.nombre_col;
    nombre_lign = z.nombre_lign;
    nombre_obs = z.nombre_obs;
    positioni = z.positioni;
    positionf = z.positionf;

    /*if (nombre_col > nombre_lign)
    {
        matrice = new casetab * [nombre_col];
        for (int s = 0; s < nombre_col; s++)
        {
            matrice[s] = new casetab[nombre_lign];
        }
    }
    else
    {
        matrice = new casetab * [nombre_lign];
        for (int s = 0; s < nombre_lign; s++)
        {
            matrice[s] = new casetab[nombre_col];
        }
    }*/
    //Code Solution
    matrice = new casetab * [99];
    for (int s = 0; s < nombre_lign; s++)
    {
        matrice[s] = new casetab[99];
    }

    for (int i = 0; i < nombre_lign; i++)
    {
        for (int j = 0; j < nombre_col; j++)
        {
            matrice[i][j] = z.matrice[i][j];
        }
    }
    matrice2 = new char* [nombre_col * nombre_lign];
    for (int u = 0; u < nombre_col * nombre_lign; u++)
    {
        matrice2[u] = new char[nombre_col * nombre_lign];
    }
    for (int i = 0; i < nombre_lign * nombre_col; i++)
    {
        for (int j = 0; j < nombre_col * nombre_lign; j++)
        {
            matrice2[i][j] = z.matrice2[i][j];
        }
    }
}

void zone::afficher_zone()
{
    //std::cout << "**************la representation de la grille**************" << endl;
    for (int u = 0; u < nombre_lign; u++)
    {
        for (int l = 0; l < nombre_col; l++)
        {
            char c = matrice[u][l].getponderation();
            //std::cout << c << " ";
        }
        std::cout << endl;
    }
}
bool zone::existe(casetab c)
{
    int col, lig;
    col = c.getpos_col();
    lig = c.getpos_lign();
    char o = matrice[lig][col].getponderation();
    if (o == 'v')
    {
        return(false);
    }
    else
    {
        return(true);
    }
}
int  zone::recherche(int p, int l)
{
    int** matrice3;
    int nbr = 0;
    //Code Solution
    matrice3 = new int* [99];
    for (int s = 0; s < 99; s++)
    {
        matrice3[s] = new int[99];
    }
    /*if (nombre_col > nombre_lign)
    {
        matrice3 = new int* [nombre_col];
        for (int s = 0; s < nombre_col; s++)
        {
            matrice3[s] = new int[nombre_lign];
        }
    }
    else
    {
        matrice3 = new int* [nombre_lign];
        for (int s = 0; s < nombre_lign; s++)
        {
            matrice3[s] = new int[nombre_col];
        }
    }*/
    for (int i = 0; i < nombre_lign; i++)
    {
        for (int j = 0; j < nombre_col; j++)
        {
            matrice3[i][j] = nbr;
            nbr = nbr + 1;
        }
    }
    return(matrice3[p][l]);
}
zone::zone(int l, int c, int o)
{
    int i, i1;
    int a, b;
    int j, j1, s;
    this->nombre_lign = l;
    this->nombre_col = c;
    while ((o > (c * l) - 2) && (o > 0))
    {
        std::cout << "donner une autre fois le nombre d'obstacle car vous avez depassez la surface de la  matrice ";
        cin >> o;
    }
    this->nombre_obs = o;
    //Code Solution
    alea = new casetab[99];
    matrice = new casetab * [99];
    for (s = 0; s < 99; s++)
    {
        matrice[s] = new casetab[99];
    }

    /*if (nombre_col > nombre_lign)
    {
        matrice = new casetab * [nombre_col];
        for (s = 0; s < nombre_col; s++)
        {
            matrice[s] = new casetab[nombre_lign];
        }
    }
    else
    {
        matrice = new casetab * [nombre_lign];
        for (s = 0; s < nombre_lign; s++)
        {
            matrice[s] = new casetab[nombre_col];
        }
    }*/
    //Code Solution
    matrice2 = new char* [99 * 99];
    for (int t = 0; t < 99 * 99; t++)
    {
        matrice2[t] = new char[99 * 99];
    }
    /*if (nombre_col > nombre_lign)
    {
        matrice2 = new char* [nombre_lign * nombre_col];
        for (int t = 0; t < nombre_col * nombre_lign; t++)
        {
            matrice2[t] = new char[nombre_col * nombre_lign];
        }
    }
    else
    {
        matrice2 = new char* [nombre_lign * nombre_col];
        for (int t = 0; t < nombre_col * nombre_lign; t++)
        {
            matrice2[t] = new char[nombre_col * nombre_lign];
        }
    }*/
    for (int u = 0; u < nombre_lign; u++)
    {
        for (int l = 0; l < nombre_col; l++)
        {
            matrice[u][l].setponderation('v');
        }
    }

    for (int y = 0; y < nombre_lign; y++)
    {
        for (int l = 0; l < nombre_col; l++)
        {
            matrice2[y][l] = 'v';
        }
    }
}
void zone::changer_matrice2()
{
    int nbr3 = 0;
    int i1 = -1;
    int j1 = 0;
    casetab c1;
    for (int j = 0; j < nombre_col * nombre_lign; j++)
    {
        if (nbr3 % nombre_col == 0)
        {
            j1 = 0;
            i1 = i1 + 1;
            c1 = this->getmatrice(i1, j1);
            matrice2[0][j] = c1.getponderation();
        }
        else
        {
            i1 = i1;
            j1 = j1 + 1;
            c1 = this->getmatrice(i1, j1);
            matrice2[0][j] = c1.getponderation();
        }
        nbr3 = nbr3 + 1;
    }
    for (int i = 1; i < nombre_col * nombre_lign; i++)
    {
        for (int j = 0; j < nombre_col * nombre_lign; j++)
        {
            matrice2[i][j] = matrice2[i - 1][j];
        }
    }
}
casetab* zone::liste_objet()
{
    casetab* tab;
    tab = new casetab[nombre_col * nombre_lign];
    int s = 0;
    for (int u = 0; u < nombre_lign; u++)
    {
        for (int l = 0; l < nombre_col; l++)
        {
            if (matrice[u][l].getponderation() == 'o')
            {
                s = s + 1;
                tab[s] = matrice[u][l];
                //std::cout << matrice[u][l];
            }
        }
    }
    return (tab);
}
casetab zone::recherche2(int c)
{
    int** matrice3;
    int nbr = 0;
    matrice3 = new int* [99];
    for (int s = 0; s < 99; s++)
    {
        matrice3[s] = new int[99];
    }

    for (int i = 0; i < nombre_lign; i++)
    {
        for (int j = 0; j < nombre_col; j++)
        {
            matrice3[i][j] = nbr;
            nbr = nbr + 1;

        }
    }
    int a;
    int b;
    casetab tab;
    for (int i = 0; i < nombre_lign; i++)
    {
        for (int j = 0; j < nombre_col; j++)
        {
            if (matrice3[i][j] == c)
            {
                tab.setpos_col(j);
                tab.setpos_lign(i);
            }
        }
    }


    return(tab);

}
casetab* zone::obstacles_alea(int c)
{

    for (int i = 0; i < c; i++)
    {
        alea[i] = this->modifier_alea_case();
        //cout << alea[i];
    }
    return(alea);
}
/*void zone::position_obs()
{
    char ch;
    int a, b;
    casetab c1;
    cout << "est ce que le positionnement va etre manuelle  " << endl;
    cout << "oui il suffit decrire o et non il suffit decrire n ";
    cin >> ch;
    if (ch == 'o')
    {
        for (int t = 0; t < this->nombre_obs; t++)
        {
            modifier_case(c1, 2, 2, 'o');
        }
    }
    else
    {
        for (int t = 0; t < this->nombre_obs; t++)
        {
            modifier_alea_case(c1);
        }
    }
}*/
zone::~zone()
{
    //delete[] matrice;
    delete[] matrice2;
}
bool  zone::modifier_case(casetab c, int i, int j, char a)
{
    bool test;
    c.setpos_lign(i);
    c.setpos_col(j);

    if (a == 'i')
    {

        matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setponderation('i');
        ili = c.getpos_lign();
        icol = c.getpos_col();
        test = true;
        
    }
    if (a == 'f')
    {
        matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setponderation('f');
        fli = c.getpos_lign();
        fcol = c.getpos_col();
        test = true;
        
    }
    if (a == 'o')
    {

        if (existe(c) == false)
        {
            test = true;
            matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
            matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
            matrice[c.getpos_lign()][c.getpos_col()].setponderation('o');
        }
        else
        {
            test = false;
        }

    }
    return(test);

}
casetab zone::modifier_alea_case()
{
    casetab c;
    c.setpos_col(rand() % this->nombre_col);
    c.setpos_lign(rand() % this->nombre_lign);
    while ((c.getpos_col() >= this->nombre_col) || (c.getpos_lign() >= this->nombre_lign) || (this->existe(c) == true))
    {
        c.setpos_col(rand() % this->nombre_col);
        c.setpos_lign(rand() % this->nombre_lign);
    }
    matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
    matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
    matrice[c.getpos_lign()][c.getpos_col()].setponderation('o');
    return(c);
}


/****************  partie  graphe     ****************/

graphe::graphe(int a, int b, zone z)
{
    this->dim = a * b;
    tableau = new casetab[99];
    graph = new int* [dim];
    for (int s = 0; s < dim; s++)
    {
        graph[s] = new int[dim];
    }
    int nbr = z.getnombre_col() - 1;
    int nbr2 = z.getnombre_col();
    int jinitial = 0;
    int iinitial = 0;
    //cout<<"******la representation de la grille par matrice *******"<<endl; 
    if (b != 1)
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (i == iinitial && j == jinitial + 1)
                {
                    if (jinitial == nbr)
                    {
                        graph[i][j] = 0;
                        nbr = nbr + z.getnombre_col();
                    }
                    else
                    {
                        if (z.getmatrice2(i, j) == 'o')
                        {
                            graph[i][j] = 0;
                        }
                        else
                        {
                            graph[i][j] = 1;
                        }
                    }
                }
                else
                {
                    if (i == iinitial && j == jinitial - 1)
                    {
                        if (jinitial == nbr2)
                        {
                            graph[i][j] = 0;
                            nbr2 = nbr2 + z.getnombre_col();
                        }
                        else
                        {
                            if (z.getmatrice2(i, j) == 'o')
                            {
                                graph[i][j] = 0;
                            }
                            else
                            {
                                graph[i][j] = 1;
                            }
                        }
                    }
                    else
                    {
                        if (i == iinitial - 1 && j == jinitial)
                        {
                            if (z.getmatrice2(i, j) == 'o')
                            {
                                graph[i][j] = 0;
                            }
                            else
                            {
                                graph[i][j] = 1;
                            }
                        }
                        else
                        {
                            if (i == iinitial && j == jinitial + z.getnombre_col())
                            {
                                if (z.getmatrice2(i, j) == 'o')
                                {
                                    graph[i][j] = 0;
                                }
                                else
                                {
                                    graph[i][j] = 1;
                                }
                            }
                            else
                            {
                                if (i == iinitial && j == jinitial - z.getnombre_col())
                                {
                                    if (z.getmatrice2(i, j) == 'o')
                                    {
                                        graph[i][j] = 0;
                                    }
                                    else
                                    {
                                        graph[i][j] = 1;
                                    }
                                }
                                else
                                {
                                    graph[i][j] = 0;
                                }
                            }
                        }
                    }
                }
                //cout<<graph[i][j]; 
            }
            //cout<<endl ; 
            iinitial = iinitial + 1;
            jinitial = jinitial + 1;
        }
    }
    else
    {
        iinitial = 0;
        jinitial = 0;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                if ((i == iinitial) && (j == jinitial + 1))
                {
                    if (z.getmatrice2(i, j) == 'o')
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        graph[i][j] = 1;
                    }

                }

                //cout<<graph[i][j]; 
            }
            //cout<<endl; 
            iinitial = iinitial + 1;
            jinitial = jinitial + 1;
        }
    }

}
graphe ::~graphe()
{
    delete[]graph;
}
int graphe::minimumDist(int dist[], bool Dset[])
{
    int min = 9999, index;     //9999 car c est plus infini normalement dans lalgorithme de dijekstra              
    for (int v = 0; v < dim; v++)
    {
        if (Dset[v] == false && dist[v] <= min)
        {
            min = dist[v];
            index = v;
        }
    }
    return(index);
}
int graphe::dijekstra(int src, zone z, int w, int v)
{
    stack<int> p;
    int* dist;
    dist = new int[dim];
    int* index;
    index = new int[dim];
    bool* Dset;
    Dset = new bool[dim];
    for (int i = 0; i < dim; i++)
    {
        dist[i] = 9999;
        Dset[i] = false;
        index[i] = 0;
    }
    dist[src] = 0;
    index[src] = 888888;
    for (int c = 0; c < dim; c++)
    {
        int u = minimumDist(dist, Dset);
        Dset[u] = true;
        for (int v = 0; v < dim; v++)
        {
            if (!Dset[v] && graph[u][v] && dist[u] != 9999 && dist[u] + graph[u][v] < dist[v])
            {
                int c1;
                c1 = graph[u][v];
                dist[v] = dist[u] + c1;
                index[v] = u;
            }
        }
    }
    int m = z.recherche(w, v);
    if (dist[m] == 9999)
    {
        //cout << "il n y a pas de chemin ";
        dist[m] = -1;
    }
    else
    {
        //cout << "****le chemin par les cases  est le suivant*****" << endl;
        int n = z.recherche(w, v);
        int i = 0;
        while (n != src)
        {
            p.push(n);
            n = index[n];
        }
        p.push(src);
        int nbr = p.size();
        //cout << "de la case initiale" << endl;
        while (p.size() != 0)
        {

            int c5 = p.top();
            //cout<<"le rang de la case est "<<c5;
            //cout<<" les coordonnées de la case est "; 

            if (p.size() == 1)
            {
                tableau[i] = z.recherche2(c5);
                p.pop();
                //cout << "vers la case finale" << endl;
            }
            else
            {
                tableau[i] = z.recherche2(c5);
                //cout << " " << " ↓↓" << endl;
                p.pop();
            }
            i = i + 1;

        }
        //cout << "***************************************" << endl;
        //cout << "la longeur du plus court chemin du point initial pour le robot vers le point final est :  " << dist[m] << endl;
        cout << endl;
    }
    return(dist[m]);
}
//String Cleaning..
std::vector<std::string> Clean(string input) {
    string ss = input;
    ss.erase(std::remove(ss.begin(), ss.end(), '\n'), ss.end());
    std::vector<std::string> result;
    std::istringstream iss(input);
    for (std::string input; iss >> input;) {
        result.push_back(input);
    }
    return result;
}


int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    sf::RenderWindow window({ 975 , 680 }, "ROBOT");
    std::string input_text = " ";
    std::string input_text1 = "";
    std::string input_text2 = " ";

    sf::Font font;
    font.loadFromFile("Raleway-Bold.ttf");
    sf::Text war1("!deja existant!", font, 15);
    sf::Text war2("!deja existant!", font, 15);
    sf::Text war3("!deja existant!", font, 15);
    sf::Text war4("!deja existant!", font, 15);
    sf::Text war5("!deja existant!", font, 15);
    sf::Text war6("!deja existant!", font, 15);
    sf::Text war7("!deja existant!", font, 15);
    sf::Text war8("!deja existant!", font, 15);
    sf::Text war9("!deja existant!", font, 15);
    sf::Text war10("!deja existant!", font, 15);
    sf::Text erreur("! nbr obs grand effacer et changer le !", font);
    sf::Text erreur2("! petite surface effacer et changer !", font);
    sf::Text erreur3("! cette position et deja occupeé  !", font);
    sf::Text erreur4("!vous etes sortie \n       du cadre!", font);
    sf::Text erreur5("!vous etes sortie \n       du cadre!", font);
    sf::Text erreur99("cle de la matrice ", font);
    sf::Text text("", font);
    sf::Text text1("", font);
    sf::Text text2("", font, 20);
    sf::Text t2("ENTRER LE NOMBRE DES COLONNES :", font);
    sf::Text t1("ENTRER LE NOMBRE DES LIGNES :", font);
    sf::Text t3("ENTRER LE NOMBRE DES OBSTACLES :", font);
    sf::Text t4("POSITIONNEMENT AUTOMATIQUE OUI OU NON (o/n) :", font);
    sf::Text titre(" Mettez les positions de vos obstacles ici :", font);
    sf::Text co1(" le 1 er  obstacle :", font);
    sf::Text co3(" le 3 eme obstacle :", font);
    sf::Text co5(" le 5 eme obstacle :", font);
    sf::Text co7(" le 7 eme obstacle :", font);
    sf::Text co9(" le 9 eme obstacle :", font);
    sf::Text co2(" le 2 eme obstacle :", font);
    sf::Text co4(" le 4 eme obstacle :", font);
    sf::Text co6(" le 6 eme obstacle :", font);
    sf::Text co8(" le 8 eme obstacle :", font);
    sf::Text co10("le 10 eme obstacle:", font);


    //page 
    int page = -1;
    bool mp = true;

    text.setFillColor(sf::Color(255, 0, 0));
    text1.setFillColor(sf::Color(255, 0, 0));
    text2.setFillColor(sf::Color(255, 0, 0));
    t1.setFillColor(sf::Color(0, 0, 0));
    t2.setFillColor(sf::Color(0, 0, 0));
    t3.setFillColor(sf::Color(0, 0, 0));
    t4.setFillColor(sf::Color(0, 0, 0));
    erreur.setFillColor(sf::Color(255, 0, 0));
    erreur2.setFillColor(sf::Color(255, 0, 0));
    erreur3.setFillColor(sf::Color(255, 0, 0));
    erreur4.setFillColor(sf::Color(255, 0, 0));
    erreur5.setFillColor(sf::Color(255, 0, 0));
    erreur99.setFillColor(sf::Color(255, 0, 0));
    war1.setFillColor(sf::Color(255, 0, 0));
    war2.setFillColor(sf::Color(255, 0, 0));
    war3.setFillColor(sf::Color(255, 0, 0));
    war4.setFillColor(sf::Color(255, 0, 0));
    war5.setFillColor(sf::Color(255, 0, 0));
    war6.setFillColor(sf::Color(255, 0, 0));
    war7.setFillColor(sf::Color(255, 0, 0));
    war8.setFillColor(sf::Color(255, 0, 0));
    war9.setFillColor(sf::Color(255, 0, 0));
    war10.setFillColor(sf::Color(255, 0, 0));
    titre.setFillColor(sf::Color(0, 0, 0));
    co1.setFillColor(sf::Color(225, 0, 0));
    co2.setFillColor(sf::Color(225, 0, 0));
    co3.setFillColor(sf::Color(225, 0, 0));
    co5.setFillColor(sf::Color(225, 0, 0));
    co7.setFillColor(sf::Color(225, 0, 0));
    co9.setFillColor(sf::Color(225, 0, 0));
    co4.setFillColor(sf::Color(225, 0, 0));
    co6.setFillColor(sf::Color(225, 0, 0));
    co10.setFillColor(sf::Color(225, 0, 0));
    co8.setFillColor(sf::Color(225, 0, 0));

    text.setPosition(160.f, 130.f);
    text1.setPosition(225.f, 210.f);
    text2.setPosition(110, 160.f);
    t1.setPosition(60.f, 79.f);
    t2.setPosition(60.f, 185.f);
    t3.setPosition(60.f, 291.f);
    t4.setPosition(60.f, 397.f);
    erreur.setPosition(340, 335);
    erreur2.setPosition(340, 235);
    erreur3.setPosition(260, 560);
    erreur4.setPosition(350, 200);
    erreur5.setPosition(350, 400);
    erreur99.setPosition(400,150);
    titre.setPosition(40, 30);
    war1.setPosition(300, 170);
    war2.setPosition(525, 170);
    war3.setPosition(300, 285);
    war4.setPosition(525, 285);
    war5.setPosition(300, 120);
    war6.setPosition(525, 120);
    war7.setPosition(300, 120);
    war8.setPosition(525, 120);
    war9.setPosition(300, 120);
    war10.setPosition(525, 120);
    co1.setPosition(60, 100);
    co3.setPosition(60, 215);
    co5.setPosition(60, 330);
    co7.setPosition(60, 445);
    co9.setPosition(60, 560);
    co2.setPosition(630, 100);
    co4.setPosition(630, 215);
    co6.setPosition(630, 330);
    co8.setPosition(630, 445);
    co10.setPosition(630, 560);





    //Cases
    sf::Texture  rt;
    rt.loadFromFile("case.png");
    sf::RectangleShape X1(sf::Vector2f(120, 50));
    X1.setSize(sf::Vector2f(90, 40));
    X1.setPosition(75.f, 155.f);
    X1.setTexture(&rt);

    sf::RectangleShape Y1(sf::Vector2f(120, 50));
    Y1.setSize(sf::Vector2f(90, 40));
    Y1.setPosition(185.f, 155.f);
    Y1.setTexture(&rt);

    sf::RectangleShape X2(sf::Vector2f(120, 50));
    X2.setSize(sf::Vector2f(90, 40));
    X2.setPosition(660.f, 155.f);
    X2.setTexture(&rt);

    sf::RectangleShape Y2(sf::Vector2f(120, 50));
    Y2.setSize(sf::Vector2f(90, 40));
    Y2.setPosition(770.f, 155.f);
    Y2.setTexture(&rt);

    sf::RectangleShape X3(sf::Vector2f(120, 50));
    X3.setSize(sf::Vector2f(90, 40));
    X3.setPosition(75.f, 270.f);
    X3.setTexture(&rt);

    sf::RectangleShape Y3(sf::Vector2f(120, 50));
    Y3.setSize(sf::Vector2f(90, 40));
    Y3.setPosition(185.f, 270.f);
    Y3.setTexture(&rt);

    sf::RectangleShape X4(sf::Vector2f(120, 50));
    X4.setSize(sf::Vector2f(90, 40));
    X4.setPosition(660.f, 270.f);
    X4.setTexture(&rt);

    sf::RectangleShape Y4(sf::Vector2f(120, 50));
    Y4.setSize(sf::Vector2f(90, 40));
    Y4.setPosition(770, 270.f);
    Y4.setTexture(&rt);

    sf::RectangleShape X5(sf::Vector2f(120, 50));
    X5.setSize(sf::Vector2f(90, 40));
    X5.setPosition(75.f, 385.f);
    X5.setTexture(&rt);

    sf::RectangleShape Y5(sf::Vector2f(120, 50));
    Y5.setSize(sf::Vector2f(90, 40));
    Y5.setPosition(185.f, 385);
    Y5.setTexture(&rt);

    sf::RectangleShape X7(sf::Vector2f(120, 50));
    X7.setSize(sf::Vector2f(90, 40));
    X7.setPosition(75.f, 500.f);
    X7.setTexture(&rt);

    sf::RectangleShape Y7(sf::Vector2f(120, 50));
    Y7.setSize(sf::Vector2f(90, 40));
    Y7.setPosition(185.f, 500);
    Y7.setTexture(&rt);

    sf::RectangleShape X9(sf::Vector2f(120, 50));
    X9.setSize(sf::Vector2f(90, 40));
    X9.setPosition(75.f, 615.f);
    X9.setTexture(&rt);

    sf::RectangleShape Y9(sf::Vector2f(120, 50));
    Y9.setSize(sf::Vector2f(90, 40));
    Y9.setPosition(185.f, 615.f);
    Y9.setTexture(&rt);

    sf::RectangleShape X6(sf::Vector2f(120, 50));
    X6.setSize(sf::Vector2f(90, 40));
    X6.setPosition(660.f, 385.f);
    X6.setTexture(&rt);

    sf::RectangleShape Y6(sf::Vector2f(120, 50));
    Y6.setSize(sf::Vector2f(90, 40));
    Y6.setPosition(770, 385.f);
    Y6.setTexture(&rt);

    sf::RectangleShape X8(sf::Vector2f(120, 50));
    X8.setSize(sf::Vector2f(90, 40));
    X8.setPosition(660.f, 500.f);
    X8.setTexture(&rt);

    sf::RectangleShape Y8(sf::Vector2f(120, 50));
    Y8.setSize(sf::Vector2f(90, 40));
    Y8.setPosition(770, 500.f);
    Y8.setTexture(&rt);

    sf::RectangleShape X10(sf::Vector2f(120, 50));
    X10.setSize(sf::Vector2f(90, 40));
    X10.setPosition(660.f, 615.f);
    X10.setTexture(&rt);

    sf::RectangleShape Y10(sf::Vector2f(120, 50));
    Y10.setSize(sf::Vector2f(90, 40));
    Y10.setPosition(770, 615.f);
    Y10.setTexture(&rt);

    sf::RectangleShape rect1(sf::Vector2f(120, 50));
    rect1.setSize(sf::Vector2f(220, 64));
    rect1.setPosition(60.f, 120.f);
    rect1.setTexture(&rt);

    sf::RectangleShape rect2(sf::Vector2f(120, 50));
    rect2.setSize(sf::Vector2f(220, 64));
    rect2.setPosition(60.f, 226.f);
    rect2.setTexture(&rt);

    sf::RectangleShape rect3(sf::Vector2f(120, 50));
    rect3.setSize(sf::Vector2f(220, 64));
    rect3.setPosition(60.f, 332.f);
    rect3.setTexture(&rt);

    sf::RectangleShape rect4(sf::Vector2f(120, 50));
    rect4.setSize(sf::Vector2f(220, 64));
    rect4.setPosition(60.f, 438.f);
    rect4.setTexture(&rt);

    //Background image
    sf::Texture bt;
    bt.loadFromFile("back.jpg");
    sf::Sprite Back(bt);

    //Submit Button
    sf::Texture subt;
    subt.loadFromFile("submit.png");
    sf::Sprite btn(subt);
    btn.setPosition(700.f, 530.f);

    sf::Vector2i position(700, 530);
    sf::Vector2i size(260, 100);
    sf::IntRect btnrect(position, size);
    int ox, oy;
    int cy, cx;
    //Submit button page 2
    sf::Vector2i position3(358, 550);
    sf::Vector2i size3(260, 100);
    sf::IntRect btnrect2(position3, size3);
    // texte position intiale 
    sf::Text initiale("ENTRER LES COORDONNEES DE LA POSITION INITIALE :", font);
    initiale.setFillColor(sf::Color(0, 0, 0));
    initiale.setPosition(60.f, 79.f);
    // texte position finale 
    sf::Text finale("ENTRER LES COORDONNEES DE LA POSITION FINALE :", font);
    finale.setFillColor(sf::Color(0, 0, 0));
    finale.setPosition(60.f, 300.f);
    //texte position X initiale 
    sf::Text X_I(" donner X ", font);
    X_I.setFillColor(sf::Color(255, 0, 0));
    X_I.setPosition(170.f, 150.f);
    X_I.setCharacterSize(24);
    // texte position y initiale 
    sf::Text Y_I(" donner Y ", font);
    Y_I.setFillColor(sf::Color(255, 0, 0));
    Y_I.setPosition(650.f, 150.f);
    Y_I.setCharacterSize(24);
    sf::Clock clock;
    // texte position X finale
    sf::Text X_F(" donner X ", font);
    X_F.setFillColor(sf::Color(255, 0, 0));
    X_F.setPosition(170.f, 357.f);
    X_F.setCharacterSize(24);
    // texte position Y finale 
    sf::Text Y_F(" donner Y ", font);
    Y_F.setFillColor(sf::Color(255, 0, 0));
    Y_F.setPosition(650.f, 357.f);
    Y_F.setCharacterSize(24);

    // case initiale 
    sf::RectangleShape rectI(sf::Vector2f(120, 50));
    rectI.setSize(sf::Vector2f(220, 64));
    rectI.setPosition(125.f, 200.f);
    rectI.setTexture(&rt);
    sf::RectangleShape rectF(sf::Vector2f(120, 50));
    rectF.setSize(sf::Vector2f(220, 64));
    rectF.setPosition(600.f, 200.f);
    rectF.setTexture(&rt);
    //case finale 
    sf::RectangleShape rectI2(sf::Vector2f(120, 50));
    rectI2.setSize(sf::Vector2f(220, 64));
    rectI2.setPosition(125.f, 410.f);
    rectI2.setTexture(&rt);
    sf::RectangleShape rectF2(sf::Vector2f(120, 50));
    rectF2.setSize(sf::Vector2f(220, 64));
    rectF2.setPosition(600.f, 410.f);
    rectF2.setTexture(&rt);
    //Page 3 Grille..
    sf::RectangleShape Grille[10][10];
    sf::Texture box;
    box.loadFromFile("box.png");
    int gx = 50, gy = 50, box_size = 100;
    //Robot
    sf::Texture ro;
    ro.loadFromFile("robot.png");
    sf::Sprite robot(ro);
    int ix, iy;
    //Finsih
    sf::Texture ff;
    ff.loadFromFile("finish.png");
    sf::Sprite finish(ff);

    int fx, fy;
    // obstacle 
    sf::Texture oo;
    oo.loadFromFile("obstacle.png");
    sf::Sprite obstacle(oo);

    //chemin 
    sf::Texture cc;
    cc.loadFromFile("localisation.png");
    sf::Sprite chemin(cc);
    chemin.setColor(sf::Color(255, 255, 255, 30));
    //Finsih Button
    sf::Texture fint;
    fint.loadFromFile("finish_button.png");
    sf::Sprite fbtn(fint);
    fbtn.setPosition(700.f, 530.f);

    sf::Vector2i position2(700, 530);
    sf::Vector2i size2(260, 100);
    sf::IntRect fbtnrect(position2, size2);
    //Music
    sf::Music music;
    if (!music.openFromFile("song.ogg"))
        return -1; // erreur

    sf::Texture mt;
    mt.loadFromFile("mute.png");

    sf::Texture mbtn;
    mbtn.loadFromFile("msb.png");
    sf::Sprite msb(mt);
    msb.setPosition(850.f, 30.f);

    sf::Vector2i position4(850.f, 30.f);
    sf::Vector2i size4(60, 60);
    sf::IntRect mbtnrect(position4, size4);
    //INTRO 
    sf::Text intro("Coucou, coucou,\nNotre petit robot,Est perdu dans un lot,\nEt pour sortir le plus tôt,\nVous pouvez l’aider pour qu’il ne soit pas solo,\nPar le choix de nombre d’obstacles,\nlignes et colonnes de ce lot,\nPuis par notre magie le robot,\nArrivera à son boulot,\nSans toucher  les sabots.",font);
    intro.setCharacterSize(26);
    intro.setFillColor(sf::Color::Black);
    intro.setPosition(sf::Vector2f(360, 180));

    sf::Texture txtintro;
    txtintro.loadFromFile("robot-intro.png");
    sf::Sprite imgint(txtintro);
    imgint.setPosition(sf::Vector2f(50, 150));

    sf::Texture blb;
    blb.loadFromFile("dialog.png");
    sf::Sprite dialog(blb);
    dialog.setPosition(sf::Vector2f(250, 40));

    sf::Text diatxt("Aidez Moi!", font);
    diatxt.setCharacterSize(26);
    diatxt.setFillColor(sf::Color::Black);
    diatxt.setPosition(sf::Vector2f(270, 90));

    //NO SOLUTION 
    sf::Text solu("          Desolé,\nPas De Solution !! ", font);
    solu.setCharacterSize(24);
    solu.setFillColor(sf::Color::Red);
    solu.setPosition(sf::Vector2f(720, 300));

    
    //VARs

    int a = 99;
    int b = 99;
    int c = 0;

    bool b1 = 0;
    bool b2 = 0;
    bool b4 = 0;
    int start = 0;

    int nb = 1;
    int nb1 = 1;
    int nb2 = 0;

    int a1 = 97;
    int b12 = 97;
    int c1 = 96;
    int d1 = 96;

    bool g1 = 1;
    bool g2 = 1;
    bool g3 = 1;
    bool g4 = 1;
    bool g5 = 1;
    bool g6 = 1;
    bool g7 = 1;
    bool g8 = 1;
    bool g9 = 1;
    bool g10 = 1;

    bool ee = 1;
    bool aa = 1;
    bool bb = 1;
    bool ccc = 1;
    bool dd = 1;
    bool fff = 1;
    bool jj = 1;
    bool gg = 1;
    bool hh = 1;
    bool ii = 1;



    string case4;

    int obsx;
    int obsy;
    int chemx;
    int chemy;
    bool test = true;
    bool test2 = true;
    bool ready = false;
    bool b3 = false;

    std::vector<std::string> result3;
    sf::Vector2i pos;
    bool ispressed = false;
    //bool efface = true;

    int* obstacles = new int[80];
    for (int i = 0; i < 80; i++)
    {
        obstacles[i] = 95;
    }

    zone z(a, b, c);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (std::isprint(event.text.unicode))
                {
                    if (page == 1)
                    {
                        input_text1 += event.text.unicode;
                    }
                    else if (page == 0)
                    {
                        input_text += event.text.unicode;
                    }
                    else if (page == 2)
                    {
                        input_text2 += event.text.unicode;
                    }
                }

            }
            else if (event.type == sf::Event::KeyPressed)
            {
                //ENTER
                if (event.key.code == sf::Keyboard::Return)
                {
                    //Page 0 Inputs..
                    if (page == 0)
                    {

                        input_text += " \n \n \n ";
                        nb++;
                        if (nb == 5) {
                            std::vector<std::string> result1 = Clean(input_text);
                            a = std::stoi(result1[0]);
                            b = std::stoi(result1[1]);
                            if (a * b < 4)
                            {
                                test2 = false;
                            }
                            else
                            {
                                test2 = true;
                            }
                            c = std::stoi(result1[2]);
                            if (c > a * b - 2)
                            {
                                test = false;
                            }
                            else
                            {
                                test = true;
                            }
                            case4 = result1[3];

                        }
                    }
                    //Page 1 Inputs.
                    else if (page == 1)
                    {
                        nb1++;
                        if (nb1 == 2) {
                            input_text1 += "                      ";
                            input_text1 += "                      ";
                            input_text1 += "                      ";
                        }
                        if (nb1 == 3) {
                            input_text1 += " \n \n \n \n \n \n ";
                        }
                        if (nb1 == 4) {
                            input_text1 += "                      ";
                            input_text1 += "                      ";
                            input_text1 += "                      ";
                        }
                        if (nb1 == 5) {
                            std::vector<std::string> result2 = Clean(input_text1);
                            a1 = std::stoi(result2[0]);
                            b12 = std::stoi(result2[1]);
                            c1 = std::stoi(result2[2]);
                            d1 = std::stoi(result2[3]);
                        }
                    }
                    //Page 2 Inputs
                    else if (page == 2 && nb2 < c * 2 + 1)
                    {

                        nb2++;
                        //Test For 14 cases cad 7 obstacles
                        if (nb2 % 2 == 1) {
                            input_text2 += "                    ";
                        }
                        if (nb2 % 4 == 2) {
                            input_text2 += "                                                                                             ";
                        }
                        if (nb2 % 4 == 0) {
                            input_text2 += " \n \n \n \n \n ";
                        }

                        if (nb2 == c * 2) {
                            result3 = Clean(input_text2);
                            for (int i = 0; i < result3.size(); i++) {
                                obstacles[i] = std::stoi(result3[i]);
                                //std::cout << obstacles[i] << endl;
                            }
                        }
                    }
                }
                //ESCAPE
                if (event.key.code == sf::Keyboard::Escape)
                {
                    if (page == 0) {
                        nb = 1;
                        input_text = " ";
                    }
                    else if (page == 1) {
                        nb1 = 1;
                        input_text1 = " ";
                    }
                    else if (page == 2) {
                        nb2 = 0;
                        b3 = 0;
                        input_text2 = " ";
                        ee = 1;
                        aa = 1;
                        bb = 1;
                        ccc = 1;
                        dd = 1;
                        fff = 1;
                        jj = 1;
                        gg = 1;
                        hh = 1;
                        ii = 1;
                        g1 = 1;
                        g2 = 1;
                        g3 = 1;
                        g4 = 1;
                        g5 = 1;
                        g6 = 1;
                        g7 = 1;
                        g8 = 1;
                        g9 = 1;
                        g10 = 1;
                        for (int i = 0; i < 80; i++)
                        {
                            obstacles[i] = 95;
                        }
                        zone z = z;
                        /*char cic = z.getmatrice(2, 2).getponderation();
                        for (int i = 0; i < result3.size() - 1; i++) {
                            
                        }*/
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    pos = sf::Mouse::getPosition(window);
                    ispressed = true;
                    b1 = btnrect.contains(pos);
                    b4 = mbtnrect.contains(pos);
                    if (page == 3) {
                        b2 = fbtnrect.contains(pos);
                    }
                    if (page == 2) {
                        b3 = btnrect2.contains(pos);
                    }
                    if (b4 == 1 && start % 2 == 0) {
                        msb.setTexture(mbtn);

                        music.play();
                        start++;
                    }
                    else if (b4 == 1 && start % 2 != 0) {
                        msb.setTexture(mt);
                        music.stop();
                        start++;
                    }
                }
            }
        }
        //Cursor
        static sf::Time text_effect_time;
        static bool show_cursor;
        text_effect_time += clock.restart();
        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }
        //Remove Cursor in the end.
        if (nb == 5)
        {
            text.setString(input_text);
        }
        else
        {
            text.setString(input_text + (show_cursor ? '_' : ' '));
        }
        //page 1 curseur 
        if (nb1 == 5)
        {
            text1.setString(input_text1);
        }
        else
        {
            text1.setString(input_text1 + (show_cursor ? '_' : ' '));
        }
        //page 2  curseur 
        if (nb2 == 2 * c)
        {
            text2.setString(input_text2);
        }
        else
        {
            text2.setString(input_text2 + (show_cursor ? '_' : ' '));
        }
        //test de ne pas entrer la meme valeur pour initiale et finale 
        bool test4 = false;
        if (a1 == c1 && nb1 == 5)
        {

            if (b12 == d1)
            {

                test4 = true;
            }
            else
            {
                test4 = false;
            }
        }
        else
        {
            test4 = false;

        }
        //tester le nombre ligne col de initiale 
        bool test5 = false;
        if ((a1 >= a || b12 >= b) && (a1 != 97 && b12 != 97))
        {
            test5 = true;
        }
        // tester le nombre ligne col finale 
        bool test6 = false;
        if ((c1 >= a || d1 >= b) && (c1 != 96 && d1 != 96))
        {
            test6 = true;
        }

        //Game Render
        //__Page 1..

        if (b1 == 1 && page == 1 && nb == 5)
        {
            window.clear();
            z.setnombre_col(b);
            z.setnombre_lign(a);
            z.setnombre_obs(c);
            window.draw(Back);
            window.draw(initiale);
            window.draw(finale);
            window.draw(X_I);
            window.draw(Y_I);
            window.draw(X_F);
            window.draw(Y_F);
            window.draw(rectI);
            window.draw(rectF);
            window.draw(rectI2);
            window.draw(rectF2);
            if (test4 == true)
            {
                window.draw(erreur3);
            }
            if (test5 == true)
            {
                window.draw(erreur4);
            }
            else
            {

                casetab p;
                z.modifier_case(p, a1, b12, 'i');
            }

            if (test6 == true)
            {
                window.draw(erreur5);
            }
            else
            {
                //Code Fonctionelle..
                casetab p2;
                z.modifier_case(p2, c1, d1, 'f');
            }
            //z.afficher_zone();
            if (nb1 == 5 && test4 == false && test5 == false && test6 == false)
            {
                window.draw(btn);
            }
            if (ispressed == true && nb1 == 5) 
            {
                page += 1;
                if ((case4 == "o") ||(c==0)) 
                {
                    page++;
                    cout << page;
                }
            }
            window.draw(text1);
            window.draw(msb);
            window.display();
        }
        //__Page 2..
        else if ((page == 2) && (case4 == "n") && (c!=0))
        {
            window.clear();
            window.draw(Back);
            window.draw(titre);
            window.draw(msb);


            if (c >= 1)
            {
                window.draw(co1);
                window.draw(X1);
                window.draw(Y1);
                window.draw(text2);
                casetab p3;
                if (g1 == true && obstacles[0] != 95 && obstacles[1] != 95) {
                    
                    ee = z.modifier_case(p3, obstacles[0], obstacles[1], 'o');
                    g1 = false;
                }
                if (c >= 2)
                {
                    window.draw(co2);
                    window.draw(X2);
                    window.draw(Y2);
                    
                    casetab p4;
                    if (g2 == true && obstacles[2] != 95 && obstacles[3] != 95) {
                        
                        aa = z.modifier_case(p4, obstacles[2], obstacles[3], 'o');
                        g2 = false;
                    }
                    if (c >= 3)
                    {
                        window.draw(co3);
                        window.draw(X3);
                        window.draw(Y3);
                        
                        if (g3 == true && obstacles[4] != 95 && obstacles[5] != 95) {
                            casetab p5;
                            bb = z.modifier_case(p5, obstacles[4], obstacles[5], 'o');
                            g3 = 0;
                        }
                        if (c >= 4)
                        {
                            window.draw(co4);
                            window.draw(X4);
                            window.draw(Y4);
                            
                            if (g4 == true && obstacles[6] != 95 && obstacles[7] != 95) {
                                casetab p6;
                                ccc = z.modifier_case(p6, obstacles[6], obstacles[7], 'o');
                                g4 = 0;
                            }
                            if (c >= 5)
                            {
                                window.draw(co5);
                                window.draw(X5);
                                window.draw(Y5);
                                
                                
                                if (g5 == true && obstacles[8] != 95 && obstacles[9] != 95) {
                                    casetab p7;
                                    dd = z.modifier_case(p7, obstacles[8], obstacles[9], 'o');
                                    g5 = 0;
                                }
                                if (c >= 6)
                                {
                                    window.draw(co6);
                                    window.draw(X6);
                                    window.draw(Y6);
                                    
                                    if (g6 == true && obstacles[10] != 95 && obstacles[11] != 95) {
                                        casetab p8;
                                        fff = z.modifier_case(p8, obstacles[10], obstacles[11], 'o');                                       
                                        g6 = 0;
                                    }
                                    
                                    if (c >= 7)
                                    {
                                        window.draw(X7);
                                        window.draw(Y7);
                                        window.draw(co7);
                                        
                                        if (g7 == true && obstacles[12] != 95 && obstacles[13] != 95) {
                                            casetab p9;
                                            ii = z.modifier_case(p9, obstacles[12], obstacles[13], 'o');
                                            g7 = 0;
                                        }
                                        
                                        if (c >= 8)
                                        {
                                            window.draw(co8);
                                            window.draw(X8);
                                            window.draw(Y8);
                                            
                                            if (g8 == true && obstacles[13] != 95 && obstacles[14] != 95) {
                                                casetab p10;
                                                jj = z.modifier_case(p10, obstacles[13], obstacles[14], 'o');
                                                g8 = 0;
                                            }
                                            if (c >= 9)
                                            {
                                                window.draw(X9);
                                                window.draw(Y9);
                                                window.draw(co9);
                                                
                                                if (g9 == true && obstacles[15] != 95 && obstacles[16] != 95) {
                                                    casetab p11;
                                                    gg = z.modifier_case(p11, obstacles[15], obstacles[16], 'o');
                                                    g9 = 0;
                                                }
                                                if (c >= 10)
                                                {
                                                    
                                                    if (g10 == true && obstacles[16] != 95 && obstacles[17] != 95) {
                                                        casetab p12;
                                                        hh = z.modifier_case(p12, obstacles[16], obstacles[17], 'o');
                                                        g10 = 0;
                                                    }  
                                                    window.draw(co10);
                                                    window.draw(X10);
                                                    window.draw(Y10);
                                                    window.draw(war10);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (ee == false)
            {
                window.draw(war1);
            }
            if (aa == false)
            {
                window.draw(war2);
            }
            if (bb == false)
            {
                window.draw(war3);
            }
            if (ccc == false)
            {
                window.draw(war4);
            }
            if (dd == false)
            {
                window.draw(war5);
            }
            if (fff == false)
            {
                window.draw(war6);
            }
            if (ii == false)
            {
                window.draw(war7);
            }
            if (jj == false)
            {
                window.draw(war8);
            }
            if (gg == false)
            {
                window.draw(war9);
            }
            if (hh  == false)
            {
                window.draw(war10);
            }
            if (nb2 == c * 2) {
                if (ee == 1 && aa == 1 && bb == 1 && ccc == 1 && dd == 1 && fff == 1 && ii == 1 && jj == 1 && gg == 1 && hh == 1) {
                    btn.setPosition(sf::Vector2f(358, 550));
                    window.draw(btn);
                    if (b3 == 1) {
                        page++;
                    }
                }
            }
            window.display();
        }
        //__Page 0..
        else if (page == 0)
        {
            window.clear();
            window.draw(Back);
            window.draw(rect1);
            window.draw(rect2);
            window.draw(rect3);
            window.draw(rect4);
            window.draw(t1);
            window.draw(t2);
            if (test2 == false)
            {
                window.draw(erreur2);
            }
            window.draw(t3);
            window.draw(t4);
            if (test == false)
            {
                window.draw(erreur);
            }
            window.draw(text);
            window.draw(msb);
            if (test == true && nb == 5 && test2 == true)
            {
                window.draw(btn);

            }
            /*if( (( nb==5) && (case4 != "n"))|| ((nb == 5) && (case4 != "o")))
            {
                cout << case4; 
                window.draw(erreur99); 
            }*/
            window.display();
            if (b1 == true) {
                page += 1;
            }
        }
        //__Page 3
        else if (b3 == 1 || page == 3)
        {

            if (case4 == "n")
            {
                window.clear();
                window.draw(Back);
                window.draw(msb);
                for (int i = 0; i < a; i++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        casetab rr = z.getmatrice(i, j);
                        Grille[i][j].setSize(sf::Vector2f(100, 100));
                        Grille[i][j].setPosition(gx, gy);
                        Grille[i][j].setTexture(&box);
                        ix = Grille[a1][b12].getPosition().x;
                        iy = Grille[a1][b12].getPosition().y;
                        robot.setPosition(sf::Vector2f(ix + 20, iy + 20)); // Variable : box position + 20..
                        fx = Grille[c1][d1].getPosition().x;
                        fy = Grille[c1][d1].getPosition().y;
                        finish.setPosition(sf::Vector2f(fx + 20, fy + 20));//VAR
                        if (rr.getponderation() == 'o')
                        {
                            ox = rr.getpos_lign();
                            oy = rr.getpos_col();
                            obsx = Grille[ox][oy].getPosition().x;
                            obsy = Grille[ox][oy].getPosition().y;
                            obstacle.setPosition(sf::Vector2f(obsx + 20, obsy + 20));
                        }
                        window.draw(Grille[i][j]);
                        if (c != 0)
                        {
                            window.draw(obstacle);
                        }

                        /************************/
                        z.changer_matrice2();
                        graphe g(a, b, z);
                        int m = z.recherche(z.ili, z.icol);
                        //std::cout << m << endl;
                        int w = z.fli;
                        int x = z.fcol;
                        int k = g.dijekstra(m, z, w, x);
                        if (k == -1) 
                        {
                            window.draw(solu);
                            window.draw(robot);
                            window.draw(finish);

                        }

                        for (int i = 0; i < k + 1; i++)
                        {
                            cx = g.tableau[i].getpos_lign();
                            cy = g.tableau[i].getpos_col();
                            chemx = Grille[cx][cy].getPosition().x;
                            chemy = Grille[cx][cy].getPosition().y;
                            chemin.setPosition(sf::Vector2f(chemx + 20, chemy + 20));
                            char ch = z.getponderation(cx, cy);
                            if (ch == 'v')
                            {
                                window.draw(chemin);
                            }
                            window.draw(finish);
                            window.draw(robot);

                        }
                        gx += box_size - 26;
                    }
                    gx = 50;
                    gy += box_size - 26;
                }
                gy = 50;
                
                window.draw(fbtn);
                if (b2 == 1) {
                    window.close();
                }

                window.display();
            }
            else if (case4 == "o")
            {
                window.clear();
                window.draw(Back);

                for (int i = 0; i < a; i++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        casetab rr = z.getmatrice(i, j);
                        Grille[i][j].setSize(sf::Vector2f(100, 100));
                        Grille[i][j].setPosition(gx, gy);
                        Grille[i][j].setTexture(&box);
                        ix = Grille[a1][b12].getPosition().x;
                        iy = Grille[a1][b12].getPosition().y;
                        robot.setPosition(sf::Vector2f(ix + 20, iy + 20)); // Variable : box position + 20..
                        fx = Grille[c1][d1].getPosition().x;
                        fy = Grille[c1][d1].getPosition().y;
                        finish.setPosition(sf::Vector2f(fx + 20, fy + 20));//VAR

                        if (mp == true)
                        {
                            z.obstacles_alea(c);
                            mp = false;
                        }

                        if (rr.getponderation() == 'o')
                        {
                            ox = rr.getpos_lign();
                            oy = rr.getpos_col();
                            obsx = Grille[ox][oy].getPosition().x;
                            obsy = Grille[ox][oy].getPosition().y;
                            obstacle.setPosition(sf::Vector2f(obsx + 20, obsy + 20));
                        }
                        window.draw(Grille[i][j]);
                        if (c != 0)
                        {
                            window.draw(obstacle);
                           
                        }
                        
                        z.changer_matrice2();
                        graphe g(a, b, z);
                        int m = z.recherche(z.ili, z.icol);
                        //std::cout << m << endl;
                        int w = z.fli;
                        int x = z.fcol;
                        int k = g.dijekstra(m, z, w, x);
                        if (k == -1) 
                        {
                            window.draw(solu);
                            window.draw(robot);
                            window.draw(finish);
                        }
                        for (int i = 0; i < k + 1; i++)
                        {
                            cx = g.tableau[i].getpos_lign();
                            cy = g.tableau[i].getpos_col();
                            chemx = Grille[cx][cy].getPosition().x;
                            chemy = Grille[cx][cy].getPosition().y;
                            chemin.setPosition(sf::Vector2f(chemx + 20, chemy + 20));
                            char ch = z.getponderation(cx, cy);
                            if (ch == 'v')
                            {
                                window.draw(chemin);
                            }
                            window.draw(finish);
                            window.draw(robot);
                        }
                        gx += box_size - 26;
                    }
                    gx = 50;
                    gy += box_size - 26;
                }
                gy = 50;
                window.draw(fbtn);


                if (b2 == 1) {
                    window.close();
                }
                window.display();
            }
        }
        //__Page Intro
        else if (page == -1) {
            window.clear();
            window.draw(Back);
            window.draw(imgint);
            window.draw(intro);
            window.draw(btn);
            window.draw(dialog);
            window.draw(diatxt);
            window.draw(msb);
            if (b1 == 1) {
                b1 = 0;
                page++;
            }
            window.display();
        }
        //Transition Fix
        if (page != 0)
        {
            ispressed = false;
        }
    }
}