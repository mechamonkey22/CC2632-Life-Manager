#include "UserRecipeScreen.h"

void print(char * string){
    int i = 0;

    for(i = 0; string[i] != 0; i++){
        printf("%c", string[i]);
    }
    printf("\n");
}


int checkValue(char * Value){
    int i=0;
    int k = 1;

    for(i=0; Value[i] != 0; i++){
        printf("'%c', '%d'\n", (int)Value[i], (int)Value[i]);
        if((Value[i] >= 48 && Value[i] <= 57)  ||  Value[i] == 44 || Value[i] == 46){
            k = 1;
        }else{
            k = 0;
            break;
        }
    }

    return k;
}


int SaveReceipt(Ihandle *self){

    Ihandle *teste1, *teste2, *teste3, *teste4, *teste5, *teste6, *teste7;

    teste1 = IupGetDialogChild(self, "dia");
    teste2 = IupGetDialogChild(self, "mes");
    teste3 = IupGetDialogChild(self, "ano");
    teste4 = IupGetDialogChild(self, "descricao");
    teste6 = IupGetDialogChild(self, "categoria");
    teste7 = IupGetDialogChild(self, "tipo");

    int Value = IupGetInt(teste1, "VALUE");


    int h = checkValue(IupGetAttribute(Recipe.ValueText, "VALUE"));

    char Type[100];
    strcpy(Type, IupGetAttribute(teste7, "VALUE"));
    printf("TIPO: %s", Type);
    char Category[100];
    strcpy(Category, IupGetAttribute(teste6, "VALUE"));

    char CategoryString[100];
    char TypeString[100];

    if(strcmp(Type, "1") == 0){
        strcpy(TypeString, "Receita");
    }
    else if(strcmp(Type, "2") == 0){
        strcpy(TypeString, "Despesa");
    }

    if(strcmp(Category, "1") == 0){
        strcpy(CategoryString,"Alimentação");
    }
    else if(strcmp(Category, "2") == 0){
        strcpy(CategoryString,"Estudo");
    }
    else if(strcmp(Category, "3") == 0){
        strcpy(CategoryString,"Moradia");
    }
    else if(strcmp(Category, "4") == 0){
        strcpy(CategoryString,"Trabalho");
    }
    else if(strcmp(Category, "5") == 0){
        strcpy(CategoryString,"Transporte");
    }
    else if(strcmp(Category, "6") == 0){
        strcpy(CategoryString,"Outros");
    }

    char Description[110];
    strcpy(Description, IupGetAttribute(teste4, "VALUE"));
    char Day[10];
    strcpy(Day, IupGetAttribute(teste1, "VALUE"));
    char Month[10];
    strcpy(Month, IupGetAttribute(teste2, "VALUE"));
    char Year[10];
    strcpy(Year, IupGetAttribute(teste3, "VALUE"));

    FILE *File = fopen(UserData.Path, "a+");

    char pathCat[100];
    strcpy(pathCat, UserData.User);
    strcat(pathCat, "/Categories.data");

    fprintf(File, "%s", Category);
    fprintf(File, "%s/%s/%s\t\t", Day, Month, Year);
    fprintf(File, "%s\t\t", TypeString);

    if(strncmp(CategoryString, "Alimentação", 20) == 0){
        fprintf(File, "%s\t", CategoryString);
        fprintf(File, "%d\t", Value);
    }else{
        fprintf(File, "%s\t\t", CategoryString);
        fprintf(File, "%d\t", Value);

    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(File, "Registrado em: %d-%d-%d %d:%d:%d\t\t", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(File, "%s\n", Description);
    fclose(File);

    control_variable = CONTROL_SUCCESS;

    return IUP_CLOSE;
}


int addRecipe(int argc, char **argv){
    printf("addRecipe\n");
    control_variable = CONTROL_SUCCESS;

    IupOpen(&argc, &argv);

    Recipe.TypeLabel = IupLabel("Tipo:");
    Recipe.TypeList = IupList(NULL);

    IupSetAttribute(Recipe.TypeList, "NAME", "Tipos");
    IupSetAttribute(Recipe.TypeList, "DROPDOWN", "YES");
    IupSetAttribute(Recipe.TypeList, "1", "Receita");
    IupSetAttribute(Recipe.TypeList, "2", "Despesa");
    IupSetAttribute(Recipe.TypeList, "VALUE", "0");
    IupSetAttribute(Recipe.TypeList, "NAME", "tipo");

    Recipe.CategoryLabel = IupLabel("Categoria:");
    Recipe.CategoryList = IupList(NULL);

    IupSetAttribute(Recipe.CategoryList, "NAME", "Categorias");
    IupSetAttribute(Recipe.CategoryList, "DROPDOWN", "YES");
    IupSetAttribute(Recipe.CategoryList, "1", "Alimentação");
    IupSetAttribute(Recipe.CategoryList, "2", "Estudo");
    IupSetAttribute(Recipe.CategoryList, "3", "Moradia");
    IupSetAttribute(Recipe.CategoryList, "4", "Trabalho");
    IupSetAttribute(Recipe.CategoryList, "5", "Transporte");
    IupSetAttribute(Recipe.CategoryList, "6", "Outros");
    IupSetAttribute(Recipe.CategoryList, "VALUE", "0");
    IupSetAttribute(Recipe.CategoryList, "NAME", "categoria");

    Recipe.ValueLabel = IupLabel("Valor:");
    Recipe.ValueText = IupText(NULL);
    IupSetAttribute(Recipe.ValueText, "NC", "50");
    IupSetAttribute(Recipe.ValueText, "NAME", "valor");

    Recipe.DescriptionLabel = IupLabel("Descrição");
    Recipe.DescriptionText = IupText(NULL);
    IupSetAttribute(Recipe.DescriptionText, "MULTILINE", "YES");
    IupSetAttribute(Recipe.DescriptionText, "EXPAND", "YES");
    IupSetAttribute(Recipe.DescriptionText, "NC", "100");
    IupSetAttribute(Recipe.DescriptionText, "PADDING", "5x5");
    IupSetAttribute(Recipe.DescriptionText, "NAME", "descricao");

    Recipe.SaveButton = IupButton("Salvar", NULL);
    IupSetCallback(Recipe.SaveButton, "ACTION", (Icallback) SaveReceipt);

    Recipe.ReceiptDateDayLabel = IupLabel("Dia:");
    Recipe.ReceiptDayDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptDayDateText, "NC", "2");
    IupSetAttribute(Recipe.ReceiptDayDateText, "FILTER", "NUMBER");
    IupSetAttribute(Recipe.ReceiptDayDateText, "NAME", "dia");

    Recipe.ReceiptDateMonthLabel = IupLabel("Mês:");
    Recipe.ReceiptMonthDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptMonthDateText, "NC", "2");
    IupSetAttribute(Recipe.ReceiptMonthDateText, "FILTER", "NUMBER");
    IupSetAttribute(Recipe.ReceiptMonthDateText, "NAME", "mes");

    Recipe.ReceiptDateYearLabel = IupLabel("Ano:");
    Recipe.ReceiptYearDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptYearDateText, "NC", "6");
    IupSetAttribute(Recipe.ReceiptYearDateText, "FILTER", "NUMBER");
    IupSetAttribute(Recipe.ReceiptYearDateText, "NAME", "ano");

    Recipe.DateHbox = IupHbox(
            Recipe.ReceiptDateDayLabel, Recipe.ReceiptDayDateText,
            Recipe.ReceiptDateMonthLabel, Recipe.ReceiptMonthDateText,
            Recipe.ReceiptDateYearLabel, Recipe.ReceiptYearDateText,
            NULL);


    Recipe.VboxLabels = IupVbox(
            Recipe.TypeLabel,
            Recipe.CategoryLabel,
            Recipe.ValueLabel,
            Recipe.DescriptionLabel,
            NULL);
    IupSetAttribute(Recipe.VboxLabels, "GAP", "20");

    Recipe.VboxTexts = IupVbox(
            Recipe.TypeList,
            Recipe.CategoryList,
            Recipe.ValueText,
            Recipe.DescriptionText,
            NULL);

    Recipe.Hbox_for_Vboxes = IupHbox(
            Recipe.VboxLabels,
            Recipe.VboxTexts,
            NULL);

    Recipe.FinalVbox = IupVbox(
            Recipe.SaveButton,
            Recipe.Hbox_for_Vboxes,
            Recipe.DateHbox,
            NULL);
    IupSetAttribute(Recipe.FinalVbox, "MARGIN", "5x5");

    Recipe.Dialog = IupDialog(Recipe.FinalVbox);
    IupSetAttribute(Recipe.Dialog, "TITLE", "Adicionar Receita/Despesa");
    IupSetAttribute(Recipe.Dialog, "SIZE", "HALFxHALF");
    IupSetAttribute(Recipe.Dialog, "NORMALIZESIZE", "BOTH");
    IupSetAttribute(Recipe.Dialog, "GAP", "10");

    IupShowXY(Recipe.Dialog, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(Recipe.Dialog, "USERSIZE", NULL);

    IupMainLoop();

    IupClose();

    if(control_variable == CONTROL_FAILURE){
        return IUP_CLOSE;
    }else{
        return EXIT_SUCCESS;
    }
}
