#include "Graf_turneu.h"

#include <utility>

Graf_turneu::Graf_turneu(int nr, int mc, const Matrice& M, std::vector<std::pair<int, int> > w): Graf_complet{mc, nr, std::move(w)}, Graf_antisimetric{M, nr} {}

Graf_turneu::Graf_turneu(const Graf_turneu& g) = default;

Graf_turneu::~Graf_turneu() = default;

std::istream& operator >>(std::istream& reader, Graf_turneu& g)
{
    int i, j, k;

    reader >> g.noduri >> g.muchii;
    g.adiacenta = Matrice(g.noduri, g.noduri);
    for(i = 0; i < g.noduri; i++)
        for(j = 0; j < g.noduri; j++)
        {
            reader >> k;
            g.adiacenta.setval(i, j, k);
        }

    return reader;
}

std::ostream& operator <<(std::ostream& writer, const Graf_turneu& g)
{
    writer << g.noduri << " noduri, " << g.muchii << " muchii\n" << g.adiacenta << '\n';

    return writer;
}

Graf_turneu& Graf_turneu::operator =(const Graf_turneu& g) = default;

void Graf_turneu::afisare_arce()
{
    int i, j;

    std::cout << "Arce graf turneu:\n";
    for(i = 0; i < noduri; i++)
        for(j = 0; j < noduri; j++)
            if(adiacenta(i, j) == 1)
                std::cout << i << ' ' << j << '\n';
}
