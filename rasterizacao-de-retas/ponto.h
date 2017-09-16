#ifndef PONTO_H
#define PONTO_H


class Ponto
{
private:
    int x;
    int y;

public:
    Ponto();
    Ponto(int x, int y);

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);
};

#endif // PONTO_H
