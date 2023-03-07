#ifndef DIALOGAGREGAREVENTO_H
#define DIALOGAGREGAREVENTO_H

#include <QDialog>

namespace Ui {
class Dialogagregarevento;
}

class Dialogagregarevento : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogagregarevento(QWidget *parent = nullptr);
    ~Dialogagregarevento();

private:
    Ui::Dialogagregarevento *ui;
};

#endif // DIALOGAGREGAREVENTO_H
