#ifndef FILESEND_H
#define FILESEND_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QTimer>
#include <QTextStream>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

class FileSend : public QObject
{
    Q_OBJECT
public:
    explicit FileSend(QObject *parent = nullptr);
   // void openFile(const QString &file);
protected:
    QTimer timer;
    QFile file;
    QTextStream text;


    float lastData;
    QSerialPort port;
    QString portName;

protected slots:
    void sendData();
public slots:
     void start(const QString &signalFile,QString portName,float freq,QSerialPort::BaudRate baudRate);
     void stop();


signals:


};

#endif // FILESEND_H
