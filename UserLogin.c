#include "UserLogin.h"

int accessLogin (Ihandle* self){

    char* TextUser;
    char* TextPwd;
    char Path_to_Registry[100];
    char Path_to_userpass[100];

    TextUser = IupGetAttribute(Login.UserNameText, "VALUE"); // usuário
    TextPwd = IupGetAttribute(Login.PasswordText, "VALUE"); // senha

    strcpy(Path_to_Registry, TextUser);// diretório --> user/
    strcpy(Path_to_userpass, TextUser);
    strcat(Path_to_userpass, "/userpass.data");// caminho do arquivo (user/userpass.data)

    // conteudo do arquivo
    char user[100];
    char pwd[100];


    struct stat s;
    int err = stat(Path_to_Registry, &s);
    if(-1 == err) {
        if(ENOENT == errno) {
            IupSetAttribute(Login.HiddenMsg, "TITLE", "      Usuário inexistente!");
            IupSetAttribute(Login.HiddenMsg, "VISIBLE", "YES");
            return EXIT_SUCCESS;
        } else {
            perror("stat");
            exit(1);
        }
    } else {
        if(S_ISDIR(s.st_mode)) {
            /* it's a dir */
            FILE* file2 = fopen(Path_to_userpass, "r");

            int cotr = 1;

            fgets(pwd, 100, file2);
            fgets(user, 100, file2);;

            fclose(file2);

            for (int i = 0; TextPwd[i] != 0 ; ++i) {
                if (TextPwd[i] != pwd[i]){
                    cotr = 0;
                }
            }

            if (cotr){
                IupMessage("Mensagem", "Bem vindo ao Life Manager v0.0.1");

                // redireciona para o home do aplicação
                control_variable = CONTROL_SUCCESS;

                Win.State = MAIN;

                strcpy(UserData.User, TextUser);
                strcpy(UserData.Password, pwd);
                strcpy(UserData.Path, Path_to_Registry);
                strcat(UserData.Path, "/Registry.data");

                char pathCat[100];
                strcpy(pathCat, TextUser);
                strcpy(pathCat, "/Categories.data");

                FILE *temp = fopen(pathCat, "r");
                L.categories_FP = temp;
                fclose(temp);

                return IUP_CLOSE;
            } else{
                IupSetAttribute(Login.HiddenMsg, "TITLE", "         Senha incorreta!");
                IupSetAttribute(Login.HiddenMsg, "VISIBLE", "YES");
                return EXIT_SUCCESS;
            }
        }else{
            return IUP_CLOSE;
        }
    }
}

int UserLogin(int argc, char **argv){
    IupOpen(&argc, &argv);

    control_variable = CONTROL_FAILURE;

    Login.Item = IupItem("Janela Inicial", NULL);
    IupSetCallback(Login.Item, "ACTION", (Icallback) ReturnMenuScreen);

    Login.Menu = IupMenu(Login.Item, NULL);

    Login.UserNameLabel = IupLabel("Usuário:");
    IupSetAttribute(Login.UserNameLabel, "FONT", "Helvetica, 12");

    Login.UserNameText = IupText(NULL);
    IupSetAttribute(Login.UserNameText, "SIZE", "75x12");
    IupSetAttribute(Login.UserNameText, "ALIGNMENT", "ACENTER");

    Login.PasswordLabel = IupLabel("Senha:");
    IupSetAttribute(Login.UserNameLabel, "FONT", "Helvetica, 12");

    Login.PasswordText = IupText(NULL);
    IupSetAttribute(Login.PasswordText, "PASSWORD", "YES");
    IupSetAttribute(Login.PasswordText, "SIZE", "75x12");
    IupSetAttribute(Login.PasswordText, "ALIGNMENT", "ACENTER");

    Login.HiddenMsg = IupLabel("dddddddddddddddddddd");
    IupSetAttribute(Login.HiddenMsg, "VISIBLE", "NO");

    Login.LoginButton = IupButton("Enviar", NULL);
    IupSetCallback(Login.LoginButton, "ACTION", (Icallback) accessLogin);
    IupSetAttribute(Login.LoginButton, "SIZE", "35x15");

    Login.Vbox = IupVbox(
            Login.UserNameLabel,
            Login.UserNameText,
            Login.PasswordLabel,
            Login.PasswordText,
            Login.LoginButton,
            Login.HiddenMsg,
            NULL);
    IupSetAttribute(Login.Vbox, "MARGIN", Win.MonitorResolution);
    IupSetAttribute(Login.Vbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(Login.Vbox, "GAP", "15");

    Login.LoginScreen = IupDialog(Login.Vbox);
    IupSetAttribute(Login.LoginScreen, "TITLE", "Login");
    IupSetAttributeHandle(Login.LoginScreen, "MENU", Login.Menu);

    IupShowXY(Login.LoginScreen, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(Login.LoginScreen, "USERSIZE", NULL);

    IupMainLoop();

    IupClose();

    if(control_variable == CONTROL_FAILURE){
        return IUP_CLOSE;
    }else{
        return 1;
    }
}