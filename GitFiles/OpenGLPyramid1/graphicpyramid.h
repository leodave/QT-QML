#ifndef GRAPHICPYRAMID_H
#define GRAPHICPYRAMID_H

#include <QOpenGLFunctions_1_1>
#include <QOpenGLWidget>
#include <QObject>
#include <QMouseEvent>

class GraphicPyramid : public QOpenGLWidget, public QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    GraphicPyramid(QWidget *parent = 0);

protected:

    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;

private:
    QColor triColor;
    QColor background;
    float angleX;
    float angleY;
    float zoom;
    float translateX;
    float translateY;
    bool pressed = false;
    bool rightPressed = false;
    float lastX = 0;
    float lastY = 0;
    float lastPosX = 0;
    float lastPosY = 0;

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    // QWidget interface
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
};

#endif // GRAPHICPYRAMID_H
