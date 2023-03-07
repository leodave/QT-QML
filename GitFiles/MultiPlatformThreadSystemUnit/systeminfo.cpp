#include "systeminfo.h"
//#include "systeminfowindows.h"

#ifdef Q_OS_WIN
    #include "systeminfowindows.h"

#elif defined Q_OS_LINUX
    #include "systeminfolinux.h"

#elif defined Q_OS_MAC
    #include "systeminfomac.h"

#endif
SystemInfo &SystemInfo::instanceIn()
{
#ifdef Q_OS_WIN
   static SystemInfoWindows singleton;

#elif defined Q_OS_LINUX
       static SystemInfoLinux singleton;

#elif defined Q_OS_MAC
       static SystemInfoMac singleton;

#endif
       return singleton;
}

SystemInfo::~SystemInfo()
{

}

SystemInfo::SystemInfo()
{

}
