#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include "QFile"
#include "QFileDialog"
#include "QString"
#include <QtPrintSupport/QPrinter>
#include <QResizeEvent>
#include <QMap>
#include <QMapIterator>
#include <QScrollArea>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    widget *wid;
    QVector <QVector  <int> > layersIndicators;
    QStringList templateParts;

protected:
    void resizeEvent(QResizeEvent* event);

public slots:
    void openTemplate();
    void generatePDF();


};
#endif // MAINWINDOW_H
