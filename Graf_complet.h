#ifndef TEMA2_GRAF_COMPLET_H
#define TEMA2_GRAF_COMPLET_H

#include <iostream>
#include <vector>
#include "Graf.h"

class Graf_complet: virtual public Graf
{
protected:
    int muchii{};
    std::vector<std::pair<int, int> > arce;

public:
    explicit Graf_complet(int mc = 0, int nr = 0, std::vector<std::pair<int, int> > w = {});
    Graf_complet(const Graf_complet& g);
    ~Graf_complet() override;

    friend std::istream& operator >>(std::istream& reader, Graf_complet& g);
    friend std::ostream& operator <<(std::ostream& writer, const Graf_complet& g);

    Graf_complet& operator =(const Graf_complet& g);

    void afisare_arce() override;
};

#endif //TEMA2_GRAF_COMPLET_H
