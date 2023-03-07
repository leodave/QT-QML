#include "thread.h"
#include "QDebug"

Thread::Thread()
{
   running = true;
}

void Thread::run()
{
    while(true) {
        mutex.lock();
        if(!running){
            running = true;
            mutex.unlock();
            break;
        }
        mutex.unlock();
        emit changeLabel(texto);
    }
  //  mutex.lock();
//    while(running) {

//        //mutex.unlock();
//        emit changeLabel(texto);
//    }
    //mutex.unlock();
}

void Thread::stop()
{
    QMutexLocker locker(&mutex);
    //mutex.lock();
    running = false;
    //mutex.unlock();
}

void Thread::setText(const QString &str)
{
    texto = str;
}

