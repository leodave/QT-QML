#ifndef LAYER_H
#define LAYER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>


class Layer : public QWidget
{
    Q_OBJECT

public:

    void setLabel(QString labeler);
    QString getLabel();
    QString getLineEdit();
    void resizeEvent(QResizeEvent *event);

    explicit Layer(QWidget *parent = nullptr);



private:

    QLabel label;
    QLineEdit lineEdit;
};

#endif // LAYER_H
