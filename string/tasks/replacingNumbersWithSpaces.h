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

#endif
