#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QObject>
#include <QPainter>
#include <QPaintEvent>


class Graphic : public QWidget
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = nullptr);
    void newDatas(double nD);

signals:


protected:
    virtual void paintEvent(QPaintEvent *event);
private:
    QVector<double> datas;
};

#endif // GRAPHIC_H
