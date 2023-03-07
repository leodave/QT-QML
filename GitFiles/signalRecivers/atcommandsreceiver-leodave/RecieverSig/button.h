#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>

class Button : public QWidget
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);

private:
    QPushButton button;

public:
    void setButtonName(QString buttonName);
    void setButtonSize(int w, int h);
signals:
    void onClicked(QString button);
public slots:
    void writeButtonName();




    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // BUTTON_H
