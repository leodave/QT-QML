#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;

private slots:
    void diaSeleccionado(QVector<QString> eventos){
        for (int i = 0; i < eventos.size(); i++){
            qDebug() << eventos[i];
        }
    };
};

#endif // CALENDARIO_H
