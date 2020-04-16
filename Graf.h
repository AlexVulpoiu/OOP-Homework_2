#ifndef TEMA2_GRAF_H
#define TEMA2_GRAF_H

class Graf
{
protected:
    int noduri;

public:
    explicit Graf(int nr = 0);
    Graf(const Graf& g);
    virtual ~Graf() = 0;

    Graf& operator =(const Graf& g);

    virtual void afisare_arce() = 0;
};

#endif //TEMA2_GRAF_H
