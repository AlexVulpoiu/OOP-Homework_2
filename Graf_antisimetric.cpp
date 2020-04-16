#include "Graf_antisimetric.h"

Graf_antisimetric::Graf_antisimetric(const Matrice& M, int nr): Graf{nr}, adiacenta{M} {}

Graf_antisimetric::Graf_antisimetric(const Graf_antisimetric& g): Graf(g)
{
    adiacenta = g.adiacenta;
}

Graf_antisimetric::~Graf_antisimetric() = default;

std::istream& operator >>(std::istream& read, Graf_antisimetric& g)
{
    int i, j, k;

    read >> g.noduri;
    g.adiacenta = Matrice(g.noduri, g.noduri);
    for(i = 0; i < g.noduri; i++)
        for(j = 0; j < g.noduri; j++)
        {
            read >> k;
            g.adiacenta.setval(i, j, k);
        }

    return read;
}

std::ostream& operator <<(std::ostream& write, const Graf_antisimetric& g)
{
    write << g.noduri << " noduri\n" << g.adiacenta << '\n';

    return write;
}

Graf_antisimetric& Graf_antisimetric::operator =(const Graf_antisimetric& g)
{
    if(this != &g)
    {
        this->noduri = g.noduri;
        this->adiacenta = g.adiacenta;
    }

    return *this;
}

void Graf_antisimetric::afisare_arce()
{
    int i, j;

    std::cout << "Arce graf antisimetric:\n";
    for(i = 0; i < noduri; i++)
        for(j = 0; j < noduri; j++)
            if(adiacenta.getval(i, j) == 1)
                std::cout << i << ' ' << j << '\n';
}
