#include <fstream>
#include "Matrice.h"
#include "Graf.h"
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"

using namespace std;

int tip_graf(Matrice& M)
{
    int i, j, c, a;

    if(M.getn() == M.getm())
    {
        for(i = 0; i < M.getn(); i++)
            for(j = 0; j < M.getn(); j++)
                if((M.getval(i, j) == 1 && i == j) || (M.getval(i, j) != 0 && M.getval(i, j) != 1))
                    return 0;   /// nu se poate forma un graf cu matricea data daca avem valori diferite de 0 si 1
        c = 1;
        for(i = 0; i < M.getn(); i++)
            for(j = 0; j < M.getn(); j++)
                if(!M.getval(i, j) && !M.getval(j, i) && i != j)
                    c = 0;    /// daca c == 0, graful nu poate fi complet
        a = 1;
        for(i = 0; i < M.getn(); i++)
            for(j = 0; j < M.getn(); j++)
                if(M.getval(i, j) && M.getval(j, i) && i != j)
                    a = 0;    /// daca a == 0, graful nu poate fi antisimetric
        if(c && a)
            return 3;   /// graf turneu
        else
            if(a)
                return 2;   /// graf antisimetric
            else
                if(c)
                    return 1;   /// graf complet
                else
                    return 0;   /// nu se poate forma un graf complet, antisimetric sau turneu
    }
    else
        return 0;   /// nu se poate forma un graf cu matricea data
}

int main()
{
    ifstream fin("grafuri.in");
    ofstream fout("grafuri.out");

    int i, j, l, ind, mc, nr;
    Matrice* mat;
    Graf_complet gc;
    Graf_antisimetric ga;
    Graf_turneu gt;

    fin >> nr;
    mat = new Matrice [nr];
    for(ind = 0; ind < nr; ind++)
    {
        fin >> mat[ind];
        l = mat[ind].getn();
        Matrice M = mat[ind];
        try
        {
            throw tip_graf(M);
        }
        catch(int x)
        {
            if(!x)
                fout << "Nu se poate forma un graf complet, antisimetric sau turneu cu matricea " << ind << "\n\n";
            else
                if(x == 1)  /// graf complet
                {
                    mc = 0;
                    for(i = 0; i < l; i++)
                        for(j = 0; j < l; j++)
                            if(M.getval(i, j))
                                mc++;
                    gc = Graf_complet(mc, l);

                    fout << "Graf complet format cu matricea " << ind << '\n' << gc << "\n";
                }
                else
                    if(x == 2)  /// graf antisimetric
                    {
                        ga = Graf_antisimetric(mat[ind], l);

                        fout << "Graf antisimetric format cu matricea " << ind << '\n' << ga;
                        ga.afisare_arce();
                    }
                    else    /// graf turneu
                    {
                        gt = Graf_turneu(l, l * (l - 1) / 2, mat[ind]);

                        fout << "Graf turneu format cu matricea " << ind << '\n' << gt;
                        gt.afisare_arce();
                    }
        }
    }
    fin.close();

    delete []mat;
    fout.close();

    return 0;
}
