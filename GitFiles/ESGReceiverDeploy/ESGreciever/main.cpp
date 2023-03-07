#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "filerecievergraphic.h"
#include "filereciever.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    //qmlRegisterType<FileRecieverGraphic>("FileRecieverGraphic.File",1,0,"FileRecieverGrapgic");
    qmlRegisterType<FileReciever>("FileReciever.File",1,0,"FileReciever");
    engine.load(url);
   // FileRecieverGraphic fileRecieverGraphic;
    //fileRecieverGraphic.start("COM2",QSerialPort::Baud9600);
   // FileReciever fileReciever;
    //fileReciever.start("COM2",QSerialPort::Baud9600);

    return app.exec();
}
