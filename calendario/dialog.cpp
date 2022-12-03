#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::show()
{
    ui->lineEdit->clear();
    QDialog::show();
}

QString Dialog::getEvent()
{
 return ui->lineEdit->text();
}
