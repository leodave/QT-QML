#include "serialgraphic.h"

SerialGraphic::SerialGraphic(QObject *parent)
    : QObject{parent}
{

}

void SerialGraphic::start(const QString &signalFile, QString portName, float freq, QSerialPort::BaudRate baudRate)
{

    //filesend.start("ESG.txt","COM1",500,QSerialPort::Baud9600);
    filesend.start(signalFile,portName,freq,baudRate);
}

void SerialGraphic::stop()
{
    filesend.stop();
}

