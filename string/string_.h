#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#endif