#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGlobal>
#include <QTimer>
#include "thread.h"

#include "systeminfo.h"

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
    QTimer timer;
    Thread three;

private slots:
    void updateLabel(double datas);
    void on_dial_valueChanged(int value);
};
#endif // MAINWINDOW_H
