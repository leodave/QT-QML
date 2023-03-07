#ifndef OPENGLGRAPHICSIGNAL_H
#define OPENGLGRAPHICSIGNAL_H


#include <QOpenGLFunctions_1_1>
#include <QOpenGLWidget>
#include <QObject>


class OpenGlGraphicSignal : public QOpenGLWidget, public QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    OpenGlGraphicSignal(QWidget *parent = 0);

protected:
public slots:
   void recievedNewData(QList<float> data);


    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;

private:
    QColor signalColor;
    QColor background;
    QList<float> newestData3;



};

#endif // OPENGLGRAPHICSIGNAL_H
