#ifndef TEMPLATEHANDLER_H
#define TEMPLATEHANDLER_H

#include <QString>
#include <QFile>
#include <QMap>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
class TemplateHandler
{
public:
    TemplateHandler();

    bool addTemplate(const QString &file);
    QStringList obtainLayer();
    void completeLayer(const QString &layer, const QString &content);
     void savePDF(const QString &file);
     bool saveTXT(const QString &file);

private:
    QStringList partesDisplay;

  //  int obtainIndexLayer(const QString &layer);

    QStringList labels;

  //  QList<QList<int>> indexLayers;

    QMap<QString,QString> obtainLayers;



};

#endif // TEMPLATEHANDLER_H
