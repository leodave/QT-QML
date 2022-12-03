#ifndef SERIALGRAPHIC_H
#define SERIALGRAPHIC_H

#include <QObject>

class SerialGraphic : public QObject
{
    Q_OBJECT
public:
    explicit SerialGraphic(QObject *parent = nullptr);

signals:

};

#endif // SERIALGRAPHIC_H
