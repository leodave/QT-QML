#include "templatehandler.h"

TemplateHandler::TemplateHandler()
{

}

bool TemplateHandler::addTemplate(const QString &file)
{
    QFile archivo(file);

    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){

        QString textRead = archivo.readAll();

        partesDisplay = textRead.split("###");

        int layerToComplete = 1;

       /* if(textRead.startsWith("###")){
            layerToComplete = 1;
        }*/
        for(; layerToComplete <partesDisplay.size(); layerToComplete +=2){
            //erase
           // int indicatorLayer = obtainIndexLayer(partesDisplay[layerToComplete]);

            if( !labels.contains(partesDisplay[layerToComplete])){
                labels.append(partesDisplay[layerToComplete]);
               obtainLayers[partesDisplay[layerToComplete]] = "";
            }
        }
        return true;
    }else{
        return false;
    }
}

QStringList TemplateHandler::obtainLayer()
{
    return labels;
}

void TemplateHandler::completeLayer(const QString &layer, const QString &content)
{
    if(labels.contains(layer)){
        obtainLayers[layer] = content;
    }
    qDebug() << obtainLayers;
}

bool TemplateHandler::saveTXT(const QString &file)
{
    for( int i = 1; i < partesDisplay.size(); i+=2){
        partesDisplay[i] = obtainLayers[partesDisplay[i]];
    }
    QFile archivo(file);
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream textArchivo(&archivo);
        textArchivo << partesDisplay.join("");
        qDebug() << textArchivo.readAll();
        archivo.close();
        return true;
    }else {
        return false;
    }

}

void TemplateHandler::savePDF(const QString &file)
{

    for( int i = 1; i < partesDisplay.size(); i+=2){
        partesDisplay[i] = obtainLayers[partesDisplay[i]];
    }

    QString html = partesDisplay.join("");
    html.replace("\r","<br>");
    html.replace("\n","<br>");

    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(file);
    printer.setPageMargins(QMargins(10,20,10,15));
    document.print(&printer);
}



/*int TemplateHandler::obtainIndexLayer(const QString &layer)
{
    for (int index = 0; index < layers.size(); index++){
        if(layers[index] == layer){
            return index ;
        }
    }
    return -1;
}*/
