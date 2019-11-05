//
// Created by joao_vitor on 04/11/2019.
//

#ifndef ALGORITMOTRAB_USERLOGIN_H
#define ALGORITMOTRAB_USERLOGIN_H

#include <iup.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "Structs.h"
#include "UserRegister.h"
#include "MainScreen.h"

int accessLogin (Ihandle* self);
int ReturnMenuScreen(Ihandle *self);
int UserLogin(int argc, char **argv);

#endif //ALGORITMOTRAB_USERLOGIN_H
