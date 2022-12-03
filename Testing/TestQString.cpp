#include <QtTest>
// Alt + shift + 0
class TestString : public QObject
{
    Q_OBJECT

private slots:
    void testToUpper();
    void testToUpper_data();
};

void TestString::testToUpper()
{
    /*QString str = "Hola Mundo";
    QVERIFY(str.toUpper() == "HOLA MUNDO");
    QCOMPARE(str.toUpper(), "HOLA MUNDO");*/

    QFETCH(QString, original);
    QFETCH(QString, changeToUpperCase);

    QBENCHMARK {
    QCOMPARE(original.toUpper(),changeToUpperCase);
    }
}

void TestString::testToUpper_data()
{
    QTest::addColumn<QString>("original");
    QTest::addColumn<QString>("changeToUpperCase");

    QTest::addRow("allInLowerCase") << "hola mundo" << "HOLA MUNDO";
    QTest::addRow("UpLowChanges") << "HoLa MuNdO" << "HOLA MUNDO";
    QTest::addRow("allInUpperCase") << "HOLA MUNDO" << "HOLA MUNDO";
}
QTEST_MAIN(TestString);
#include "TestQString.moc"

