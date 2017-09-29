#ifndef MEUPAINELOPENGL_H
#define MEUPAINELOPENGL_H

#include <QGLWidget>
#include "malha.h"
#include "reta.h"

class MeuPainelOpenGL : public QGLWidget
{
Q_OBJECT
public:
    explicit MeuPainelOpenGL(QWidget *parent = 0);

signals:

public slots:
    void changeSizePanel(int size);
    void setStartPointX(int value);
    void setStartPointY(int value);
    void setEndPointX(int value);
    void setEndPointY(int value);
    void setShowRetaPrincipal(bool value);
    void setShowDDA(bool value);
    void setShowExplictEquation(bool value);
    void setShowMidpoint(bool value);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();


private:
    Malha malha;
    Reta reta;
    int startPointX;
    int startPointY;
    int endPointX;
    int endPointY;

    bool showRetaPrincipal;
    bool showDDA;
    bool showExplictEquation;
    bool showMidpoint;

    void clear();
    void defineSizePanel();
    void drawGrid();
    void drawLine();
    void drawCircle();
};

#endif // MEUPAINELOPENGL_H
