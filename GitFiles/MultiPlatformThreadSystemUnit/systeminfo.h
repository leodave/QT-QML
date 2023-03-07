#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QtGlobal>


class SystemInfo
{
public:
    static SystemInfo& instanceIn();
    virtual   ~SystemInfo();

    virtual void init() = 0;
    virtual double cpuLoad() = 0;
    virtual double memoryUsed() = 0;

protected:
    explicit  SystemInfo();

private:
    SystemInfo (const SystemInfo &other);
    SystemInfo &operator =(const SystemInfo &other);
};

#endif // SYSTEMINFO_H
