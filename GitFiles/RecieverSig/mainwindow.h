#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QList>

#include "openglgraphicsignal.h"
#include "filerecieverproject.h"
#include "button.h"

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
    void resizeEvent(QResizeEvent* event) override;


public slots:
    void recievedData(QString data);
    void generateButtons(QList<QString> datas);
    void buttonNameReciever(QString name);
private:
    Ui::MainWindow *ui;
    OpenGlGraphicSignal openGl;
    FileRecieverProject fileReciever;
    QList<QString> newData;
    QList<QString> newestData;
    QList<float> newestData2;
    QList<Button*> groupButton;
    Button button;

private slots:
    void on_OpenPort_clicked();
    void on_ATSIGNALS_clicked();
    void on_ATSTART_clicked();

    void on_ATSTOP_clicked();

    void on_ATMAX_clicked();

    void on_ATMIN_clicked();

    void on_ATCURR_clicked();

    void on_COM1_clicked();

    void on_COM2_clicked();

signals:
    void arraySent(QList<QString> datas);

};
#endif // MAINWINDOW_H
