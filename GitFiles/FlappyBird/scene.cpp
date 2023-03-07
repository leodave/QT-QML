#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    setUpPillarTimer();


}

void Scene::addBird()
{
    bird = new Bird();
    addItem(bird);
}

void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);

    connect(pillarTimer,&QTimer::timeout,[=](){

        Pillar *pillarItem = new Pillar();
        addItem(pillarItem);
    });
    pillarTimer->start(1000);
}

void Scene::keyPressEvent(QKeyEvent *event)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if(event->button() == Qt::LeftButton){
      bird->shootUp();
  }
  QGraphicsScene::mousePressEvent(event);
}
