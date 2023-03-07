#ifndef FILERECIEVERPROJECT_H
#define FILERECIEVERPROJECT_H

//#include "mainwindow.h"

#include "graphicsignal.h"

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
    void started();
    void portError();

protected:
    QSerialPort port;
    QVariantList buffer;
    QString resultRecieved;


protected slots:
    void readData();
private:
  GraphicSignal grapgicSignal;
  QString res = "";

public slots:
    void start(const QString &portName, QSerialPort::BaudRate baudRate);
    void stop();
    void clickReciever(QString result);

};

#endif // FILERECIEVERPROJECT_H
