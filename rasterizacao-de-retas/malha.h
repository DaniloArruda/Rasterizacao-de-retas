#ifndef MALHA_H
#define MALHA_H


class Malha
{
private:
    int size;

public:
    Malha();
    Malha(int size);
    int getSize();
    void setSize(int size);
    void draw();
};

#endif // MALHA_H
