#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-250,-300,500,600);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/Images/aa3.jpeg"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                           pixItem->boundingRect().height()/2));
    scene->addLine(-300,0,300,0,QPen(Qt::blue));
    scene->addLine(0,-300,0,300,QPen(Qt::red));

    setFixedHeight(scene->height() - 50);
    setFixedWidth(scene->width()-20);

    /*Pillar *pillar = new Pillar();
    scene->addItem(pillar); */

  //  Bird *bird = new Bird();

    //scene->addItem(bird);
    scene->addBird();


    ui->graphicsView->setScene(scene);

}

Widget::~Widget()
{
    delete ui;
}

