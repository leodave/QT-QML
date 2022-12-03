#ifndef LAYER_H
#define LAYER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class Layer;
}

class Layer : public QWidget
{
    Q_OBJECT

public:
    void setLabel(QString labeler);
    QString getLabel();
    QString getLineEdit();
    void resizeEvent(QResizeEvent *event);

    explicit Layer(QWidget *parent = nullptr);
    ~Layer();


private:
    Ui::Layer *ui;
    QLabel label;
    QLineEdit lineEdit;
};

#endif // LAYER_H
