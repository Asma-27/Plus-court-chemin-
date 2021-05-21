#include <iostream>
#include <stack>
#include <ostream>
#include "casetab.h"
#include "zone.h"
#include "graphe.h"
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
        cout << "c est en dehors de la matrice veuillez refaire ";
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
    if (nombre_col > nombre_lign)
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
    cout << "**************la representation de la grille**************" << endl;
    for (int u = 0; u < nombre_lign; u++)
    {
        for (int l = 0; l < nombre_col; l++)
        {
            char c = matrice[u][l].getponderation();
            cout << c << " ";
        }
        cout << endl;
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
    if (nombre_col > nombre_lign)
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
    }
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
        cout << "donner une autre fois le nombre d'obstacle car vous avez depassez la surface de la  matrice ";
        cin >> o;
    }
    this->nombre_obs = o;
    if (nombre_col > nombre_lign)
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
    }
    matrice2 = new char* [nombre_lign * nombre_col];
    for (int t = 0; t < nombre_col * nombre_lign; t++)
    {
        matrice2[t] = new char[nombre_col * nombre_lign];
    }
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
    cout << "****** la case  intial****** " << endl;
    casetab c1;
    this->modifier_case(c1, 'i');
    cout << "******la case finale****** " << endl;
    casetab c2;
    this->modifier_case(c2, 'f');
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
                cout << matrice[u][l];
            }
        }
    }
    return (tab);
}
void zone::recherche2(int c)
{
    int** matrice3;
    int nbr = 0;
    if (nombre_col > nombre_lign)
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
    cout << tab;
}
void zone::position_obs()
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
            modifier_case(c1, 'o');
        }
    }
    else
    {
        for (int t = 0; t < this->nombre_obs; t++)
        {
            modifier_alea_case(c1);
        }
    }
}
zone::~zone()
{
    delete[]matrice;
    delete[] matrice2;
}
void zone::modifier_case(casetab c, char a)
{
    int i;
    int j;
    cout << "donner la ligne puis colone  de cette case " << endl;
    cin >> i;
    cin >> j;
    c.setpos_lign(i);
    c.setpos_col(j);
    while ((c.getpos_col() >= this->nombre_col) || (c.getpos_lign() >= this->nombre_lign) || (this->existe(c) == true))
    {
        cout << "oups vous avez fait une faute donner une autre fois la case (ligne puis colone ) " << endl;
        cin >> i;
        cin >> j;
        c.setpos_lign(i);
        c.setpos_col(j);
    }
    if (a == 'i')
    {

        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setponderation('i');
        ili = c.getpos_lign();
        icol = c.getpos_col();
    }
    if (a == 'f')
    {
        matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setponderation('f');
        fli = c.getpos_lign();
        fcol = c.getpos_col();
    }
    if (a == 'o')
    {
        matrice[c.getpos_lign()][c.getpos_col()].setpos_col(c.getpos_col());
        matrice[c.getpos_lign()][c.getpos_col()].setpos_lign(c.getpos_lign());
        matrice[c.getpos_lign()][c.getpos_col()].setponderation('o');
    }

}
void zone::modifier_alea_case(casetab c)
{

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
}


/****************  partie  graphe     ****************/

graphe::graphe(int a, int b, zone z)
{
    this->dim = a * b;
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
void  graphe::dijekstra(int src, zone z, int w, int v)
{
    stack<int> p;
    int* dist = new int[dim];
    int* index = new int[dim];
    bool* Dset = new bool[dim];
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
        cout << "il n y a pas de chemin ";
    }
    else
    {
        cout << "****le chemin par les cases  est le suivant*****" << endl;
        int n = z.recherche(w, v);
        while (n != src)
        {
            p.push(n);
            n = index[n];
        }
        p.push(src);
        int nbr = p.size();
        cout << "de la case initiale" << endl;
        while (p.size() != 0)
        {

            int c5 = p.top();
            //cout<<"le rang de la case est "<<c5;
            //cout<<" les coordonnées de la case est "; 

            if (p.size() == 1)
            {
                z.recherche2(c5);
                p.pop();
                cout << "vers la case finale" << endl;
            }
            else
            {
                z.recherche2(c5);
                cout << " " << " ↓↓" << endl;
                p.pop();
            }

        }
        cout << "***************************************" << endl;
        cout << "la longeur du plus court chemin du point initial pour le robot vers le point final est :  " << dist[m] << endl;
        cout << endl;
    }
}
/****************  partie  main      ****************/
int main()
{
    int a, b, c;
    cout << "donner le nombre de ligne de votre zone ";
    cin >> a;
    cout << "donner le nombre de colone de votre zone ";
    cin >> b;
    cout << "donner le nombre d'obstacle' de votre zone et c doit etre infeieur ou egale à " << a * b - 2 << " ";
    cin >> c;
    if (a * b >= 4)
    {
        zone z1(a, b, c);
        z1.position_obs();
        z1.afficher_zone();
        z1.changer_matrice2();
        graphe g(a, b, z1);
        int m = z1.recherche(z1.ili, z1.icol);
        int w = z1.fli;
        int x = z1.fcol;
        g.dijekstra(m, z1, w, x);
    }
    else
    {
        cout << "la surface est tres petite pour avoir des obstacles , points finals et initials ";
    }

}
