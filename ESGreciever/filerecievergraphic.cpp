#include "filerecievergraphic.h"

FileRecieverGraphic::FileRecieverGraphic(QObject *parent)
    : QObject{parent}
{
    
}

void FileRecieverGraphic::start(const QString &portName, QSerialPort::BaudRate baudRate)
{
    filereceiver.start(portName,baudRate);
   // emit dataRecieved(filereceiver.buffer);
}

void FileRecieverGraphic::stop()
{
    filereceiver.stop();
}




