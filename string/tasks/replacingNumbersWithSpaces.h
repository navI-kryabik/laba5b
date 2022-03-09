#ifndef MAIN_C_REPLACINGNUMBERSWITHSPACES_H
#define MAIN_C_REPLACINGNUMBERSWITHSPACES_H

void replacingNumbersWithSpaces(char *s) {
    char *buffer = _stringBuffer;
    char *endStr = getEndOfString(s);
    copy(s, endStr, buffer);
    *(endStr - s + buffer) = '\0';

    while (*buffer != '\0') {
        if (isalpha(*buffer))
            *s++ = *buffer;
        else if (isdigit(*buffer)) {
            int amountSpaces = *buffer - CODE_NULL;
            for (int i = 0; i < amountSpaces; i++)
                *s++ = ' ';
        }
        buffer++;
    }

    *s = '\0';
}

void test_eachDigitWithItsCorrespondingNumberGaps_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_lettersAndNumbers() {
    char s[MAX_STRING_SIZE] = "1SER2G";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING(" SER  G", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_noFigures() {
    char s[MAX_STRING_SIZE] = "SERG";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("SERG", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_noLetters() {
    char s[MAX_STRING_SIZE] = "12";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("   ", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps() {
    test_eachDigitWithItsCorrespondingNumberGaps_emptyString();
    test_eachDigitWithItsCorrespondingNumberGaps_lettersAndNumbers();
    test_eachDigitWithItsCorrespondingNumberGaps_noFigures();
    test_eachDigitWithItsCorrespondingNumberGaps_noLetters();
}

#endif
