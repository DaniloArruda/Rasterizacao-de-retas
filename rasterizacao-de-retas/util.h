#ifndef UTIL_H
#define UTIL_H


class Util
{
public:
    Util();
    static void trocar(int *valor1, int *valor2);
    static void trocar(float *valor1, float *valor2);
    static void trocar(double *valor1, double *valor2);

    static int maior(int valor1, int valor2);
    static int menor(int valor1, int valor2);
};

#endif // UTIL_H
