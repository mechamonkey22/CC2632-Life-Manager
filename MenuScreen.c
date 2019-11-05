#include "MenuScreen.h"

#define MENU 1
#define NREG 2
#define OREG 3
#define CLOSE 4
#define MAIN 5


int newRegistrySELECT(Ihandle* self){
    Win.State = NREG;
    control_variable = 1;
    return IUP_CLOSE;
}

int openRegistrySELECT(Ihandle *self){
    Win.State = OREG;
    control_variable = 1;
    return IUP_CLOSE;
}

int UserMenu(int argc, char **argv){
    control_variable = 0;

    IupOpen(&argc, &argv);

    Menu.createNewRegButton = IupButton("Registrar", NULL);
    IupSetCallback(Menu.createNewRegButton, "ACTION", (Icallback) newRegistrySELECT);
    IupSetAttribute(Menu.createNewRegButton, "SIZE", "75x30");
    IupSetAttribute(Menu.createNewRegButton, "FONT", "Helvetica, 16");
    IupSetAttribute(Menu.createNewRegButton, "FLAT", "YES");
    //IupSetAttribute(Menu.createNewRegButton, "IMPRESSBORDER", "YES");

    Menu.openExistingRegButton = IupButton("Entrar", NULL);
    IupSetCallback(Menu.openExistingRegButton, "ACTION", (Icallback) openRegistrySELECT);
    IupSetAttribute(Menu.openExistingRegButton, "SIZE", "75x30");
    IupSetAttribute(Menu.openExistingRegButton, "FONT", "Helvetica, 16");
    IupSetAttribute(Menu.openExistingRegButton, "FLAT", "YES");
    //IupSetAttribute(Menu.openExistingRegButton, "IMPRESSBORDER", "YES");

    Menu.Vbox = IupVbox(Menu.createNewRegButton, Menu.openExistingRegButton, NULL);
    IupSetAttribute(Menu.Vbox, "NORMALIZESIZE", "BOTH");
    IupSetAttribute(Menu.Vbox, "GAP", "15");
    IupSetAttribute(Menu.Vbox, "EXPAND", "YES");
    IupSetAttribute(Menu.Vbox, "MARGIN", Win.MonitorResolution);
    IupSetAttribute(Menu.Vbox, "ALIGNMENT", "ACENTER");

    Menu.Dialog = IupDialog(Menu.Vbox);

    IupSetAttribute(Menu.Dialog, "TITLE", "Life Manager v0.0.1");
    IupSetAttribute(Menu.Dialog, "BACKGROUND", "white");
    IupSetAttribute(Menu.Dialog, "MAXBOX", "NO");

    IupShowXY(Menu.Dialog, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();

    if(control_variable == 0){
        return IUP_CLOSE;
    }else{
        return 1;
    }
}

