#include "reta.h"
#include <GL/glu.h>
#include "math.h"
#include "util.h"

Reta::Reta()
{
    ponto1 = Ponto(0, 0);
    ponto2 = Ponto(5, 5);
}

Reta::Reta(Ponto ponto1, Ponto ponto2) {
    this->ponto1 = ponto1;
    this->ponto2 = ponto2;
}

Ponto* Reta::getPonto1() {
    return &this->ponto1;
}

void Reta::setPonto1(Ponto ponto) {
    this->ponto1 = ponto;
}

Ponto* Reta::getPonto2() {
    return &this->ponto2;
}

void Reta::setPonto2(Ponto ponto) {
    this->ponto2 = ponto;
}

void Reta::setXPonto1(int value) {
    ponto1.setX(value);
}

void Reta::setYPonto1(int value) {
    ponto1.setY(value);
}

void Reta::setXPonto2(int value) {
    ponto2.setX(value);
}

void Reta::setYPonto2(int value) {
    ponto2.setY(value);
}

void Reta::draw() {
    glBegin(GL_LINES);
        glVertex2f(ponto1.getX(), ponto1.getY());
        glVertex2f(ponto2.getX(), ponto2.getY());
    glEnd();
}

void Reta::drawPixel(int x, int y) {
    int lados = 60;
    float raio = 0.5;
    float PI = 3.14159265;
    glBegin(GL_POLYGON);
        for (int i = 0; i < lados; ++i) {
            glVertex2f(x + raio*cos(i*2*PI/lados), y + raio*sin(i*2*PI/lados));
        }
    glEnd();
}

int Reta::getdx() {
    return ponto2.getX() - ponto1.getX();
}

int Reta::getdy() {
    return ponto2.getY() - ponto1.getY();
}

void Reta::drawDDA() {
    int length, dx, dy;
    float x, y, xInc, yInc;

    dx = getdx();
    dy = getdy();

    if (abs(dx) > abs(dy))
        length = abs(dx);
    else
        length = abs(dy);

    xInc = (float) dx/length;
    yInc = (float) dy/length;

    x = ponto1.getX();
    y = ponto1.getY();

    for (int i = 0; i <= length; i++) {
        drawPixel(round(x), round(y));
        x += xInc;
        y += yInc;
    }
}

void Reta::drawMidpoint() {
    int a, b, d, x, y, incE, incNE, dx, dy, x1, x2, y1, y2, xDraw, yDraw;
    bool declive, simetrico;

    x1 = ponto1.getX();
    x2 = ponto2.getX();

    y1 = ponto1.getY();
    y2 = ponto2.getY();

    dx = getdx();
    dy = getdy();


    //inicio do processo de conversão de qualquer octante para o primeiro octante
    declive = false;
    simetrico = false;

    if(dx * dy < 0) {
        dy = -dy;
        y1 = -y1;
        y2 = -y2;

        simetrico = true;
    }

    if(abs(dx) < abs(dy)){
        Util::trocar(&x1, &y1);
        Util::trocar(&x2, &y2);

        declive = true;
    }

    if(x1 > x2){
        Util::trocar(&x1, &x2);
        Util::trocar(&y1, &y2);
    }
    //fim do processo de conversão de octantes

    a = y2 - y1;
    b = -x2 + x1;

    x = x1;
    y = y1;
    xDraw = x1;
    yDraw = y1;

    incE = 2*a;
    incNE = 2*(a + b);

    //verifica e converte de volta ao primeiro octante
    if(declive){
        Util::trocar(&xDraw, &yDraw);
    }
    if(simetrico){
        yDraw = -yDraw;
    }
    //fim de verificacao de octante

    drawPixel(xDraw,yDraw);
    d = 2*a + b;
    while(x < x2){
        if(d <= 0){
            d += incE;
            x++;
        } else{
            d += incNE;
            x++;
            y++;
        }
        xDraw = x;
        yDraw = y;

        //verifica e converte de volta ao primeiro octante
        if(declive){
            Util::trocar(&xDraw, &yDraw);
        }
        if(simetrico){
            yDraw = -yDraw;
        }
        //fim de verificacao de octante
        drawPixel(xDraw,yDraw);
    }
}
