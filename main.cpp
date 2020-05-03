#include <fstream>
#include <vector>
#include "Matrice.h"
#include "Graf.h"
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"

using namespace std;

ofstream fout("grafuri.out");

enum GRAF{nu_e_graf, complet, antisimetric, turneu};

void construieste_graf(int tip, Matrice matr, int ind)
{
    int mc, i, j, l;
    vector<pair<int, int> > vect;
    Graf_complet gc;
    Graf_antisimetric ga;
    Graf_turneu gt;

    l = matr.getn();
    if(tip == 1)  /// graf complet
     {
        mc = 0;
        for(i = 0; i < l; i++)
            for(j = 0; j < l; j++)
                if(matr(i, j))
                {
                    mc++;
                    vect.emplace_back(i, j);
                }
        gc = Graf_complet(mc, l, vect);

        fout << "Graf complet format cu matricea " << ind << '\n' << gc << "\n";
        gc.afisare_arce();
     }
    else
        if(tip == 2)  /// graf antisimetric
        {
            ga = Graf_antisimetric(matr, l);

            fout << "Graf antisimetric format cu matricea " << ind << '\n' << ga;
            ga.afisare_arce();
        }
        else    /// graf turneu
        {
            gt = Graf_turneu(l, l * (l - 1) / 2, matr);

            fout << "Graf turneu format cu matricea " << ind << '\n' << gt;
            gt.afisare_arce();
        }
}

void graf(Matrice& M, int ind)
{
    int i, j, c, a;
    bool ok;
    GRAF rez;

    if(M.getn() != M.getm())
        rez = nu_e_graf;
    else
    {
        ok = true;  /// initial, presupunem ca putem forma graf
        for(i = 0; i < M.getn(); i++)
            for(j = 0; j < M.getn(); j++)
                if((M(i, j) == 1 && i == j) || (M(i, j) != 0 && M(i, j) != 1))
                {
                    rez = nu_e_graf;
                    ok = false; /// nu putem forma graf
                }
        if(ok)
        {
            c = 1;
            for(i = 0; i < M.getn(); i++)
                for(j = 0; j < M.getn(); j++)
                    if(!M(i, j) && !M(j, i) && i != j)
                        c = 0;    /// daca c == 0, graful nu poate fi complet
            a = 1;
            for(i = 0; i < M.getn(); i++)
                for(j = 0; j < M.getn(); j++)
                    if(M(i, j) && M(j, i) && i != j)
                        a = 0;    /// daca a == 0, graful nu poate fi antisimetric
            if(c && a)
                rez = turneu;
            else
                if(a)
                    rez = antisimetric;
                else
                    if(c)
                        rez = complet;
                    else
                        rez = nu_e_graf;
        }
    }

    try
    {
        throw rez;
    }
    catch(GRAF x)
    {
        if(x == nu_e_graf)
            fout << "Nu se poate forma un graf complet, antisimetric sau turneu cu matricea " << ind << "\n\n";
        else
            construieste_graf(x, M, ind);
    }
}

int main()
{
    ifstream fin("grafuri.in");

    int ind, nr;
    Matrice* mat;

    fin >> nr;
    mat = new Matrice [nr];
    for(ind = 0; ind < nr; ind++)
    {
        fin >> mat[ind];
        Matrice M = mat[ind];
        graf(M, ind);
    }
    fin.close();

    delete []mat;
    fout.close();

    return 0;
}
