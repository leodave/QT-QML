#ifndef TEMPLATEINTERFACE_H
#define TEMPLATEINTERFACE_H

#include <QObject>
#include "templatehandler.h"

class TemplateInterface : public QObject
{
    Q_OBJECT
public:
    explicit TemplateInterface(QObject *parent = nullptr);

    Q_INVOKABLE bool addTemplate(const QString &file);
    Q_INVOKABLE QStringList obtainLayer();
    Q_INVOKABLE void completeLayer(const QString &layer, const QString &content);
    Q_INVOKABLE void savePDF(const QString &file);
    Q_INVOKABLE bool saveTXT(const QString &file);


signals:

private:
    TemplateHandler templatehandler;

};

#endif // TEMPLATEINTERFACE_H
