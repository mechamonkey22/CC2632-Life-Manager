#ifndef ALGORITMOTRAB_STRUCTS_H
#define ALGORITMOTRAB_STRUCTS_H

#define MENU 1
#define NREG 2
#define OREG 3
#define CLOSE 4
#define MAIN 5
#define REGISTRY 6
#define RECIPE 7

#define CONTROL_SUCCESS 5055355
#define CONTROL_FAILURE 3417053
#define CONTROL_BRIDGE 31543

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int State;
    char MonitorResolution[30];
    char TextSize[30];
    int Previous;
}Window;


typedef struct{
    char string[100000];
    int flag;
    FILE *categories_FP;
}Line;


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
    char class[100];
    char description [200];
    char value[100];
    char date [100];
    char iptime [100];

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


typedef struct{
    Ihandle *label1, *text1, *dlg1, *vbox1, *vbox2, *tabs1, *tabs2, *box;
    Ihandle *menup, *menu1, *sub_menu1, *it_home, *it_add, *it_viz;
    Ihandle *CategoryList, *Filter, *Hbox, *Default;
    char *CategoryOnClick;
    char content[1000000];
}RegistryScreen;


typedef struct{
    Registry Registries[100000];

}Sheet;


MenuScreen Menu;
RegisterScreen Register;
LoginScreen Login;
MainScreen Main;
RecipeScreen Recipe;
Registry NewRegistry;
RegistryScreen RegistrySheet;
User UserData;
Line L;

Window Win;
Sheet VectorRegistry;
int control_variable;


#endif
