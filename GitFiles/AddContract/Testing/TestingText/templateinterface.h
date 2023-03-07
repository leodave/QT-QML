#ifndef TEMPLATEINTERFACE_H
#define TEMPLATEINTERFACE_H

#include <QObject>

class TemplateInterface : public QObject
{
    Q_OBJECT
public:
    explicit TemplateInterface(QObject *parent = nullptr);

signals:

};

#endif // TEMPLATEINTERFACE_H
