#include <QTest>

#include "../../templatehandler.h"

class TestHandler : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testObtainLayers();
    void testCompleteLayer();
    void testObtainLayers_data();
    void testCompleteLayer_data();


    QStringList obtainLayersOfFile(const QString &file);
    QString completeLayer(const QString &file);

};


void TestHandler::initTestCase()
{
    QFile testFile1("testFile1.cont");
    testFile1.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream textFile1(&testFile1);

    textFile1 << "texto ###campo1### texto ###campo2### texto ###campo3### texto";
    testFile1.close();

    QFile testFile2("testFile2.cont");
    testFile2.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream textFile2(&testFile2);

    textFile2 << "texto ###campo1### texto ###campo2### texto ###campo3### texto";
    testFile2.close();

    QFile testFile3("testFile3.cont");
    testFile3.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream textFile3(&testFile3);

    textFile3 << "texto ###campo1### texto ###campo2### texto ###campo3### mas texto.\n";
    testFile3.close();

    QFile testFile4("testFile4.cont");
    testFile4.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream textFile4(&testFile4);

    textFile4 << "###campo1### texto ###campo2### texto ###campo3### mas texto.\n";
    testFile4.close();
}

void TestHandler::cleanupTestCase()
{
    QFile::remove("testFile1.cont");
    QFile::remove("testFile2.cont");
    QFile::remove("testFile3.cont");
    QFile::remove("testFile4.cont");

    QFile::remove("testFile1Modified.txt");
    QFile::remove("testFile2Modified.txt");
    QFile::remove("testFile3Modified.txt");
    QFile::remove("testFile4Modified.txt");

}



void TestHandler::testObtainLayers()
{
   QFETCH(QString,nameFile);
   QFETCH(QStringList, layersObtained);

   QBENCHMARK {
       QCOMPARE(obtainLayersOfFile(nameFile),layersObtained);
   }
}

void TestHandler::testCompleteLayer()
{
    QFETCH(QString,nameArchivo);
    QFETCH(QString, textModified);

    QBENCHMARK {
        QCOMPARE(completeLayer(nameArchivo),textModified);
    }
}



void TestHandler::testObtainLayers_data()
{
    QTest::addColumn<QString>("nameFile");
    QTest::addColumn<QStringList>("layersObtained");

    QStringList lista;

    lista.append("campo1");
    lista.append("campo2");
    lista.append("campo3");

    QTest::addRow("archivo1") << "testFile1.cont" << lista;
    QTest::addRow("archivo2") << "testFile2.cont" << lista;
    QTest::addRow("archivo3") << "testFile3.cont" << lista;
    QTest::addRow("archivo4") << "testFile4.cont" << lista;
}

void TestHandler::testCompleteLayer_data()
{
    QTest::addColumn<QString>("nameArchivo");
     QTest::addColumn<QString>("textModified");

     QTest::addRow("archivo1") << "testFile1.cont" << "texto Primer layer modified texto Este el el segundo layer texto Campito texto";
     QTest::addRow("archivo2") << "testFile2.cont" << "texto Primer layer modified texto Este el el segundo layer texto Campito texto";

     QTest::addRow("archivo3") << "testFile3.cont" << "texto Primer layer modified texto Este el el segundo layer texto Campito mas texto.\n";
     QTest::addRow("archivo4") << "testFile4.cont" << "Primer layer modified texto Este el el segundo layer texto Campito mas texto.\n";
}

QStringList TestHandler::obtainLayersOfFile(const QString &file)
{
    TemplateHandler templateHandler;
    templateHandler.addTemplate(file);
    return templateHandler.obtainLayer();

}

QString TestHandler::completeLayer(const QString &file)
{
    TemplateHandler templatehandler;
    templatehandler.addTemplate(file);
    templatehandler.completeLayer("campo1","Primer layer modified");
    templatehandler.completeLayer("campo2","Este el el segundo layer");
    templatehandler.completeLayer("campo3","Campito");

    templatehandler.saveTXT(file.split(".")[0] + "Modified.txt");
    templatehandler.savePDF(file.split(".")[0] + "Modifieded.pdf");
    QFile archivoModificado(file.split(".")[0] + "Modified.txt");
    archivoModificado.open(QIODevice::ReadOnly | QIODevice::Text);
    QString textModified = archivoModificado.readAll();
    archivoModificado.close();
    return textModified;

}

QTEST_MAIN(TestHandler)
#include "TestHandler.moc"
