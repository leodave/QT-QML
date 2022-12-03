#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QObject>
#include <QTimer>
#include "systeminfo.h"

class Thread : public QThread
{
    Q_OBJECT
public:
     Thread();
private:
     QTimer timer;
signals:
     void updateCPU(double dataCPU);
private slots:
     void sendData();
};

#endif // THREAD_H
