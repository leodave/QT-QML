#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    void stop();
    void setText(const QString &str);
private:
   volatile bool running;
    QString texto;
    QMutex mutex;
protected:
    virtual void run() override;
signals:
    void changeLabel(const QString &str);
};

#endif // THREAD_H
