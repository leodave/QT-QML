#ifndef FILERECIEVERPROJECT_H
#define FILERECIEVERPROJECT_H

//#include "mainwindow.h"

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QVariant>
#include <QLabel>
#include <QWidget>

class FileRecieverProject : public QObject
{
    Q_OBJECT
public:
    explicit FileRecieverProject(QObject *parent = nullptr);

signals:
    void dataReciever(QString data);
    void dataRecieverMinMaxStopTypes(QString data);
protected:
    QSerialPort port;
    QString resultRecieved;


protected slots:
    void readData();
private:
  QByteArray res = "";

public slots:
    void start(const QString &portName, QSerialPort::BaudRate baudRate);
    void stop();
    void clickReciever(QString result);
    void mixMaxStopTypes(QString result);

};

#endif // FILERECIEVERPROJECT_H
