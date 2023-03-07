#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "layer.h"
#include <QList>
#include <QVBoxLayout>



class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();
    void addLayer(QString label);
    int countLayer();
    QString labelAt(int i);
    QString lineEditAt(int i);
    int find(QString label);
private:

    QList<Layer*> layer;
    QVBoxLayout *layout;
};

#endif // WIDGET_H
