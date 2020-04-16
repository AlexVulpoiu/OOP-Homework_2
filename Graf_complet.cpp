#include "Graf_complet.h"

Graf_complet::Graf_complet(int mc, int nr): Graf{nr}, muchii{mc} {}

Graf_complet::Graf_complet(const Graf_complet& g): Graf(g)
{
    muchii = g.muchii;
}

Graf_complet::~Graf_complet()
{
    muchii = 0;
}

std::istream& operator >>(std::istream& read, Graf_complet& g)
{
    read >> g.noduri >> g.muchii;

    return read;
}

std::ostream& operator <<(std::ostream& write, const Graf_complet& g)
{
    write << g.noduri << " noduri, " << g.muchii << " muchii\n";

    return write;
}

Graf_complet& Graf_complet::operator =(const Graf_complet &g)
{
    if(this != &g)
    {
        noduri = g.noduri;
        muchii = g.muchii;
    }

    return *this;
}

void Graf_complet::afisare_arce()
{
    std::cout << muchii << " muchii\n";
}
