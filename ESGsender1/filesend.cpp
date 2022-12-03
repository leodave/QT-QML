#include "filesend.h"

FileSend::FileSend(QObject *parent)
    : QObject{parent}
{
    connect(&timer, SIGNAL(timeout()),this,SLOT(sendData()));
}

void FileSend::sendData()
{
    if(file.isOpen()){
        if(text.status() == QTextStream::Ok){
            text >> lastData;
            if(port.isOpen()){
                //port.write(char*) &lastData, sizeOf(lastData);
                port.write(QByteArray::number(lastData));
            }else {
                qDebug() << "port mot opened from send data";
                stop();
            }
            qDebug() << lastData;
        }else {
             qDebug() << "notWorking SendData";
             stop();
        }
    }
}

void FileSend::start(const QString &signalFile,QString portName, float freq, QSerialPort::BaudRate baudRate)
{
    file.setFileName(signalFile);
    text.setDevice(&file);
    file.open(QIODevice::ReadOnly |QIODevice::Text);
    if(file.isOpen()){
        timer.start((5000/freq));
        port.setBaudRate(baudRate);
        port.setStopBits(QSerialPort::TwoStop);
        port.setPortName(portName);
        port.open(QIODevice::WriteOnly);
        if(port.isOpen()){
            qDebug() << "port Opened";
        }else {
            qDebug() << "port not open";
        }

    }else {
        qDebug() << "notWorking";
        stop();
    }
}

void FileSend::stop()
{
    timer.stop();
    file.close();

}
