#include "bird.h"
#include "scene.h"

Bird::Bird()
{
    QTimer *birdWingsTimer = new QTimer(this);
    QPixmap pix(":/Images/abiyup.png");
    pix = pix.scaled(pix.size() / 3);

    connect(birdWingsTimer,&QTimer::timeout,[=](){
        setPixmap(pix);
    });

     birdWingsTimer->start(80);

     groundPosition = scenePos().y() +200;

     yAnimation = new QPropertyAnimation(this,"y",this);
     yAnimation->setStartValue(scenePos().y());
     yAnimation->setEndValue(groundPosition);
     yAnimation->setEasingCurve(QEasingCurve::InQuad);
     yAnimation->setDuration(1000);

     yAnimation->start();

     rotationAnimation = new QPropertyAnimation(this,"rotation",this);
     rotateTo(90,1200,QEasingCurve::InQuad);

}

qreal Bird::rotation() const
{
    return m_rotation;
}

void Bird::setRotation(qreal newRotation)
{
    m_rotation = newRotation;

    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(newRotation);
    t.translate(-c.x(),-c.y());
    setTransform(t);
}

qreal Bird::y() const
{
    return m_y;
}

void Bird::sety(qreal newY)
{
    moveBy(0,newY-m_y);
    m_y = newY;

}

void Bird::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);

    rotationAnimation->start();

}

void Bird::shootUp()
{
    yAnimation->stop();
    rotationAnimation->stop();

    qreal curPosY = y();

    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY - scene()->sceneRect().height()/20);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    yAnimation->start();

    connect(yAnimation,&QPropertyAnimation::finished,[=](){
        fallToGround();
    });

    rotateTo(-20,200,QEasingCurve::OutCubic);

}

void Bird::fallToGround()
{
 if(y() < groundPosition){
     rotationAnimation->stop();
     //yAnimation->stop();

     yAnimation->setStartValue(y());
     yAnimation->setEndValue(groundPosition);
     yAnimation->setEasingCurve(QEasingCurve::InQuad);
     yAnimation->setDuration(1000);
     yAnimation->start();

     rotateTo(90,1100,QEasingCurve::InCubic);
 }
}
