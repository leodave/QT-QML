#ifndef SYSTEMINFOLINUX_H
#define SYSTEMINFOLINUX_H

#include "systeminfo.h"
#include "QFile"
#include <QtGlobal>
#include <QVector>
#include <QTextStream>
//#include <QText>

class SystemInfoLinux : public SystemInfo
{
public:
    SystemInfoLinux();

    virtual void init() = 0;
    virtual double cpuLoad() = 0;
    virtual double memoryUsed() = 0;
private:
    QVector<qulonglong> finalCpuLoad;
    QVector<qulonglong> obtainCpuData();
    //qulonglong convertFileTime(const FILETIME &fileTime) const;

};

#endif // SYSTEMINFOLINUX_H
