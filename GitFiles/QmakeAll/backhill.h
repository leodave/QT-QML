#ifndef BACKHILL_H
#define BACKHILL_H

#include <QObject>
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraInfo>

class BackHill : public QObject
{
    Q_OBJECT
public:
    explicit BackHill(QObject *parent = nullptr);

signals:

};

#endif // BACKHILL_H
