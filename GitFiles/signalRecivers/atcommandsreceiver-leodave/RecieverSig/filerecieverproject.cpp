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

  /*  if(res.size() <=2 ){
        qDebug() << res;
    }*/
   // qDebug() << res.length();
      emit dataReciever(res);
    res = NULL;

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
    port.write(resultRecieved.toLatin1());
   // start("COM2",QSerialPort::Baud115200);

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
