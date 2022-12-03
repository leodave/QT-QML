#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QFrame>
#include <QVector>
#include <QLabel>
#include <QFileDialog>
#include "diacalendario.h"
#include "dialog.h"
//#include "dialogagregarevento.h"

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

    QVector<QFrame*> graphicRepesentation;
    QVector<QLabel*> numerosDias;
   // QVector<QLabel*>
    QVector<diaCalendario*> days;
    Dialog dialog;


   private slots:
    void diaSeleccionado(int daySelected);
    void saveEvent(const QVector<QString> &evs, int fecha);
   // QFile

};
#endif // MAINWINDOW_H
