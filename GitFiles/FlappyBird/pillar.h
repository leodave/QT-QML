#ifndef PILLAR_H
#define PILLAR_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <qDebug>

class Pillar : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Pillar();
    ~Pillar();

    qreal x() const;
    void setX(qreal newX);

signals:

public slots:

private:
    QGraphicsPixmapItem *topPillar;
    QGraphicsPixmapItem *bottomPillar;
    QPropertyAnimation *xAnimation;

    qreal m_x;
    int yPos;
};

#endif // PILLAR_H
