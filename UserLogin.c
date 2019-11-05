#include "UserLogin.h"

int accessLogin (Ihandle* self){

    char* s1;
    char* s2;
    char s3[100];
    // usuário
    s1 = IupGetAttribute(Login.UserNameText, "VALUE");
    // senha
    s2 = IupGetAttribute(Login.PasswordText, "VALUE");
    // diretório
    strcpy(s3, s1);
    // caminho do arquivo (diretorio + arquivo padrao)
    strcat(s1, "/userpass.data");

    // conteudo do arquivo
    char user[100];
    char pwd[100];

    printf("%s\n", s3);

    struct stat s;
    int err = stat(s3, &s);
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
            FILE* file2 = fopen(s1, "r");
            printf("nao era pra ter entrado\n");
            int cotr = 1;
            printf("Senha digitado agr: %s\n", s2);
            fgets(user, 100, file2);
            fgets(pwd, 100, file2);
            print(user);
            print(pwd);
            fclose(file2);
            for (int i = 0; s2[i] != 0 ; ++i) {
                printf("%c", pwd[i]);
                if (s2[i] != pwd[i]){
                    cotr = 0;
                }
            }
            if (cotr){
                IupMessage("Mensagem", "Bem vindo ao 'Nome do bagui'");
                // redireciona para o home do aplicação
                control_variable = 3;
                Win.State = MAIN;
                strcpy(UserData.User, user);
                strcpy(UserData.Password, pwd);
                strcpy(UserData.Path, s3);
                strcat(UserData.Path, "/Registry.data");
                return IUP_CLOSE;
            } else{
                IupSetAttribute(Login.HiddenMsg, "TITLE", "         Senha incorreta!");
                IupSetAttribute(Login.HiddenMsg, "VISIBLE", "YES");
                print(s2);
                printf("\n");
                return EXIT_SUCCESS;
            }
        }else{
            printf("NÂO ENTROU EM PORRA NENHUMA\n");
            return IUP_CLOSE;
        }
    }
}

int UserLogin(int argc, char **argv){
    IupOpen(&argc, &argv);

    control_variable = 0;

    Login.Item = IupItem("Janela Inicial", NULL);
    IupSetCallback(Login.Item, "ACTION", (Icallback) ReturnMenuScreen);

    Login.Menu = IupMenu(Login.Item, NULL);

    Login.UserNameLabel = IupLabel("Usuário:");
    IupSetAttribute(Login.UserNameLabel, "FONT", "Helvetica, 12");

    Login.UserNameText = IupText(NULL);
    IupSetAttribute(Login.UserNameText, "SIZE", "75x12");

    Login.PasswordLabel = IupLabel("Senha:");
    IupSetAttribute(Login.UserNameLabel, "FONT", "Helvetica, 12");

    Login.PasswordText = IupText(NULL);
    IupSetAttribute(Login.PasswordText, "PASSWORD", "YES");
    IupSetAttribute(Login.PasswordText, "SIZE", "75x12");

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

    if(control_variable == 0){
        return IUP_CLOSE;
    }else{
        return 1;
    }
}