#include "graphic.h"

Graphic::Graphic(QWidget *parent)
    : QWidget{parent}
{
    //setBackgroundRole(QPalette::Light);
}

void Graphic::newDatas(double nD)
{
    datas.append(nD);

    if(datas.size() > (width()/10)){
        datas.removeFirst();

    }
    update();
}

void Graphic::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//painter.setPen(QPen(Qt::black, Qt::DotLine, Qt::RoundCap));
   painter.setPen(Qt::black);
   //painter.setBrush(Qt::green);
   // painter.drawEllipse(50,50,100,100);

    for( int i = 0; i < (datas.size() -1); i++){
        painter.drawLine(i *10,height() - (datas[i]*10), (i + 1) * 10,(height() - (datas[i+1]*10)));
    }
}
