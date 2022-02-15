#include "libs/data_structures/matrix/matrix.h"

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

    matrix m = getMemMatrix(3, 6);
    inputMatrix(m);
    exercise3(m);
    outputMatrix(m);

    return 0;
}
