#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filereciever.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
    FileReciever reciever;

private slots:
    void dataAdder(const QVariantList &newDatas);
};
#endif // MAINWINDOW_H
