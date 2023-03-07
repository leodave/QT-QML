#include "pillar.h"
#include <QRandomGenerator>
#include <QGraphicsScene>

Pillar::Pillar() : topPillar(new QGraphicsPixmapItem(QPixmap(":/Images/goldpilla.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/Images/goldpilla.png")))
{
    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
                                             topPillar->boundingRect().height()+60));
    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2,60));

    addToGroup(topPillar);
    addToGroup(bottomPillar);

    yPos = QRandomGenerator::global()->bounded(150);
    int xRandomizer = QRandomGenerator::global()->bounded(200);

    setPos(QPoint(0,0) + QPoint (260 + xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(260 + xRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(3000);

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        qDebug() << "animation finished";
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();

}

Pillar::~Pillar()
{
qDebug() << "Deliting Pillar";
}

qreal Pillar::x() const
{
    return m_x;
}

void Pillar::setX(qreal newX)
{
    m_x = newX;
    setPos(QPointF(0,0) + QPointF(newX,yPos));
}
