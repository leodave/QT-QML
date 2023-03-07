#include "graphicpyramid.h"

GraphicPyramid::GraphicPyramid(QWidget *parent) : QOpenGLWidget(parent)
{
     background = QColor("lightgray");
     triColor = QColor("blue");
     angleX = 0.0f;
     angleY = 0.0f;
     zoom = 2.0f;
     translateX = 1.5f;
     translateY = 0.0f;
}

void GraphicPyramid::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
    glEnable(GL_DEPTH_TEST);
}

void GraphicPyramid::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0f, 3.0f, -1.0f, 2.0f, -10.0f, 10.0f);
    glOrtho(-10.0f,10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
    //glOrtho(0.0f,w * 1.0f, 0.0f, h * 1.0f, -1000.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

   glTranslatef(translateX,translateY,0.0);
   // glScalef(100,100,100);
    glScalef(zoom,zoom,zoom);
    glRotatef(angleX,0.0,1.0,0.0);
   glRotatef(angleY,1.0,0.0,0.0);

     //glLineWidth(1.5);
    glBegin(GL_TRIANGLES);




//green left
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0);

  //blue back
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(1.0f,-1.0f,-1.0f);
        glVertex3f(0.0f,1.0f,0.0f);

//darkgreen
    glColor3f(0.0f,0.5f,0.5f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);

//red front
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-1.0f,-1.0f,1.0f);
        glVertex3f(1.0f,-1.0f,1.0f);
        glVertex3f(0.0f,1.0f,0.0f);

    glEnd();

     glBegin(GL_QUADS);

     glColor3f(0.5f,0.5f,0.0f);
     glVertex3f(-1.0f,-1.0f,1.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
     glVertex3f(1.0f,-1.0f,-1.0f);
     glVertex3f(1.0f,-1.0f,1.0f);

     glEnd();

     glLineWidth(3.5);
     glBegin(GL_LINES);
     glColor3f(0.0f,0.0f,0.0f);
     glVertex3f(-1.5f,0.0f,0.0f);
     glVertex3f(1.5f,0.0f,0.0f);

     glColor3f(0.0f,0.0f,0.0f);
     glVertex3f(0.0f,-1.5f,0.0f);
     glVertex3f(0.0f,1.5f,0.0f);



    glEnd();
    glPopMatrix();
    glFlush();
}

void GraphicPyramid::mousePressEvent(QMouseEvent *event)
{
    lastX = event->pos().x();
    lastY = event->pos().y();
    lastPosX = event->pos().x();
    lastPosY = event->pos().y();
    if(event->button() == Qt::RightButton){
        rightPressed = true;
    }
    if(event->button() == Qt::LeftButton){
        pressed = true;
    }


}

void GraphicPyramid::mouseReleaseEvent(QMouseEvent *event)
{
    rightPressed = false;
    pressed = false;

}

void GraphicPyramid::mouseMoveEvent(QMouseEvent *event)
{


    if(pressed == true){
        if(event->pos().x() > lastX ){
            angleX +=0.8f;
            qDebug() <<  lastX;
        }else{
               angleX -=0.8f;
            qDebug() << lastX;
        }
        if(event->pos().y() > lastY ){
            angleY -=0.8f;


            qDebug() <<  lastX;
        }else{
               angleY +=0.8f;
            qDebug() << lastY;
        }
        lastX = event->pos().x();
        lastY = event->pos().y();

    }else {
        qDebug() << "not pressed";
    }
    if(rightPressed == true){
        if(event->pos().x() > lastPosX){
            translateX += 0.05f;
        }else {
            translateX -= 0.05f;
        }
        if(event->pos().y() > lastPosY ){
            translateY -=0.05f;

        }else{
               translateY +=0.05f;

        }
        lastPosX = event->pos().x();
        lastPosY = event->pos().y();
    }
    update();
}

void GraphicPyramid::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y()>0){
        zoom += 0.2;
    }
    else if(event->angleDelta().y() < 0)
    {
        zoom -= 0.1f;

        if (zoom < 0.1)
        {
            zoom = 0.1;
        }
    }

    update();
}

