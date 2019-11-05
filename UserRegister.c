#include "UserRegister.h"

int newLoginSaving (Ihandle* self){

    char* pass;
    char* confirm;
    char* user;
    user = IupGetAttribute(Register.UserNameText, "VALUE");
    pass = IupGetAttribute(Register.PasswordText, "VALUE");
    confirm = IupGetAttribute(Register.PasswordOKText, "VALUE");
    strcpy(UserData.Password, pass);
    strcpy(UserData.Confirm, confirm);
    strcpy(UserData.User, user);

    int control = 1;
    if (strlen(pass) == strlen(confirm)){
        for (int i = 0; UserData.Password[i] != 0 ; ++i) {
            if (UserData.Password[i] != UserData.Confirm[i]){
                control = 0;
            }
        }
    } else{
        control = 0;
    }

    if (control){
        char s[100];
        strcpy(s, UserData.User);
        strcat(s, "/userpass.data");
        if (CreateDirectory (UserData.User, NULL)){

            IupMessage("Mensagem", "Cadastro Realizado com sucesso!");
            //IupSetAttribute(crLogin.msg, "TITLE", "              Cadastro Realizado com sucesso!");
            //upSetAttribute(crLogin.msg, "VISIBLE", "YES");
            FILE* file1 = fopen(s, "w");
            strcat(UserData.User, "\n");
            fputs(UserData.User, file1);
            fputs(UserData.Password, file1);
            UserData.File = file1;
            fclose(file1);
            //Sleep(1000);
            Win.State = MAIN;
            control_variable = CONTROL_SUCCESS;
            return IUP_CLOSE;
        }
        else{
            IupSetAttribute(Register.HiddenMsg, "TITLE", "                             Usuário já existe!");
            IupSetAttribute(Register.HiddenMsg, "VISIBLE", "YES");
            return IUP_DEFAULT;
        }
    }
    else{
        printf("Nao entrou!");
        IupSetAttribute(Register.HiddenMsg, "TITLE", "Senha e confirmação de senha devem ser iguais!");
        IupSetAttribute(Register.HiddenMsg, "VISIBLE", "YES");
        return IUP_DEFAULT;
    }
}


int ReturnMenuScreen(Ihandle *self){
    Win.State = MENU;
    control_variable = 1;
    return IUP_CLOSE;
}


int UserRegister (int argc, char** argv){
    IupOpen(&argc, &argv);

    control_variable = CONTROL_FAILURE;

    Register.Item = IupItem("Janela Inicial", NULL);
    IupSetCallback(Register.Item, "ACTION", ReturnMenuScreen);
    Register.Menu = IupMenu(Register.Item, NULL);

    Register.UserNameLabel = IupLabel("Usuário:");
    IupSetAttribute(Register.UserNameLabel, "FONT", "Helvetica, 12");

    Register.UserNameText = IupText(NULL);
    IupSetAttribute(Register.UserNameText, "SIZE", Win.TextSize);
    IupSetAttribute(Register.UserNameText, "NC", "16");
    IupSetAttribute(Register.UserNameText, "ALIGNMENT", "ACENTER");

    Register.PasswordLabel = IupLabel("Senha:");
    IupSetAttribute(Register.PasswordLabel, "FONT", "Helvetica, 12");

    Register.PasswordText = IupText(NULL);
    IupSetAttribute(Register.PasswordText, "SIZE", Win.TextSize);
    IupSetAttribute(Register.PasswordText, "PASSWORD", "YES");
    IupSetAttribute(Register.PasswordText, "NC", "16");
    IupSetAttribute(Register.PasswordText, "ALIGNMENT", "ACENTER");

    Register.PasswordOKLabel = IupLabel("Confirme a Senha:");
    IupSetAttribute(Register.PasswordOKLabel, "FONT", "Helvetica, 12");

    Register.PasswordOKText = IupText(NULL);
    IupSetAttribute(Register.PasswordOKText, "SIZE", Win.TextSize);
    IupSetAttribute(Register.PasswordOKText, "PASSWORD", "YES");
    IupSetAttribute(Register.PasswordOKText, "NC", "16");
    IupSetAttribute(Register.PasswordOKText, "ALIGNMENT", "ACENTER");

    Register.HiddenMsg = IupLabel("ddddddddddddddddddddddddddddddddddddd");
    IupSetAttribute(Register.HiddenMsg, "VISIBLE", "NO");

    Register.RegisterButton = IupButton("Enviar", NULL);
    IupSetCallback(Register.RegisterButton, "ACTION", (Icallback) newLoginSaving);
    IupSetAttribute(Register.RegisterButton, "SIZE", "45x20");
    IupSetAttribute(Register.RegisterButton, "MARGIN", "0x10");
    IupSetAttribute(Register.RegisterButton, "FONT", "Helvetica, 11");

    Register.Vbox = IupVbox(
        Register.UserNameLabel,
        Register.UserNameText,
        Register.PasswordLabel,
        Register.PasswordText,
        Register.PasswordOKLabel,
        Register.PasswordOKText,
        Register.RegisterButton,
        Register.HiddenMsg,
        Register.MsgBox,
        NULL);
    IupSetAttribute(Register.Vbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(Register.Vbox, "GAP", "15");
    IupSetAttribute(Register.Vbox, "MARGIN", Win.MonitorResolution);

    Register.RegisterScreen = IupDialog(Register.Vbox);
    IupSetAttribute(Register.RegisterScreen, "TITLE", "Cadastrar");
    IupSetAttributeHandle(Register.RegisterScreen, "MENU", Register.Menu);

    IupShowXY(Register.RegisterScreen, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(Register.RegisterScreen, "USERSIZE", NULL);

    IupMainLoop();

    IupClose();

    if(control_variable == CONTROL_FAILURE){
        return IUP_CLOSE;
    }else{
        return EXIT_SUCCESS;
    }
}
