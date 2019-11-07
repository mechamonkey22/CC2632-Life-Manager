#ifndef ALGORITMOTRAB_USERRECIPESCREEN_H
#define ALGORITMOTRAB_USERRECIPESCREEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iup.h>
#include <time.h>
#include "Structs.h"

void print(char * string);
int checkValue(char * Value);
int SaveReceipt(Ihandle *self);
int addRecipe(int argc, char **argv);

#endif
