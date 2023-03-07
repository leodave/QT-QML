#include "openglgraphicsignal.h"
#include <QDebug>



OpenGlGraphicSignal::OpenGlGraphicSignal(QWidget *parent)
{
    background = QColor("#868889");
    signalColor = QColor("blue");

}

void OpenGlGraphicSignal::recievedNewData(QList<float> data)
{
     newestData3 = data;
    while(newestData3.size() >= width()/5){
         newestData3.removeFirst();
   }

   //  qDebug() << newestData3.size();
    update();
}

void OpenGlGraphicSignal::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
}

void OpenGlGraphicSignal::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f,w * 1.0f, -1.0f, h * 1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void OpenGlGraphicSignal::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glScalef(5.0,50.0,1.0);
    glTranslatef(1.5f,2.5f,0.0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(signalColor.redF(),signalColor.greenF(), signalColor.blueF());

    /* for(int i = 0; i < 300; i+=10){
         glVertex3f(i * 1.0f,i * 1.0f, 0.0f);
         glVertex3f((i + 10) *1.0f,(i +10) * 1.0f, 0.0f);
     }*/
    //glVertex3f(0.0f,0.0f,0.0f);
    //glVertex3f(1.0f,2.0f,0.0f);

     for(int i = 0; i < (newestData3.size()-1) ; i++){
           // qDebug() << newestData3[i];
         glVertex3f(i * 1.0f, newestData3[i]*1.0f, 0.0f);
         glVertex3f((i+1)* 1.0f, newestData3[i+1]*1.0f,0.0f);
     }

     glEnd();
     glPopMatrix();
     glFlush();
}
