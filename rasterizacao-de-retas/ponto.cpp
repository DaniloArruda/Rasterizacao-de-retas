#include "ponto.h"

Ponto::Ponto()
{
    x = 0;
    y = 0;
}


Ponto::Ponto(int x, int y) {
    this->x = x;
    this->y = y;
}

int Ponto::getX() {
    return x;
}

void Ponto::setX(int value) {
    x = value;
}

int Ponto::getY() {
    return y;
}

void Ponto::setY(int value) {
    y = value;
}
