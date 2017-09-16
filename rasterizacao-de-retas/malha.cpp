#include "malha.h"
#include <GL/glu.h>

Malha::Malha()
{
    this->size = 10;
}

Malha::Malha(int size) {
    this->size = size;
}

int Malha::getSize() {
    return this->size;
}

void Malha::setSize(int size) {
    this->size = size;
}

void Malha::draw() {
    glBegin(GL_LINES);
        for (int i = 0; i < size; i++) {
            glVertex2f(i, 0);
            glVertex2f(i, size);

            glVertex2f(0, i);
            glVertex2f(size, i);
        }
    glEnd();
}
