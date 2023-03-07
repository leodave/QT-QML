#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //graphicSignal.setParent(this);
    connect(&filereciever,SIGNAL(dataReciever(QString)),ui->widget_3,SLOT(setLabel(QString)));
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ATSIGNAL_clicked()
{
    filereciever.clickReciever("AT+SIGNALS=?");
   // ui->widget_3->setLabel("hey");
}


void MainWindow::on_ATCURR_clicked()
{
    filereciever.clickReciever("AT+CURR");
}


void MainWindow::on_ATSTART_clicked()
{
    filereciever.clickReciever("AT+START");
}


void MainWindow::on_ATSTOP_clicked()
{
    filereciever.clickReciever("AT+STOP");
}


void MainWindow::on_ATMAX_clicked()
{
    filereciever.clickReciever("AT+MAX");
}


void MainWindow::on_ATMIN_clicked()
{
    filereciever.clickReciever("AT+MIN");
}


void MainWindow::on_ATTRAINGULAR_clicked()
{
    filereciever.clickReciever("AT+SIGNAL=TRAINGULAR");
}


void MainWindow::on_ATSINE_clicked()
{
    filereciever.clickReciever("AT+SIGNAL=SINE");
}


void MainWindow::on_ATSQUARE_clicked()
{
    filereciever.clickReciever("AT+SIGNAL=SQUARE");
}


void MainWindow::on_ATRAND_clicked()
{
    filereciever.clickReciever("AT+SIGNAL=RAND");
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    //label.resize(width(), label.height());
}

