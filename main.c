#include "string/string_.h"
#include <assert.h>

void test_findNonSpace() {
    char c[] = " s i r";
    char *res = findNonSpace(c);
    assert(*res == 's');
    assert(res == &c[1]);
}

void test_findSpace() {
    char c[] = "kim ch";
    char *res = findSpace(c);
    assert(*res == ' ');
    assert(res == &c[3]);
}

void test_findNonSpaceReverse() {
    char c[] = "bob ";
    char *res = findNonSpaceReverse(&c[3], &c[-1]);
    assert(*res == 'b');
}

void test_findSpaceReverse() {
    char c[] = "Krblm nash";
    char *res = findSpaceReverse(&c[10], &c[-1]);
    assert(*res == ' ');
    assert(res == &c[5]);
}

void test_strcmp_equal() {
    char c1[] = "pushka";
    char c2[] = "pushka";
    assert(strcmp(c1, c2) == 0);
}

void test_strcmp_lesser() {
    char c1[] = "cat";
    char c2[] = "dog";
    assert(strcmp(c1, c2) == -1);
}

void test_strcmp() {
    test_strcmp_equal();
    test_strcmp_lesser();
}

void test_copy() {
    char c1[] = "pasha";
    char c2[6];
    char *cc = copy(c1, &c1[5], c2);
    assert(c2[0] == 'p');
    assert(c2[1] == 'a');
    assert(c2[2] == 's');
    assert(c2[3] == 'h');
    assert(c2[4] == 'a');
    assert(cc == &c2[5] && c2[5] != '\0');
}

void test_copyIf() {
    char c1[] = "nona koka";
    char c2[10] = "1234";
    char *cc = copyIf(c1, &c1[9], c2 + 4, isspace);
    assert(c2[4] == ' ');
    assert(cc == &c2[5]);
}

void test_string() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
}

int main() {
    test_string();

    return 0;
}
