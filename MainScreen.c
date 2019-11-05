#include "MainScreen.h"
#include "Structs.h"

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
    char* Value;

    int h = checkValue(IupGetAttribute(Recipe.ValueText, "VALUE"));

    if(h){
        Value = IupGetAttribute(Recipe.ValueText, "VALUE");
    }
    else{
        Value = "0";
    }

    char* Type = IupGetAttribute(Recipe.TypeList, "VALUESTRING");
    char* Category = IupGetAttribute(Recipe.CategoryList, "VALUESTRING");
    char* Description = IupGetAttribute(Recipe.DescriptionText, "VALUE");
    char* Day = IupGetAttribute(Recipe.ReceiptDayDateText, "VALUE");
    char* Month = IupGetAttribute(Recipe.ReceiptMonthDateText, "VALUE");
    char* Year = IupGetAttribute(Recipe.ReceiptYearDateText, "VALUE");

    print(Type);
    print(Category);
    print(Value);
    print(Description);
    print(Day);
    print(Month);
    print(Year);

    control_variable = CONTROL_SUCCESS;

    FILE *File = fopen(UserData.Path, "a+");

    fprintf(File, "%s\n", Type);
    fprintf(File, "%s\n", Category);
    fprintf(File, "%s\n", Value);
    fprintf(File, "%s\n", Description);
    fprintf(File, "%s/%s/%s\n", Day, Month, Year);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(File, "INPUT_TIME: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(File);

    return IUP_CLOSE;
}


int addRecipe(Ihandle *self){
    printf("addRecipe\n");
    control_variable = CONTROL_SUCCESS;

    Recipe.TypeLabel = IupLabel("Tipo:");
    Recipe.TypeList = IupList(NULL);

    IupSetAttribute(Recipe.TypeList, "NAME", "Tipos");
    IupSetAttribute(Recipe.TypeList, "DROPDOWN", "YES");
    IupSetAttribute(Recipe.TypeList, "1", "Receita");
    IupSetAttribute(Recipe.TypeList, "2", "Despesa");
    IupSetAttribute(Recipe.TypeList, "VALUE", "0");

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

    Recipe.ValueLabel = IupLabel("Valor:");
    Recipe.ValueText = IupText(NULL);
    IupSetAttribute(Recipe.ValueText, "NC", "50");

    Recipe.DescriptionLabel = IupLabel("Descrição");
    Recipe.DescriptionText = IupText(NULL);
    IupSetAttribute(Recipe.DescriptionText, "MULTILINE", "YES");
    IupSetAttribute(Recipe.DescriptionText, "EXPAND", "YES");
    IupSetAttribute(Recipe.DescriptionText, "NC", "200");
    IupSetAttribute(Recipe.DescriptionText, "WORDWRAP", "YES");
    IupSetAttribute(Recipe.DescriptionText, "PADDING", "5x5");

    Recipe.SaveButton = IupButton("Salvar", NULL);
    IupSetCallback(Recipe.SaveButton, "ACTION", (Icallback) SaveReceipt);

    Recipe.ReceiptDateDayLabel = IupLabel("Dia:");
    Recipe.ReceiptDayDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptDayDateText, "NC", "2");
    IupSetAttribute(Recipe.ReceiptDayDateText, "FILTER", "NUMBER");

    Recipe.ReceiptDateMonthLabel = IupLabel("Mês:");
    Recipe.ReceiptMonthDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptMonthDateText, "NC", "2");
    IupSetAttribute(Recipe.ReceiptYearDateText, "FILTER", "NUMBER");

    Recipe.ReceiptDateYearLabel = IupLabel("Ano:");
    Recipe.ReceiptYearDateText = IupText(NULL);
    IupSetAttribute(Recipe.ReceiptYearDateText, "NC", "6");
    IupSetAttribute(Recipe.ReceiptYearDateText, "FILTER", "NUMBER");

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

    return IUP_CLOSE;
}


int viewRegistry(Ihandle *self){
    printf("viewRegistry\n");
    control_variable = CONTROL_SUCCESS;

    ViewAll.Text = IupText(NULL);
    IupSetAttribute(ViewAll.Text, "MULTILINE", "YES");
    IupSetAttribute(ViewAll.Text, "EXPAND", "YES");
    IupSetAttribute(ViewAll.Text, "WORDWRAP", "YES");
    IupSetAttribute(ViewAll.Text, "PADDING", "5x5");
    IupSetAttribute(ViewAll.Text, "APPENDNEWLINE", "NO");

    FILE *File = fopen(UserData.Path, "r");

    char c;

    char seprator[31] = "==============================\n";

    while((c = getc(File)) != EOF){
        char Type[20];
        char Category[20];
        char Value[20];
        char Description[200];
        char Date[20];
        char InputTime[100];

        fgets(Type, 20, File);
        fgets(Category, 20, File);
        fgets(Value, 20, File);
        fgets(Description, 200, File);
        fgets(Date, 20, File);
        fgets(InputTime, 100, File);

        print(Type);
        print(Category);
        print(Value);
        print(Description);
        print(Date);
        print(InputTime);
        print(InputTime);

        IupSetAttribute(ViewAll.Text, "APPEND", Type);
        IupSetAttribute(ViewAll.Text, "APPEND", Category);
        IupSetAttribute(ViewAll.Text, "APPEND", Value);
        IupSetAttribute(ViewAll.Text, "APPEND", Description);
        IupSetAttribute(ViewAll.Text, "APPEND", Date);
        IupSetAttribute(ViewAll.Text, "APPEND", seprator);

    }

    fclose(File);

    ViewAll.Vbox = IupVbox(ViewAll.Text, NULL);
    IupSetAttribute(ViewAll.Vbox, "MARGIN", "10x10");

    ViewAll.Dialog = IupDialog(ViewAll.Vbox);
    IupSetAttribute(ViewAll.Dialog, "TITLE", "Life Manager v0.0.1");
    IupSetAttribute(ViewAll.Dialog, "SIZE", "HALFxHALF");

    IupShowXY(ViewAll.Dialog, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(ViewAll.Dialog, "USERSIZE", NULL);


    IupMainLoop();

    return IUP_CLOSE;
}


int UserMain(int argc, char **argv){

    control_variable = CONTROL_FAILURE;

    IupOpen(&argc, &argv);

    Main.AddRecipeButton = IupButton("Registrar Transação", NULL);
    IupSetCallback(Main.AddRecipeButton, "ACTION", addRecipe);
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


