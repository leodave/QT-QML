#ifndef BIRD_H
#define BIRD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPropertyAnimation>

class Bird : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit Bird();

    qreal rotation() const;
    void setRotation(qreal newRotation);

    qreal y() const;
    void sety(qreal newY);
    void rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve);
    void shootUp();
    void fallToGround();

    QPropertyAnimation *rotationAnimation;
    QPropertyAnimation *yAnimation;
    qreal groundPosition;

signals:


    void yChanged();

private:
    qreal m_rotation;
    qreal m_y;
 };

#endif // BIRD_H
