#ifndef FILERECIEVERGRAPHIC_H
#define FILERECIEVERGRAPHIC_H

#include <QObject>
#include "filereciever.h"

#include <QtSerialPort/QSerialPort>

class FileRecieverGraphic : public QObject
{
    Q_OBJECT
public:
    explicit FileRecieverGraphic(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void start(const QString &portName, QSerialPort::BaudRate baudRate);
    Q_INVOKABLE void stop();


signals:
    Q_INVOKABLE void dataRecieved(const QVariantList  data);

private:
    FileReciever filereceiver;

};

#endif // FILERECIEVERGRAPHIC_H
