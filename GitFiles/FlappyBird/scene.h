#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include "pillar.h"
#include "bird.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void addBird();

signals:

private:
    void setUpPillarTimer();
    QTimer *pillarTimer;
    Bird *bird;


    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
