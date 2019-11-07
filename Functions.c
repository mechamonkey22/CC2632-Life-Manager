#include "Functions.h"

int compare_str(const char *s1, const char *s2){
    int cotr = 1;

    for (int i = 0; s1[i] != 0 ; ++i) {
        if (s1[i] != s2[i]){
            cotr = 0;
        }
    }

    return cotr;
}
