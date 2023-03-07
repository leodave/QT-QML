#include "filereciever.h"

FileReciever::FileReciever(QObject *parent)
    : QObject{parent}
{
    connect(&port,SIGNAL(readyRead()),this, SLOT(readData()));
}

void FileReciever::readData()
{
    int dataIndex = 0;
    float readingData;

    buffer.clear();

    while(port.bytesAvailable() >= sizeof(readingData)){
        port.read((char*) &readingData,sizeof(readingData));
       // buffer[dataIndex++] = readData;
        buffer.append(QVariant(readingData));
        dataIndex++;

    }

   // qDebug() << buffer[0];


    emit dataRecieved(buffer);

}

void FileReciever::start(const QString &portName, QSerialPort::BaudRate baudRate)
{
    port.setPortName(portName);
    port.setBaudRate(baudRate);
    port.setStopBits(QSerialPort::TwoStop);
    port.setParity(QSerialPort::NoParity);
    port.open(QIODevice::ReadOnly);

    if(port.isOpen()){
        //buffer = (QVariantList) malloc(100 * sizeof(QVariantList ));
        emit started();
    }else {
        qDebug() << "port not open";
        emit portError();
    }
}

void FileReciever::stop()
{
    /*free(buffer);

    buffer = NULL;*/
}
