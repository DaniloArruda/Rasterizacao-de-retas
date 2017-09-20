#include "MeuPainelOpenGL.h"
#include <cmath>
#include <GL/glu.h>

MeuPainelOpenGL::MeuPainelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
}

void MeuPainelOpenGL::changeSizePanel(int size) {
    malha.setSize(size);
    defineSizePanel();
    updateGL();
}

void MeuPainelOpenGL::defineSizePanel() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, malha.getSize(), 0, malha.getSize());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MeuPainelOpenGL::setStartPointX(int value) {
    reta.getPonto1()->setX(value);
    updateGL();
}

void MeuPainelOpenGL::setStartPointY(int value) {
    reta.getPonto1()->setY(value);
    updateGL();
}

void MeuPainelOpenGL::setEndPointX(int value) {
    reta.getPonto2()->setX(value);
    updateGL();
}

void MeuPainelOpenGL::setEndPointY(int value) {
    reta.getPonto2()->setY(value);
    updateGL();
}

void MeuPainelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MeuPainelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width, (GLint)height );

    defineSizePanel();
}

void MeuPainelOpenGL::paintGL()
{
    clear();

    glColor3f(0,0,0);
    malha.draw();

    glColor3f(1,0,0);
    reta.draw();

    glColor3f(0,1,0);
    reta.drawMidpointCuia();
}

void MeuPainelOpenGL::clear() {
    // Limpa a janela de visualização com a cor branca
    // e Limpa o buffer de teste de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // limpa todas as transformações
}
