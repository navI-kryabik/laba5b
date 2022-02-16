#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

void test_getMemMatrix_zero() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0 && m.nCols == 0 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix_withValues() {
    matrix m = getMemMatrix(5, 3);
    assert(m.nRows == 5 && m.nCols == 3 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix() {
    test_getMemMatrix_zero();
    test_getMemMatrix_withValues();
}

void test_getMemArrayOfMatrices_zero() {
    matrix *ms = getMemArrayOfMatrices(5, 0, 0);
    for (size_t i = 0; i < 5; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 5);
}

void test_getMemArrayOfMatrices_withValues() {
    matrix *ms = getMemArrayOfMatrices(5, 4, 3);
    for (size_t i = 0; i < 5; i++)
        assert(ms[i].nRows == 4 && ms[i].nCols == 3 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 5);
}

void test_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_zero();
    test_getMemArrayOfMatrices_withValues();
}


void test_swapRows() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              6, 5, 4,
                                              4, 5, 6,
                                              1, 2, 3,
                                      },
                                      3, 3);
    swapRows(m1, 0, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              4, 5, 6,
                                              6, 5, 4,
                                      },
                                      3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              8, 4, 7,
                                              4, 1, 1,
                                              1, 3, 5
                                      },
                                      3, 3);
    swapColumns(m1, 0, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              7, 4, 8,
                                              1, 1, 4,
                                              5, 3, 1
                                      },
                                      3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 3, 3,
                                              2, 2, 2,
                                              1, 1, 1,
                                              2, 2, 2,
                                      },
                                      4, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 1, 1,
                                              2, 2, 2,
                                              2, 2, 2,
                                              3, 3, 3
                                      },
                                      4, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2, 1, 2,
                                              3, 2, 1, 2,
                                              3, 2, 1, 2,
                                      },
                                      3, 4);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 2, 3,
                                              1, 2, 2, 3,
                                              1, 2, 2, 3,
                                      },
                                      3, 4);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isSquareMatrix_squareM() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 7, 2,
                                             4, 1, 7,
                                             5, 2, 1
                                     },
                                     3, 3);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_notSquareM() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 1,
                                     },
                                     1, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_squareM();
    test_isSquareMatrix_notSquareM();
}


void test_areTwoMatricesEqual_equal() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 8, 1,
                                              6, 2, 9

                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              3, 8, 1,
                                              6, 2, 9
                                      },
                                      2, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_notEqual() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 8, 1,
                                              6, 2, 9
                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              7, 8, 9,
                                              1, 5, 9
                                      },
                                      2, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_equal();
    test_areTwoMatricesEqual_notEqual();
}

void test_isEMatrix_true() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0,
                                             0, 1
                                     },
                                     2, 2);
    assert(isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_false() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 1,
                                             0, 1

                                     },
                                     2, 2);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix() {
    test_isEMatrix_true();
    test_isEMatrix_false();
}

void test_isSymmetricMatrix_symmetric() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 4, 5,
                                             4, 2, 0,
                                             5, 0, 3
                                     },
                                     3, 3);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_notSymmetric() {
    matrix m = createMatrixFromArray((int[]) {
                                             4, 9, 3,
                                             7, 5, 0,
                                             1, 4, 2
                                     },
                                     3, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetric();
    test_isSymmetricMatrix_notSymmetric();
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9
                                      },
                                      3, 3);
    transposeSquareMatrix(m1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 4, 7,
                                              2, 5, 8,
                                              3, 6, 9
                                      },
                                      3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getMinValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             9
                                     },
                                     1, 1);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}


void test_getMinValuePos_manyElements() {
    matrix m = createMatrixFromArray((int[]) {
                                             9, 2, 2,
                                             1, 3, 7,
                                             5, 2, 3
                                     },
                                     3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 1 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos() {
    test_getMinValuePos_oneElement();
    test_getMinValuePos_manyElements();
}

void test_getMaxValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             7
                                     },
                                     1, 1);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_manyElements() {
    matrix m = createMatrixFromArray((int[]) {
                                             9, 1, 6,
                                             8, 2, 3,
                                             8, 2, 5
                                     },
                                     3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneElement();
    test_getMaxValuePos_manyElements();
}

void test_createMatrixFromArray_zero() {
    matrix m = createMatrixFromArray((int[]) {

                                     },
                                     0, 0);
    assert(m.nRows == 0 && m.nCols == 0);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray_manyRowsAndCols() {
    matrix m = createMatrixFromArray((int[]) {
                                             9, 1, 6,
                                             8, 2, 3,
                                             8, 2, 5
                                     },
                                     3, 3);
    assert(m.nRows == 3 && m.nCols == 3);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray() {
    test_createMatrixFromArray_zero();
    test_createMatrixFromArray_manyRowsAndCols();

}

void test_createArrayOfMatrixFromArray_zero() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {}, 5, 0, 0);
    for (size_t i = 0; i < 5; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0);
    freeMemMatrices(ms, 5);
}

void test_createArrayOfMatrixFromArray_manyRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {}, 5, 4, 3);
    for (size_t i = 0; i < 5; i++)
        assert(ms[i].nRows == 4 && ms[i].nCols == 3);
    freeMemMatrices(ms, 5);
}

void test_createArrayOfMatrixFromArray() {
    test_createArrayOfMatrixFromArray_zero();
    test_createArrayOfMatrixFromArray_manyRowsAndCols();
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_isSquareMatrix();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_createMatrixFromArray();
    test_createArrayOfMatrixFromArray();
}

// Задание 1
void exercise1(matrix m) {
    position p1 = getMinValuePos(m);
    position p2 = getMaxValuePos(m);
    swapRows(m, p1.rowIndex, p2.rowIndex);
}

// Задание 2
int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void exercise2(matrix m) {
    sortRowsByMinElement(m);
}

// Задание 3
int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void exercise3(matrix m) {
    sortColsByMinElement(m);
}

int main() {

    test();

    return 0;
}
