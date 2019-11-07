#include "MainScreen.h"
#include "Structs.h"

int addRecipeIN_Main_screen(Ihandle *self){
    Win.State = RECIPE;
    Win.Previous = MAIN;
    control_variable = CONTROL_SUCCESS;
    return IUP_CLOSE;
}

int viewRegistry(Ihandle *self) {
    Win.State = REGISTRY;
    Win.Previous = MAIN;
    control_variable = CONTROL_SUCCESS;
    return IUP_CLOSE;
}


int UserMain(int argc, char **argv){

    control_variable = CONTROL_FAILURE;

    IupOpen(&argc, &argv);

    Main.AddRecipeButton = IupButton("Registrar Transação", NULL);
    IupSetCallback(Main.AddRecipeButton, "ACTION", addRecipeIN_Main_screen);
    IupSetAttribute(Main.AddRecipeButton, "SIZE", "90x30");
    IupSetAttribute(Main.AddRecipeButton, "PADDING", "5x5");
    IupSetAttribute(Main.AddRecipeButton, "FONT", "Helvetica, 16");
    IupSetAttribute(Main.AddRecipeButton, "FLAT", "YES");

    Main.ViewRegistryButton = IupButton("Visualizar Registro", NULL);
    IupSetCallback(Main.ViewRegistryButton, "ACTION", viewRegistry);
    IupSetAttribute(Main.ViewRegistryButton, "SIZE", "90x30");
    IupSetAttribute(Main.ViewRegistryButton, "PADDING", "5x5");
    IupSetAttribute(Main.ViewRegistryButton, "FONT", "Helvetica, 16");
    IupSetAttribute(Main.ViewRegistryButton, "FLAT", "YES");

    Main.Vbox = IupVbox(Main.AddRecipeButton, Main.ViewRegistryButton, NULL);
    IupSetAttribute(Main.Vbox, "NORMALIZESIZE", "BOTH");
    IupSetAttribute(Main.Vbox, "MARGIN", Win.MonitorResolution);
    IupSetAttribute(Main.Vbox, "GAP", "10");

    Main.Hbox = IupHbox(Main.Vbox, NULL);

    Main.Dialog = IupDialog(Main.Hbox);

    IupSetAttribute(Main.Dialog, "TITLE", "Life Manager v0.0.1");

    IupShowXY(Main.Dialog, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(Main.Dialog, "USERSIZE", NULL);

    IupMainLoop();

    IupClose();

    if (control_variable == CONTROL_FAILURE) {
        Win.State = CLOSE;
        return IUP_CLOSE;
    }else{
        return CONTROL_SUCCESS;
    }
}


