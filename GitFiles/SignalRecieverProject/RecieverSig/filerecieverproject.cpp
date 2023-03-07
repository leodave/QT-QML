#include "filerecieverproject.h"



FileRecieverProject::FileRecieverProject(QObject *parent)
    : QObject{parent}
{

    connect(&port,SIGNAL(readyRead()),this, SLOT(readData()));

}

void FileRecieverProject::readData()
{

    while (port.bytesAvailable()) {
        res.append(port.readAll());
    }
      emit dataReciever(res);
    res = NULL;
}

void FileRecieverProject::start(const QString &portName, QSerialPort::BaudRate baudRate)
{
    port.setPortName(portName);
    port.setBaudRate(baudRate);
    port.setStopBits(QSerialPort::TwoStop);
    port.setParity(QSerialPort::NoParity);
    port.open(QIODevice::ReadWrite);

    if(port.isOpen()){
        qDebug() << "Port open";
    }else {
        qDebug() << "port not open";
    }
}

void FileRecieverProject::stop()
{

}


void FileRecieverProject::clickReciever(QString result)
{
    resultRecieved = result;
    port.write(resultRecieved.toLatin1());

}

void FileRecieverProject::mixMaxStopTypes(QString result)
{

    if(result == "AT+RAND"){
        result = "AT+SIGNAL=RAND";
    }
    if(result == "AT+TRIANGULAR"){
        result = "AT+SIGNAL=TRIANGULAR";
    }
    if(result == "AT+SINE"){
        result = "AT+SIGNAL=SINE";
    }
    if(result == "AT+SQUARE"){
        result = "AT+SIGNAL=SQUARE";
    }
     qDebug() << result;
    resultRecieved = result;
    port.write(resultRecieved.toLatin1());
}
