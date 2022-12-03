#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    threadA.setText("bottonA pressed");
    threadB.setText("bottonB pressed");

     connect(&threadA,SIGNAL(changeLabel(const QString)), this, SLOT(updateLabelA(const QString)));
     connect(&threadB,SIGNAL(changeLabel(const QString)), this, SLOT(updateLabelB(const QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  threadA.start();
}


void MainWindow::on_pushButton_2_clicked()
{
    threadB.start();
}


void MainWindow::on_pushButton_3_clicked()
{
    threadA.stop();
    threadB.stop();
    close();
}

void MainWindow::updateLabelA(const QString &newText)
{
    ui->label->setText(newText);
}

void MainWindow::updateLabelB(const QString &newText)
{
    ui->label_2->setText(newText);
}

