#include "util.h"

Util::Util()
{

}

void Util::trocar(int *valor1, int *valor2) {
    int temp;

    temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

void Util::trocar(float *valor1, float *valor2) {
    float temp;

    temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

void Util::trocar(double *valor1, double *valor2) {
    double temp;

    temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

int Util::maior(int valor1, int valor2) {
    if (valor1 > valor2)
        return valor1;
    return valor2;
}


int Util::menor(int valor1, int valor2) {
    if (valor1 < valor2)
        return valor1;
    return valor2;
}
