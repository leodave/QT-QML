#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_3->setText(QString("Nombre\n" + ui->lineEdit->text() +  "\n Apellido\n " + ui->lineEdit_2->text()));
}





void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->spinBox->setValue(arg1.toInt());
    ui->horizontalSlider->setValue(arg1.toInt());
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->lineEdit_3->setText(QString::number(arg1));
    ui->horizontalSlider->setValue(arg1);
}





void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit_3->setText(QString::number(value));
    ui->spinBox->setValue(value);
}

