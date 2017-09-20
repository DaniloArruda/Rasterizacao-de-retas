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
    int dx, dy, d, incE, incNE, x, y, x1, y1, x2, y2, xDraw, yDraw;
    bool symmetric, slope;

    symmetric = slope = false;

    x1 = ponto1.getX();
    y1 = ponto1.getY();
    x2 = ponto2.getX();
    y2 = ponto2.getY();

    dx = getdx();
    dy = getdy();

    if (dx * dy < 0) { // to set positive slope
        y1 = -y1;
        y2 = -y2;
        dy = -dy;
        symmetric = true;
    }

    if (abs(dx) < abs(dy)) { // to set slope in first octant
        Util::trocar(&x1, &y1);
        Util::trocar(&x2, &y2);
        Util::trocar(&dx, &dy);//
        slope = true;
    }

    if (x1 > x2) { // to set the point 1 less than point 2
        Util::trocar(&x1, &x2);
        Util::trocar(&y1, &y2);
        dx = -dx;
        dy = -dy;
    }

    x = xDraw = x1;
    y = yDraw = y1;

    if(slope)
        Util::trocar(&xDraw, &yDraw);

    if (symmetric)
        yDraw = -yDraw;

    drawPixel(xDraw, yDraw);

    d = 2*dy - dx;
    incE = 2*dy;
    incNE = 2*(dy - dx);

    while (x < x2) {
        if (d <= 0) {
            d += incE;
        } else {
            d += incNE;
            y++;
        }
        x++;

        xDraw = x;
        yDraw = y;

        if(slope)
            Util::trocar(&xDraw, &yDraw);

        if (symmetric)
            yDraw = -yDraw;

        drawPixel(xDraw, yDraw);
    }
}

void Reta::drawExplictEquation() {
    float b, m, x, y, xMin, xMax, dx, dy;

    dx = getdx();
    dy = getdy();

    if (dx == 0)
        m = dy;
    else
        m = dy/dx;

    b = ponto1.getY() - ponto1.getX()*m;

    xMin = ponto1.getX() < ponto2.getX() ? ponto1.getX() : ponto2.getX();
    xMax = ponto1.getX() > ponto2.getX() ? ponto1.getX() : ponto2.getX();

    for (x = xMin; x <= xMax; x++) {
        y = round(m*x + b);
        drawPixel(x, y);
    }
}
