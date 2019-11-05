#include "MonitorSize.h"

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor,
                              HDC      hdcMonitor,
                              LPRECT   lprcMonitor,
                              LPARAM   dwData)
{
    MONITORINFO info;
    info.cbSize = sizeof(info);
    if (GetMonitorInfo(hMonitor, &info))
    {
        Monitor_Size_X = abs(info.rcMonitor.left - info.rcMonitor.right);
        Monitor_Size_Y = abs(info.rcMonitor.top  - info.rcMonitor.bottom);
    }
    return TRUE;
}