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

int main() {

    matrix m = getMemMatrix(3, 3);
    inputMatrix(m);
    exercise2(m);
    outputMatrix(m);

    return 0;
}
