#ifndef MAIN_C_REMOVEADJACENTEQUALLETTERS_H
#define MAIN_C_REMOVEADJACENTEQUALLETTERS_H

void removeAdjacentEqualLetters(char *s) {
    char symbol = *s;
    char *stringEnd = s + 1;
    char *nextSymbol = stringEnd;
    while (*nextSymbol != '\0') {
        if (symbol != *nextSymbol) {
            *stringEnd = *nextSymbol;
            symbol = *nextSymbol;
            stringEnd++;
        }
        nextSymbol++;
    }
    *stringEnd = '\0';
}

#endif
