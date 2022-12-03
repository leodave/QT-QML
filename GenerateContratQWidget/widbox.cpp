#include "widbox.h"
#include "ui_widbox.h"

WidBox::WidBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidBox)
{
    ui->setupUi(this);
     layout->setParent(this);
}

WidBox::~WidBox()
{
    delete ui;
}
