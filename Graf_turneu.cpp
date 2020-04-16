#include "Graf_turneu.h"

Graf_turneu::Graf_turneu(int nr, int mc, const Matrice& M): Graf{nr}, Graf_complet{mc, nr}, Graf_antisimetric{M, nr}{}

Graf_turneu::Graf_turneu(const Graf_turneu& g) = default;

Graf_turneu::~Graf_turneu() = default;

std::istream& operator >>(std::istream& read, Graf_turneu& g)
{
    int i, j, k;

    read >> g.noduri >> g.muchii;
    g.adiacenta = Matrice(g.noduri, g.noduri);
    for(i = 0; i < g.noduri; i++)
        for(j = 0; j < g.noduri; j++)
        {
            read >> k;
            g.adiacenta.setval(i, j, k);
        }

    return read;
}

std::ostream& operator <<(std::ostream& write, const Graf_turneu& g)
{
    write << g.noduri << " noduri, " << g.muchii << " muchii\n" << g.adiacenta << '\n';

    return write;
}

Graf_turneu& Graf_turneu::operator =(const Graf_turneu& g)
{
    if(this != &g)
    {
        this->noduri = g.noduri;
        this->muchii = g.muchii;
        this->adiacenta = g.adiacenta;
    }

    return *this;
}

void Graf_turneu::afisare_arce()
{
    int i, j;

    std::cout << "Arce graf turneu:\n";
    for(i = 0; i < noduri; i++)
        for(j = 0; j < noduri; j++)
            if(adiacenta.getval(i, j) == 1)
                std::cout << i << ' ' << j << '\n';
}
