#ifndef SYSTEMINFOWINDOWS_H
#define SYSTEMINFOWINDOWS_H

#include "systeminfo.h"
#include "QtGlobal"
#include "windows.h"
#include <QVector>

class SystemInfoWindows : public SystemInfo
{
public:
    SystemInfoWindows();



    // SystemInfo interface


    // SystemInfo interface
public:
    virtual void init() override;
    virtual double cpuLoad() override;
    virtual double memoryUsed() override;

private:
    QVector<qulonglong> finalCpuLoad;
    QVector<qulonglong> obtainCpuData();
    qulonglong convertFileTime(const FILETIME &fileTime) const;
};

#endif // SYSTEMINFOWINDOWS_H
