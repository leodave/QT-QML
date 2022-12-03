#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    reciever.start("Com2",QSerialPort::Baud115200);
    connect(&reciever,SIGNAL(dataRecieved(QVariantList)),this,SLOT(dataAdder(QVariantList)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->widget->resize(width() -10,height() - 10);
    ui->widget->move(5,5);
}

void MainWindow::dataAdder(const QVariantList &newDatas)
{
    for( int i= 0; i < newDatas.size(); i++){
        ui->widget->addData(newDatas[i].toFloat());
    }
}

