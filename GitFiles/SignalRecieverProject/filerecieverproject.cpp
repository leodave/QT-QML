#include "filerecieverproject.h"



FileRecieverProject::FileRecieverProject(QObject *parent)
    : QObject{parent}
{

    connect(&port,SIGNAL(readyRead()),this, SLOT(readData()));

}

void FileRecieverProject::readData()
{
    //qDebug() << "hyyyy";

    while (port.bytesAvailable()) {
        res.append(port.readAll());
    }
   // qDebug() << res;
    emit dataReciever(res);
  // ui->widget_3->setLabel(res)

}

void FileRecieverProject::start(const QString &portName, QSerialPort::BaudRate baudRate)
{
    port.setPortName(portName);
    port.setBaudRate(baudRate);
    port.setStopBits(QSerialPort::TwoStop);
    port.setParity(QSerialPort::NoParity);
    port.open(QIODevice::ReadWrite);

    if(port.isOpen()){
        //buffer = (QVariantList) malloc(100 * sizeof(QVariantList ));
        //emit started();
        qDebug() << "Port open";
        port.write(resultRecieved.toLatin1());

    }else {
        qDebug() << "port not open";
        //emit portError();
    }
}

void FileRecieverProject::stop()
{

}


void FileRecieverProject::clickReciever(QString result)
{
    resultRecieved = result;
    start("COM2",QSerialPort::Baud115200);

}
