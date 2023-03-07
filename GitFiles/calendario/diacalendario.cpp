#include "diacalendario.h"

diaCalendario::diaCalendario(QWidget *parent)
    : QWidget{parent}
{
    recuardo.setParent(this);
    recuardo.setFrameStyle(QFrame::Box);
    //fecha = new QLabel("fecha", &recuardo); if with star
    fecha.setParent(&recuardo);
    indicadorEventos.setParent(&recuardo);
    indicadorEventos.setStyleSheet("QLabel {background:blue;}");
    //setMouseTracking(True);
}

void diaCalendario::setFecha(int f)
{
    fecha.setNum(f);
}

int diaCalendario::getFecha()
{
    return fecha.text().toInt();
}

void diaCalendario::resize(int w, int h)
{
    QWidget::resize(w,h);
    recuardo.resize((int)(w * 0.9), (int)(h * 0.9));
    recuardo.move((int)(w * 0.05),(int)(h * 0.05));
    fecha.move((int)(w * 0.05),(int)(h * 0.05));

    indicadorEventos.resize((int)(w * 0.05),(int)(h * 0.05));
    indicadorEventos.move((int)(w * 0.8),(int)(h * 0.05));

    eventos.append("event 1");
    eventos.append("event 2");

}

void diaCalendario::mouseReleaseEvent(QMouseEvent *e)
{
    emit diaClickeado(this->getFecha());


}

void diaCalendario::agregarEvento(QString nuevoEvento)
{
    eventos.append(nuevoEvento);
}

void diaCalendario::mouseMoveEvent(QMouseEvent *e)
{
    emit diaHovered(eventos,fecha.text().toInt());
}



