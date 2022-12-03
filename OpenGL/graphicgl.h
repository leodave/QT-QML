#ifndef GRAPHICGL_H
#define GRAPHICGL_H

#include <QOpenGLWidget>
#include <QObject>

#include <QOpenGLFunctions_1_1>
#include <QWheelEvent>
#include <QEvent>

class GraphicGl : public QOpenGLWidget, protected QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    GraphicGl( QWidget *parent = 0);
     void addData(float newData);

protected:

    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;

private:
    QColor signalColor;
    QColor background;

    QVector<float> signal;
    float graphicZoom;


    // QWidget interface
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
};

#endif // GRAPHICGL_H
