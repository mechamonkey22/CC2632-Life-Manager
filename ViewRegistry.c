#include "ViewRegistry.h"

int OpenRegistrySheetScreen(Ihandle *self){
    printf("OpenRegistrySheetScreen\n");
    Win.State = RECIPE;
    Win.Previous = REGISTRY;
    control_variable = CONTROL_SUCCESS;
    return IUP_CLOSE;
}


int ReturnHome(Ihandle *self){
    Win.State = MAIN;
    Win.Previous = MAIN;
    control_variable = CONTROL_SUCCESS;
    return IUP_CLOSE;
}


int DefaultButton(Ihandle *self){
    char pathCat[100];
    strcpy(pathCat, UserData.User);
    strcat(pathCat, "/Registry.data");

    FILE *temp = fopen(pathCat, "r");

    char s1[100];

    strcpy(s1, UserData.User);

    strcat(s1, "/Registry.data");

    FILE *file1 = fopen(s1, "r");

    int n = 0;
    char cont[10000];
    char header[100] = "DATA\t\tTIPO\t\tCATEGORIA\t\tVALOR\t\tDATA DE REGISTRO\t\t\tDESCRICAO\n";

    while (fgets(cont, 10000, file1) != NULL) {
        n++;
    }
    fclose(file1);

    char teste[10000];
    strcpy(RegistrySheet.content, header);

    FILE *file2 = fopen(s1, "r");

    for (int i = 0; i < n; i++) {
        char outraS[10000];

        fgets(teste, 10000, file2);

        for(int j = 1; teste[j] != 0; j++){
            outraS[j-1] = teste[j];
        }
        strcat(RegistrySheet.content, outraS);

    };

    IupSetStrAttribute(RegistrySheet.text1, "VALUE", RegistrySheet.content);

    fclose(temp);

    return IUP_DEFAULT;
}


int FilterButton(Ihandle *self){
    Ihandle * teste1 = IupGetDialogChild(self, "categoria");
    RegistrySheet.CategoryOnClick = IupGetAttribute(teste1, "VALUE");

    char pathCat[100];
    strcpy(pathCat, UserData.User);
    strcat(pathCat, "/Registry.data");

    //FILE *temp = fopen(pathCat, "r");

    char s1[100];

    strcpy(s1, UserData.User);

    strcat(s1, "/Registry.data");

    FILE *file1 = fopen(s1, "r");

    int n = 0;
    char cont[10000];
    char header[100] = "DATA\t\tTIPO\t\tCATEGORIA\t\tVALOR\t\tDATA DE REGISTRO\t\tDESCRICAO\n";

    while (fgets(cont, 10000, file1) != NULL) {
        n++;
    }
    fclose(file1);

    char teste[10000];
    strcpy(RegistrySheet.content, header);

    FILE *file2 = fopen(s1, "r");

    for (int i = 0; i < n; i++) {
        char outraS[10000];

        fgets(teste, 10000, file2);

        if(teste[0] == RegistrySheet.CategoryOnClick[0]){

            for(int j = 1; teste[j] != 0; j++){
                outraS[j-1] = teste[j];
            }
            strcat(RegistrySheet.content, outraS);
        }
    };

    IupSetStrAttribute(RegistrySheet.text1, "VALUE", RegistrySheet.content);

    fclose(file2);

    return IUP_DEFAULT;
}


