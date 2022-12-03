#ifndef SERIALGRAPHIC_H
#define SERIALGRAPHIC_H

#include <QObject>
#include "filesend.h"

class SerialGraphic : public QObject
{
    Q_OBJECT
public:
    explicit SerialGraphic(QObject *parent = nullptr);
    Q_INVOKABLE void start(const QString &signalFile,QString portName,float freq,QSerialPort::BaudRate baudRate);
    Q_INVOKABLE void stop();

signals:
private:
    FileSend filesend;

};

#endif // SERIALGRAPHIC_H
