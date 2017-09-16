#ifndef RETA_H
#define RETA_H

#include "ponto.h"

class Reta
{
private:
    Ponto ponto1;
    Ponto ponto2;

    void drawPixel(int x, int y);
    int getdx();
    int getdy();

public:
    Reta();
    Reta(Ponto ponto1, Ponto ponto2);

    Ponto* getPonto1();
    void setPonto1(Ponto ponto);
    Ponto* getPonto2();
    void setPonto2(Ponto ponto);

    void setXPonto1(int value);
    void setYPonto1(int value);
    void setXPonto2(int value);
    void setYPonto2(int value);

    void draw();
    void drawDDA();
};

#endif // RETA_H
