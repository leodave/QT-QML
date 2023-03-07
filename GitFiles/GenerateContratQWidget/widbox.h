#ifndef WIDBOX_H
#define WIDBOX_H

#include <QWidget>
#include <QWidget>
#include "layer.h"
#include <QList>
#include <QVBoxLayout>

namespace Ui {
class WidBox;
}

class WidBox : public QWidget
{
    Q_OBJECT

public:
    explicit WidBox(QWidget *parent = nullptr);
    ~WidBox();
    void addLayer(QString label);
    int countLayer();
    QString labelAt(int i);
    QString lineEditAt(int i);
    int find(QString label);

private:
    Ui::WidBox *ui;
    Ui::widgetBox *ui;
    QList<Layer*> layer;
    QVBoxLayout *layout;
};

#endif // WIDBOX_H
