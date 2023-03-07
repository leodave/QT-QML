#ifndef FILERECIEVER_H
#define FILERECIEVER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QVariant>

class FileReciever : public QObject
{
    Q_OBJECT
public:
    explicit FileReciever(QObject *parent = nullptr);

signals:
    void dataRecieved(QVariantList  data);
    void started();
    void portError();
protected:
    QSerialPort port;
    QVariantList buffer;

protected slots:
    void readData();


public slots:
    void start(const QString &portName, QSerialPort::BaudRate baudRate);
    void stop();

};

#endif // FILERECIEVER_H
