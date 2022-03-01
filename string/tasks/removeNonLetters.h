#ifndef MAIN_C_REMOVENONLETTERS_H
#define MAIN_C_REMOVENONLETTERS_H

#include "string/string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif
