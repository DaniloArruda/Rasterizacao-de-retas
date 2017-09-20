#ifndef RETA_H
#define RETA_H

#include "ponto.h"
#include "util.h"

class Reta
{
private:
    Ponto ponto1;
    Ponto ponto2;

    void drawPixel(int x, int y);
    int getdx();
    int getdy();

    void setPositiveSlope();

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
    void drawMidpoint();
    void drawExplictEquation();
};

#endif // RETA_H
