#include "graphicsignal.h"

GraphicSignal::GraphicSignal(QWidget *parent)
    : QWidget{parent}
{
    label.setParent(this);
    label.setText("hell");
    label.adjustSize();
    label.move(10, 10);
    label.setMinimumHeight(200);


}

void GraphicSignal::resizeEvent(QResizeEvent *event)
{
    label.resize(width(), label.height());
    if(label.height() >= 200){
        label.clear();
    }
}

void GraphicSignal::setLabel(QString text)
{
    //qDebug() << text;
    label.setText(text);
    label.update();

}

QString GraphicSignal::getLabel()
{
    return label.text();
}
