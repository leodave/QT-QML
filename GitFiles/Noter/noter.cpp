#include "noter.h"
#include "./ui_noter.h"

Noter::Noter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noter)
{
    ui->setupUi(this);
}

Noter::~Noter()
{
    delete ui;
}


void Noter::on_actionNew_File_triggered()
{
    ui->textEdit->setPlainText("");
}


void Noter::on_actionOpen_File_triggered()
{
   QFile file;
   file.setFileName(QFileDialog::getOpenFileName(this,"open file","/Downloads"));
   if(file.open(QIODevice::ReadOnly)){
           text = file.readAll();
          // qDebug() << text;
            ui->textEdit->setPlainText(text);
    }

}


void Noter::on_actionSave_triggered()
{

}


void Noter::on_actionSave_As_triggered()
{
    QFile newFile;
    newFile.setFileName(QFileDialog::getSaveFileName(this,"Save As"));
    if(newFile.open(QIODevice::WriteOnly)){
        QTextStream stream(&newFile);
        stream << ui->textEdit->toPlainText();
        qDebug() << "hello";
    }

}


void Noter::on_actionPrint_triggered()
{

}


void Noter::on_actionExit_triggered()
{
    this->close();
}

void Noter::resizeEvent(QResizeEvent *event)
{
   // resize(1000,1000);
    ui->textEdit->resize(width()-100,height()-(ui->statusbar->height()+80));
    qDebug() << this->width();
     qDebug() << ui->textEdit->width();
}

