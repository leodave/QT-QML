#ifndef FILERECIEVERPROJECT_H
#define FILERECIEVERPROJECT_H

//#include "mainwindow.h"

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QVariant>


class FileRecieverProject : public QObject
{
    Q_OBJECT
public:
    explicit FileRecieverProject(QObject *parent = nullptr);

signals:
    void dataReciever(QString data);
    void dataRecievedNumber(float data);
protected:
    QSerialPort port;
    QString resultRecieved;
protected slots:
    void readData();
private:
  QString res = "";
public slots:
    void start(const QString &portName, QSerialPort::BaudRate baudRate);
    void clickReciever(QString result);
    void mixMaxStopTypes(QString result);


};

#endif // FILERECIEVERPROJECT_H
