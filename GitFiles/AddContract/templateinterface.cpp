#include "templateinterface.h"

TemplateInterface::TemplateInterface(QObject *parent)
    : QObject{parent}
{

}

bool TemplateInterface::addTemplate(const QString &file)
{
  return templatehandler.addTemplate(file);
}

QStringList TemplateInterface::obtainLayer()
{
   return templatehandler.obtainLayer();
}

void TemplateInterface::completeLayer(const QString &layer, const QString &content)
{
    templatehandler.completeLayer(layer,content);
}

void TemplateInterface::savePDF(const QString &file)
{
    templatehandler.savePDF(file);
}

bool TemplateInterface::saveTXT(const QString &file)
{
    return templatehandler.saveTXT(file);
}
