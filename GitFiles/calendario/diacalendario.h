#ifndef DIACALENDARIO_H
#define DIACALENDARIO_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMouseEvent>

class diaCalendario : public QWidget
{
    Q_OBJECT
private:
    QFrame recuardo;
    QLabel fecha;
    QLabel indicadorEventos;
    QVector<QString> eventos;
    QLabel eventIndicator;

public:
    explicit diaCalendario(QWidget *parent = nullptr);
    void setFecha(int f);
     int getFecha();
    void resize(int w, int h);
    void mouseReleaseEvent(QMouseEvent *e);
    void agregarEvento(QString nuevoEvento);
    void mouseMoveEvent(QMouseEvent *e);




signals:
    void diaClickeado(int f);
    void diaHovered(const QVector<QString> &evs, int fecha);
   // void



};

#endif // DIACALENDARIO_H
