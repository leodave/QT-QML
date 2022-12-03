#include "serialsender.h"
#include <QDebug>

SerialSender::SerialSender(QObject *parent)
    : QObject{parent}
{
    timer.start(1);

    connect(&timer,SIGNAL(timeout()),this,SLOT(readByte()));
}

QStringList SerialSender::listAvailablePorts()
{
    QSerialPortInfo info;



    QStringList portList;


    for(int i = 0; i < info.availablePorts().size(); i++){
        portList.append(info.availablePorts()[i].portName());
    }
    qDebug() << info.availablePorts().size();
    return portList;
}

void SerialSender::setPortName(const QString &name)
{
    portName = name;

    port.setPortName(name);
    port.setBaudRate(9600);

    emit portNameChanged(portName);
}

QString SerialSender::getPortName()
{
    return portName;
}

void SerialSender::openPort()
{
    port.open(QIODevice::ReadWrite);

    if(port.isOpen()){
        qDebug() << "port open successfully.";
    }else {
        qDebug() << "Error in opening the port.";
    }
}

void SerialSender::closePort()
{
    port.close();
    qDebug() << "port closed succesfully";
}

void SerialSender::sendByte(char data)
{
    if(port.isOpen()){
        port.write(&data);
    }
}

void SerialSender::sendString(const QString &data)
{
    if(port.isOpen()){
        port.write(data.toLatin1());
    }

}

void SerialSender::readByte()
{
    if(port.bytesAvailable() > 0){
        char data1;

        port.read(&data1,1);

        emit valueRecieved(data1);

    }
}
