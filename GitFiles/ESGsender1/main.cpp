#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialgraphic.h"

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
    qmlRegisterType<SerialGraphic>("SerialGraphic.File",1,0,"SerialGraphic");
    engine.load(url);

    //SerialGraphic serialgraphic;
    //serialgraphic.start("ESG.txt","COM1",500,QSerialPort::Baud9600);


    return app.exec();
}
