#include "systeminfowindows.h"

SystemInfoWindows::SystemInfoWindows() : SystemInfo()
{

}

void SystemInfoWindows::init()
{
   finalCpuLoad = obtainCpuData();
}

double SystemInfoWindows::cpuLoad()
{
    QVector<qulonglong> oldDatas = finalCpuLoad;
    QVector<qulonglong> newDatas = obtainCpuData();
    finalCpuLoad = newDatas;

            qulonglong idleActual = newDatas[0] - oldDatas[0];
            qulonglong kernelActual = newDatas[1] - oldDatas[1];
            qulonglong userActual = newDatas[2] - oldDatas[2];

            qulonglong systemLoad = kernelActual + userActual;

           double percentageLoad = (systemLoad - idleActual) * 100.00 / systemLoad;

            return qBound(0.0,percentageLoad,100.0);
}

double SystemInfoWindows::memoryUsed()
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);

    GlobalMemoryStatusEx(&memoryStatus);
    qulonglong usedMemory = memoryStatus.ullTotalPhys - memoryStatus.ullAvailPhys;

    return (double)usedMemory / memoryStatus.ullTotalPhys * 100.00;
}

QVector<qulonglong> SystemInfoWindows::obtainCpuData()
{
    FILETIME idle,kernel,user;

    GetSystemTimes(&idle,&kernel,&user);

    QVector<qulonglong> returnData;
    returnData.append(convertFileTime(idle));
    returnData.append(convertFileTime(kernel));
    returnData.append(convertFileTime(user));



    return returnData;
}

qulonglong SystemInfoWindows::convertFileTime(const FILETIME &fileTime) const
{
    ULARGE_INTEGER largeInteger;
    largeInteger.LowPart = fileTime.dwLowDateTime;
    largeInteger.HighPart = fileTime.dwHighDateTime;

    return largeInteger.QuadPart;

}
