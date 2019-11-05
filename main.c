#include <stdio.h>
#include <iup.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Structs.h"
#include <windows.h>
#include "MenuScreen.h"
#include "MainScreen.h"
#include "MonitorSize.h"
#include "UserRegister.h"
#include "UserLogin.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Portuguese");

    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);

    printf("Monitor Resolution: %dx%d\n", Monitor_Size_X, Monitor_Size_Y);

    char monitorX[5] = "";
    char monitorY[6] = "";
    char resolution[9] = "";

    char monitorX1[5] = "";
    char monitorY1[6] = "";
    char resolution1[9] = "";

    sprintf(monitorX, "%d", (Monitor_Size_X)/2 - 5);
    sprintf(monitorY, "x%d", (Monitor_Size_Y)/2 - 15);
    strcat(resolution, monitorX);
    strcat(resolution, monitorY);

    sprintf(monitorX1, "%d", (Monitor_Size_X)/6);
    sprintf(monitorY1, "x%d", (Monitor_Size_Y)/6);
    strcat(resolution1, monitorX1);
    strcat(resolution1, monitorY1);

    Win.State = MENU;
    strcpy(Win.MonitorResolution, resolution1);
    strcpy(Win.TextSize, "90x14");

    while(1){
        int x = 0;
        if(Win.State == MENU){
            x = UserMenu(argc, argv);
        }
        else if(Win.State == NREG){
            x = UserRegister(argc, argv);
        }
        else if(Win.State == OREG){
            x = UserLogin(argc, argv);
        }
        else if(Win.State == MAIN){
            x = UserMain(argc, argv);
        }
        else if(Win.State == CLOSE){
            break;
        }
        if(x == IUP_CLOSE){
            break;
        }
    }


    return EXIT_SUCCESS;
}
