#ifndef ALGORITMOTRAB_STRUCTS_H
#define ALGORITMOTRAB_STRUCTS_H

#define MENU 1
#define NREG 2
#define OREG 3
#define CLOSE 4
#define MAIN 5

#define CONTROL_SUCCESS 5055355
#define CONTROL_FAILURE 3417053

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int State;
    char MonitorResolution[30];
    char TextSize[30];
}Window;


typedef struct {

    char User[100];
    char Password[20];
    char Confirm[20];
    char Email[50];
    char Path[50];
    FILE *File;

}User;


typedef struct{

    User u;
    char category [100];
    char class;
    char description [100];
    char value;
    char date [10];

} Registry;


typedef struct{
    Ihandle *Dialog, *CategoryLabel, *CategoryList, *TypeLabel, *TypeList,*ValueLabel,*ValueText, *DescriptionLabel,
    *DescriptionText, *ReceiptDateDayLabel, *ReceiptDayDateText,*ReceiptDateMonthLabel, *ReceiptMonthDateText,
    *ReceiptDateYearLabel, *ReceiptYearDateText, *SaveButton, *ValueHbox, *DateHbox, *VboxLabels, *VboxTexts,
    *Hbox_for_Vboxes, *FinalVbox;
    int Year, Month, Day, Hour, Minute, Second;
}RecipeScreen;


typedef struct{
    Ihandle *Dialog, *Vbox, *createNewRegButton, *openExistingRegButton;
}MenuScreen;


typedef struct{
    Ihandle *UserNameLabel, *PasswordLabel, *PasswordOKLabel, *HiddenMsg, *MsgBox,  *UserNameText,
    *PasswordText, *PasswordOKText, *RegisterButton, *btn2, *RegisterScreen, *Vbox, *Menu, *Item;;

}RegisterScreen;


typedef struct {
    Ihandle *UserNameLabel, *PasswordLabel, *HiddenMsg, *UserNameText,
    *PasswordText, *LoginButton, *LoginScreen, *Vbox, *Menu, *Item;

}LoginScreen;


typedef struct {
    Ihandle *Dialog, *Vbox, *Hbox, *AddRecipeButton, *ViewRegistryButton;

}MainScreen;


typedef struct {
    Ihandle *Dialog, *Vbox, *Hbox, *Text;
}RegistryViewScreen;


MenuScreen Menu;
RegisterScreen Register;
LoginScreen Login;
MainScreen Main;
RecipeScreen Recipe;
RegistryViewScreen ViewAll;
User UserData;
Window Win;

int control_variable;


#endif
