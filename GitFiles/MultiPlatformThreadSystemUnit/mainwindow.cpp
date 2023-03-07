#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //SystemInfo::instanceIn().init();
//    connect(&timer,SIGNAL(timeout()),this,SLOT(updateLabel()));
//    timer.start(500);
    connect(&three,SIGNAL(updateCPU(double)), this, SLOT(updateLabel(double)));

//    SystemInfo a();
//    SystemInfo b = a;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel(double datas)
{
 ui->label->setText(QString::number(datas));
 ui->widget->newDatas(datas);
}


void MainWindow::on_dial_valueChanged(int value)
{
//ui->widget->updateZoom(value);
}

