#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filerecieverproject.h"
//#include "graphicsignal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ATSIGNAL_clicked();

    void on_ATCURR_clicked();

    void on_ATSTART_clicked();

    void on_ATSTOP_clicked();

    void on_ATMAX_clicked();

    void on_ATMIN_clicked();

    void on_ATTRAINGULAR_clicked();

    void on_ATSINE_clicked();

    void on_ATSQUARE_clicked();

    void on_ATRAND_clicked();

private:
    Ui::MainWindow *ui;

    FileRecieverProject filereciever;
  //  GraphicSignal graphicSignal;
protected:
    QString result;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
