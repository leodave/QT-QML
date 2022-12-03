#ifndef SERIALSENDER_H
#define SERIALSENDER_H

#include <QObject>

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QTimer>

class SerialSender : public QObject
{
    Q_OBJECT
public:
    explicit SerialSender(QObject *parent = nullptr);

    Q_INVOKABLE QStringList listAvailablePorts();

    Q_PROPERTY(QString PortName READ getPortName WRITE setPortName NOTIFY portNameChanged);

private:
    QString portName;

    void setPortName(const QString &name);

    QString getPortName();

    QSerialPort port;

    QTimer timer;

signals:
    void portNameChanged(QString name);

    void valueRecieved(char value);

public slots:
    Q_INVOKABLE void openPort();

    Q_INVOKABLE void closePort();

    Q_INVOKABLE void sendByte(char data);

    Q_INVOKABLE void sendString(const QString &data);

private slots:
    void readByte();

};

#endif // SERIALSENDER_H
