#include "Graf_antisimetric.h"

Graf_antisimetric::Graf_antisimetric(const Matrice& M, int nr): adiacenta{M}
{
    noduri = nr;
}

Graf_antisimetric::Graf_antisimetric(const Graf_antisimetric& g) = default;

Graf_antisimetric::~Graf_antisimetric() = default;

std::istream& operator >>(std::istream& reader, Graf_antisimetric& g)
{
    int i, j, k;

    reader >> g.noduri;
    g.adiacenta = Matrice(g.noduri, g.noduri);
    for(i = 0; i < g.noduri; i++)
        for(j = 0; j < g.noduri; j++)
        {
            reader >> k;
            g.adiacenta.setval(i, j, k);
        }

    return reader;
}

std::ostream& operator <<(std::ostream& writer, const Graf_antisimetric& g)
{
    writer << g.noduri << " noduri\n" << g.adiacenta << '\n';

    return writer;
}

Graf_antisimetric& Graf_antisimetric::operator =(const Graf_antisimetric& g) = default;
void Graf_antisimetric::afisare_arce()
{
    int i, j;

    std::cout << "Arce graf antisimetric:\n";
    for(i = 0; i < noduri; i++)
        for(j = 0; j < noduri; j++)
            if(adiacenta(i, j) == 1)
                std::cout << i << ' ' << j << '\n';
}
