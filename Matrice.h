#ifndef TEMA2_MATRICE_H
#define TEMA2_MATRICE_H

#include <iostream>

class Matrice
{
private:
    int n, m, **a;

public:
    explicit Matrice(int lin = 0, int col = 0, int x = 0);
    Matrice(const Matrice& mat);
    ~Matrice();

    friend std::istream& operator >>(std::istream& reader, Matrice& mat);
    friend std::ostream& operator <<(std::ostream& writer, const Matrice& mat);

    Matrice& operator =(const Matrice& mat);

    void setval(int i, int j, int k);
    int& operator ()(int i, int j);

    int getn() const;
    int getm() const;
};

#endif //TEMA2_MATRICE_H
