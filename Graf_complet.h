#ifndef TEMA2_GRAF_COMPLET_H
#define TEMA2_GRAF_COMPLET_H

#include <iostream>
#include "Graf.h"

class Graf_complet: virtual public Graf
{
protected:
    int muchii;

public:
    explicit Graf_complet(int mc = 0, int nr = 0);
    Graf_complet(const Graf_complet& g);
    ~Graf_complet() override;

    friend std::istream& operator >>(std::istream& read, Graf_complet& g);
    friend std::ostream& operator <<(std::ostream& write, const Graf_complet& g);

    Graf_complet& operator =(const Graf_complet& g);

    void afisare_arce() override;
};

#endif //TEMA2_GRAF_COMPLET_H
