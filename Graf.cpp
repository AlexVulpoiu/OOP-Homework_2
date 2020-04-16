#include "Graf.h"

Graf::Graf(int nr): noduri{nr} {}

Graf::Graf(const Graf& g)
{
    noduri = g.noduri;
}

Graf::~Graf()
{
    noduri = 0;
}

Graf& Graf::operator =(const Graf& g)
{
    if(this != &g)
        noduri = g.noduri;

    return *this;
}
