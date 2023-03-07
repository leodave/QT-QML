#include "mainwindow.h"
#include "./mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image(QFileDialog::getOpenFileName());
    ui->label->setPixmap(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

