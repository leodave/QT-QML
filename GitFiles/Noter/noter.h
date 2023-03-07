#ifndef NOTER_H
#define NOTER_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Noter; }
QT_END_NAMESPACE

class Noter : public QMainWindow
{
    Q_OBJECT

public:
    Noter(QWidget *parent = nullptr);
    ~Noter();

private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

private:
    Ui::Noter *ui;
    QString text;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};
#endif // NOTER_H
