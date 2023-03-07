#include "button.h"

Button::Button(QWidget *parent)
    : QWidget{parent}
{
    button.setParent(this);
    connect(&button,SIGNAL(clicked()), this, SLOT(writeButtonName()));
}

void Button::setButtonName(QString buttonName)
{
    button.setText(buttonName);
    button.setStyleSheet("Button {background:'blue'}");
}

void Button::setButtonSize(int w, int h)
{
    button.setMinimumHeight(h);
    button.setMinimumWidth(w);
}

void Button::writeButtonName()
{
    emit onClicked(button.text());
}

void Button::resizeEvent(QResizeEvent *event)
{
   resize(200,200);
}
