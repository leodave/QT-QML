#include "thread.h"

Thread::Thread()
    : QThread()
{
    SystemInfo::instanceIn().init();
     connect(&timer,SIGNAL(timeout()),this,SLOT(sendData()));
     timer.start(500);
}

void Thread::sendData()
{
emit updateCPU(SystemInfo::instanceIn().cpuLoad());
}
