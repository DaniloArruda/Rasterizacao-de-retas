#include "reta.h"
#include <GL/glu.h>
#include "math.h"

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

