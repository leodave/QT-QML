#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QArrayData"
#include "QByteArray"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setLayout(new QVBoxLayout());
    connect(ui->actionImport_File,SIGNAL(triggered()),this,SLOT(readFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QFile readFile;
    readFile.setFileName(QFileDialog::getOpenFileName(this,"open","","*.cont"));
    readFile.open(QIODevice::ReadOnly);
     qDebug() << readFile.readAll();
     QString myFile(readFile.readAll());
     //readFile.close();




}




