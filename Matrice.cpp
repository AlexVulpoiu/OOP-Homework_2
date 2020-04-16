#include "Matrice.h"

Matrice::Matrice(int lin, int col, int x): n{lin}, m{col}
{
    int i, j;

    a = new int* [n];
    for(i = 0; i < n; i++)
        a[i] = new int [m];

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            a[i][j] = x;
}

Matrice::Matrice(const Matrice& mat)
{
    int i, j;

    n = mat.n;
    m = mat.m;
    a = new int* [n];
    for(i = 0; i < n; i++)
        a[i] = new int [m];

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            a[i][j] = mat.a[i][j];
}

Matrice::~Matrice()
{
    int i;

    for(i = 0; i < n; i++)
        delete []a[i];
    delete []a;
    m = 0;
    n = 0;
}

std::istream& operator >>(std::istream& read, Matrice& mat)
{
    int i, j;

    read >> mat.n >> mat.m;
    mat.a = new int* [mat.n];
    for(i = 0; i < mat.n; i++)
        mat.a[i] = new int [mat.m];
    for(i = 0; i < mat.n; i++)
        for(j = 0; j < mat.m; j++)
            read >> mat.a[i][j];

    return read;
}

std::ostream& operator <<(std::ostream& write, const Matrice& mat)
{
    int i, j;

    write << "n = " << mat.n << ", m = " << mat.m << '\n';
    for(i = 0; i < mat.n; i++, write << '\n')
        for(j = 0; j < mat.m; j++)
            write << mat.a[i][j] << ' ';

    return write;
}

Matrice& Matrice::operator =(const Matrice& mat)
{
    int i, j;

    if(this != &mat)
    {
        for(i = 0; i < n; i++)
            delete []a[i];
        delete []a;
        n = mat.n;
        m = mat.m;
        a = new int* [n];
        for(i = 0; i < n; i++)
            a[i] = new int [m];
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                a[i][j] = mat.a[i][j];
    }

    return *this;
}

void Matrice::setval(int i, int j, int k)
{
    a[i][j] = k;
}

int Matrice::getval(int i, int j) const
{
    return a[i][j];
}

int Matrice::getn() const
{
    return n;
}

int Matrice::getm() const
{
    return m;
}