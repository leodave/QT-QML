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





void MainWindow::on_pushButton_pressed()
{
    ui->label->setText("hello");
}


void MainWindow::on_pushButton_released()
{
    ui->label->setText("bye");
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(ui->lineEditmio->text());
}

