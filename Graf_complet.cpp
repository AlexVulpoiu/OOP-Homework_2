#include "Graf_complet.h"

Graf_complet::Graf_complet(int mc, int nr, std::vector<std::pair<int, int> > w): muchii{mc}, arce{std::move(w)}
{
    noduri = nr;
}

Graf_complet::Graf_complet(const Graf_complet& g) = default;

Graf_complet::~Graf_complet() = default;

std::istream& operator >>(std::istream& reader, Graf_complet& g)
{
    int i, x, y;

    reader >> g.noduri >> g.muchii;
    for(i = 0; i < g.muchii; i++)
    {
        reader >> x >> y;
        g.arce.emplace_back(x, y);
    }

    return reader;
}

std::ostream& operator <<(std::ostream& writer, const Graf_complet& g)
{
    unsigned int i;

    writer << g.noduri << " noduri, " << g.muchii << " muchii\n";
    for(i = 0; i < g.arce.size(); i++)
        writer << g.arce[i].first << ' '  << g.arce[i].second << '\n';

    return writer;
}

Graf_complet& Graf_complet::operator =(const Graf_complet &g) = default;

void Graf_complet::afisare_arce()
{
    unsigned int i;

    std::cout << "Arce graf complet:\n" << muchii << " muchii\n";
    for(i = 0; i < arce.size(); i++)
        std::cout << arce[i].first << ' ' << arce[i].second << '\n';
}
