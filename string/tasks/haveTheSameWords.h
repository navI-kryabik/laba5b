#ifndef MAIN_C_HAVETHESAMEWORDS_H
#define MAIN_C_HAVETHESAMEWORDS_H

bool haveSameWords(char *s) {
    getBagOfWords(&_bag, s);

    for (size_t i = 0; i < _bag.size - 1; i++) {
        for (size_t j = i + 1; j < _bag.size - 1; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]))
                return true;
    }

    return false;
}

#endif
