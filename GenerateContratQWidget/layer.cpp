#include "layer.h"




Layer::Layer(QWidget *parent) :
    QWidget(parent)

{
    label.setParent(this);
    lineEdit.setParent(this);

    label.setText("label");
    label.adjustSize();
    label.move(10,0);
    label.setFixedHeight(label.height());

    lineEdit.setText("");
    lineEdit.adjustSize();
    lineEdit.move(10,label.height()+ 5);
    lineEdit.setFixedHeight(lineEdit.height());

    setFixedHeight(label.height() + 10 + lineEdit.height()+ 10);

}


void Layer::setLabel(QString labeler)
{
    label.setText(labeler);
}

QString Layer::getLabel()
{
    return label.text();
}

QString Layer::getLineEdit()
{
    return lineEdit.text();
}

void Layer::resizeEvent(QResizeEvent *event)
{
    label.resize(width(), label.height());
    lineEdit.resize(width(), lineEdit.height());
}

