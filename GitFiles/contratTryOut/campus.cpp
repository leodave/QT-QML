#include "campus.h"
#include "ui_campus.h"

Campus::Campus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Campus)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setLabel(QString labeler)
{

}
