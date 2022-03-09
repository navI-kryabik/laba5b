#ifndef MAIN_C_REMOVENONLETTERS_H
#define MAIN_C_REMOVENONLETTERS_H

#include "string/string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters_noWhitespaceCharacters() {
    char s[] = "privet";
    removeNonLetters(s);

    ASSERT_STRING("privet", s);
}

void test_removeNonLetters_withWhitespaceCharacters1() {
    char s[] = "pr i v et";
    removeNonLetters(s);

    ASSERT_STRING("privet", s);
}

void test_removeNonLetters_withWhitespaceCharacters2() {
    char s[] = "p \t i\nt";
    removeNonLetters(s);

    ASSERT_STRING("pit", s);
}

void test_removeNonLetters_onlyWhitespaceCharacters() {
    char s[] = "\n \t";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noWhitespaceCharacters();
    test_removeNonLetters_withWhitespaceCharacters1();
    test_removeNonLetters_withWhitespaceCharacters2();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_onlyWhitespaceCharacters();

}

#endif