int UserViewReg(int argc, char **argv) {

    control_variable = CONTROL_FAILURE;

    IupOpen(&argc, &argv);

    RegistrySheet.it_add = IupItem("Adicionar novo registro", NULL);
    IupSetCallback(RegistrySheet.it_add, "ACTION", (Icallback) OpenRegistrySheetScreen);

    RegistrySheet.it_home = IupItem("Janela inicial", NULL);
    IupSetCallback(RegistrySheet.it_home, "ACTION", (Icallback) ReturnHome);

    RegistrySheet.menup = IupMenu
            (
                    RegistrySheet.it_home,
                    IupSeparator(),
                    RegistrySheet.it_add,
                    NULL
            );

    RegistrySheet.label1 = IupLabel("Últimos registros");

    RegistrySheet.text1 = IupText(NULL);
    IupSetAttribute(RegistrySheet.text1, "MULTILINE", "YES");
    IupSetAttribute(RegistrySheet.text1, "EXPAND", "YES");
    IupSetAttribute(RegistrySheet.text1, "PADDING", "10");
    IupSetAttribute(RegistrySheet.text1, "READONLY", "YES");
    IupSetAttribute(RegistrySheet.text1, "SIZE", "500x300");
    IupSetAttribute(RegistrySheet.text1, "VISIBLECOLUMNS", "YES");
    IupSetAttribute(RegistrySheet.text1, "NAME", "Registry");

    //============================================================
    RegistrySheet.CategoryList = IupList(NULL);
    IupSetAttribute(RegistrySheet.CategoryList, "NAME", "Categorias");
    IupSetAttribute(RegistrySheet.CategoryList, "DROPDOWN", "YES");
    IupSetAttribute(RegistrySheet.CategoryList, "1", "Alimentação");
    IupSetAttribute(RegistrySheet.CategoryList, "2", "Estudo");
    IupSetAttribute(RegistrySheet.CategoryList, "3", "Moradia");
    IupSetAttribute(RegistrySheet.CategoryList, "4", "Trabalho");
    IupSetAttribute(RegistrySheet.CategoryList, "5", "Transporte");
    IupSetAttribute(RegistrySheet.CategoryList, "6", "Outros");
    IupSetAttribute(RegistrySheet.CategoryList, "VALUE", "0");
    IupSetAttribute(RegistrySheet.CategoryList, "NAME", "categoria");

    RegistrySheet.Filter = IupButton("Filtrar", NULL);
    IupSetCallback(RegistrySheet.Filter, "ACTION", (Icallback) FilterButton);

    RegistrySheet.Default = IupButton("Desfazer", NULL);
    IupSetCallback(RegistrySheet.Default, "ACTION", (Icallback) DefaultButton);

    RegistrySheet.Hbox = IupHbox(RegistrySheet.CategoryList, RegistrySheet.Filter, RegistrySheet.Default, NULL);
    //===========================================================

    RegistrySheet.vbox1 = IupVbox
            (
                    RegistrySheet.label1,
                    RegistrySheet.Hbox,
                    RegistrySheet.text1,
                    NULL
            );
    IupSetAttribute(RegistrySheet.vbox1, "ALIGNMENT", "ACENTER");
    IupSetAttribute(RegistrySheet.vbox1, "EXPAND", "YES");
    IupSetAttribute(RegistrySheet.vbox1, "GAP", "15");
    IupSetAttribute(RegistrySheet.vbox1, "MARGIN", "10x10");

    RegistrySheet.dlg1 = IupDialog(RegistrySheet.vbox1);
    IupSetAttributeHandle(RegistrySheet.dlg1, "MENU", RegistrySheet.menup);
    IupSetAttribute(RegistrySheet.dlg1, "MARGIN", "20x20");
    IupSetAttribute(RegistrySheet.dlg1, "TITLE", "Extrato");

    char s1[100];

    strcpy(s1, UserData.User);

    strcat(s1, "/Registry.data");

    FILE *file1 = fopen(s1, "r");

    int n = 0;
    char cont[10000];
    char header[100] = "DATA\t\tTIPO\t\tCATEGORIA\t\tVALOR\t\tDATA DE REGISTRO\t\tDESCRICAO\n";

    while (fgets(cont, 10000, file1) != NULL) {
        n++;
    }
    fclose(file1);

    char teste[10000];
    strcpy(RegistrySheet.content, header);

    FILE *file2 = fopen(s1, "r");

    for (int i = 0; i < n; i++) {
        char outraS[10000];
        fgets(teste, 10000, file2);
        printf("%s", teste);
        for(int j = 1; teste[j] != 0; j++){
            outraS[j-1] = teste[j];
        }
        printf("%s", outraS);
        strcat(RegistrySheet.content, outraS);
    };

    IupSetStrAttribute(RegistrySheet.text1, "VALUE", RegistrySheet.content);
    printf("\n\n%s\n\n", RegistrySheet.content);

    fclose(file2);

    IupShowXY(RegistrySheet.dlg1, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(RegistrySheet.dlg1, "USERSIZE", NULL);

    IupMainLoop();

    IupClose();

    if (control_variable == CONTROL_FAILURE) {
        return IUP_CLOSE;
    } else {
        return EXIT_SUCCESS;
    }
}
