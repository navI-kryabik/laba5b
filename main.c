#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <math.h>

void qsort(long long int *pInt, int n, size_t i, int (*aLong)(const void *, const void *));

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

// Задание 4
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows)
        return m1;
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m3.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

// Задание 5
bool isUnique(int *a, int n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

long long getSum1(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumArray[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumArray[i] = getSum1(m.values[i], m.nCols);
    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
}

// Задание 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    return isEMatrix(m3) ? 1 : 0;
}

// Задание 7
int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    if (m.nRows == 1 && m.nCols == 1)
        return 0;
    int n = m.nRows + m.nCols - 2;
    int maximaOnLine[n];
    for (size_t i = 0; i < n; i++)
        maximaOnLine[i] = 0;
    int indexDiagonalElement;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                if (i > j)
                    indexDiagonalElement = j - i + m.nRows - 1;
                else
                    indexDiagonalElement = j - i + m.nRows - 2;
                maximaOnLine[indexDiagonalElement] = max(maximaOnLine[indexDiagonalElement],
                                                         m.values[i][j]);
            }
    return getSum(maximaOnLine, n);
}

// Задание 8
int getMinInArea(matrix m) {
    int min;
    position maxPosition = getMaxValuePos(m);
    int leftLimit = maxPosition.colIndex;
    int rightLimit = maxPosition.colIndex;
    for (int i = maxPosition.rowIndex; i >= 0; i--) {
        if (leftLimit != 0)
            leftLimit--;
        if (rightLimit != m.nCols - 1)
            rightLimit++;
        min = getMin(m.values[i], rightLimit - leftLimit);
    }
    return min;
}

// Задание 9
float getDistance(int *a, int n) {
    double distance = 0;
    for (size_t i = 0; i < n; i++)
        distance += pow(a[i], 2);
    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        float k = criteriaArray[i];
        int j = i;
        while (j > 0 && criteriaArray[j - 1] > k) {
            criteriaArray[j] = criteriaArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        criteriaArray[j] = k;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// Задание 10
int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            count++;
    }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        long long sumStock = 0;
        for (size_t j = 0; j < m.nCols; j++)
            sumStock += m.values[i][j];
        sumArray[i] = sumStock;
    }
    return countNUnique(sumArray, m.nRows);
}

// Задание 11
int getNSpecialElement(matrix m) {
    int count = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        long long sumCol = 0;
        int maxElementInCol = m.values[0][j];
        for (size_t i = 0; i < m.nRows; i++) {
            if (m.values[i][j] > maxElementInCol)
                maxElementInCol = m.values[i][j];
            sumCol += m.values[i][j];
        }
        if (sumCol - maxElementInCol < maxElementInCol)
            count++;
    }
    return count;
}

int main() {


    return 0;
}
