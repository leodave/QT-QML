#ifndef FILERECIEVER_H
#define FILERECIEVER_H

#include <QObject>

class FileReciever : public QObject
{
    Q_OBJECT
public:
    explicit FileReciever(QObject *parent = nullptr);

signals:

};

#endif // FILERECIEVER_H
