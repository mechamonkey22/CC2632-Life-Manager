#ifndef ALGORITMOTRAB_MONITORSIZE_H
#define ALGORITMOTRAB_MONITORSIZE_H

#include <windows.h>
#include <stdio.h>

int Monitor_Size_X;
int Monitor_Size_Y;

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);

#endif
