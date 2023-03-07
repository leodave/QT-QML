#ifndef GRAPHICSIGNAL_H
#define GRAPHICSIGNAL_H

#include <QWidget>
#include <QLabel>

class GraphicSignal : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicSignal(QWidget *parent = nullptr);

signals:

private:
    QWidget widget;
    QLabel label;


    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
public slots:
    void setLabel(QString text);
    QString getLabel();
};

#endif // GRAPHICSIGNAL_H
