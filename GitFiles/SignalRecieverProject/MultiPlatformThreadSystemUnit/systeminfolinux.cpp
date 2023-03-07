#include "systeminfolinux.h"
#include <sys/types.h>
#include <sys/sysinfo.h>

SystemInfoLinux::SystemInfoLinux() : SystemInfo()
{

}

void SystemInfoLinux::init()
{
    finalCpuLoad = obtainCpuData();
}

double SystemInfoLinux::cpuLoad()
{
    QVector<qulonglong> oldDatas = finalCpuLoad;
    QVector<qulonglong> newDatas = obtainCpuData();
    finalCpuLoad = newDatas;

            qulonglong userActual = newDatas[0] - oldDatas[0];
            qulonglong userNiceActual = newDatas[1] - oldDatas[1];
            qulonglong systemActual = newDatas[2] - oldDatas[2];
            qulonglong idleActual = newDatas[3] - oldDatas[3];


            qulonglong totalUsed = userActual + userNiceActual + systemActual;
            qulonglong total = totalUsed + idleActual;

           double percentageLoad = (double)(totalUsed - total) * 100.00;

            return qBound(0.0,percentageLoad,100.0);
}

double SystemInfoLinux::memoryUsed()
{

}

QVector<qulonglong> SystemInfoLinux::obtainCpuData()
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);

    QByteArray firstLine = file.readLine();
    file.close();

    qulonglong user, userNice, system, idle;

    QTextStream text(firstLine);

   // QText firstLine;

    text >> user;
    text >> userNice;
    text >> system;
    text >> idle;

    QVector<qulonglong> returnedDatas;

    returnedDatas.append(user);
    returnedDatas.append(userNice);
    returnedDatas.append(system);
    returnedDatas.append(idle);

    return returnedDatas;
}
