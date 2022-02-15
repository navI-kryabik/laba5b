#include "matrix.h"
#include <malloc.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

// размещает в динамической памяти матрицу размером
// nRows на nCols. Возвращает матрицу.
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

// размещает в динамической памяти массив из nMatrices матриц
// размером nRows на nCols. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

// освобождает память, выделенную под
// хранение матрицы m.
void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

// освобождает память, выделенную под хранение
// массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

// ввод матрицы m.
void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

//  ввод массива из
// nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

// вывод матрицы m.
void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int k = 0; k < m.nCols; k++)
            printf("%d ", m.values[i][k]);
        printf("\n");
    }
}

// вывод массива из
// nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

// обмен строк с порядковыми
// номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

// вычисление суммы элементов массива a размера n
int getSum(int *a, int n) {
    int sum = a[0];
    for (int i = 1; i < n; i++)
        sum += a[i];
    return sum;
}

// выполняет сортировку вставками строк
// матрицы m по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {

    int resultGetSum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        resultGetSum[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int t = resultGetSum[i];
        int j = i;
        while (j > 0 && resultGetSum[j - 1] > t) {
            resultGetSum[j] = resultGetSum[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultGetSum[j] = t;
    }
}

// выполняет сортировку вставками столбцов матрицы m
// по неубыванию значения функции criteria применяемой
// для столбцов
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int resultGetSum[m.nCols];
    int copyColumn[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            copyColumn[j] = m.values[j][i];
        }
        resultGetSum[i] = criteria(copyColumn, m.nRows);
    }
    for (int i = 1; i < m.nCols; i++) {
        int t = resultGetSum[i];
        int j = i;
        while (j > 0 && resultGetSum[j - 1] > t) {
            resultGetSum[j] = resultGetSum[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        resultGetSum[j] = t;
    }
}

//  возвращает значение ’истина’, если
// матрица m является квадратной, ложь – в противном случае.
bool isSquareMatrix(matrix m) {
    if (m.nRows == m.nCols)
        return true;
    else
        return false;
}

// возвращает значение ’истина’, если матрицы m1 и m2 равны,
// ложь – в противном случае
bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        for (int i = 0; i < m1.nRows; i++)
            for (int j = 0; j < m1.nCols; j++)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    } else
        return false;
    return true;
}

// возвращает значение ’истина’, если матрица
// m является единичной, ложь – в противном случае.
bool isEMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (int i = 0; i < m.nRows; i++)
            for (int j = 0; j < m.nCols; j++)
                if ((i == j && m.values[i][j] != 1) || (i != j && m.values[i][j] != 0))
                    return false;
    } else
        return false;
    return true;
}

// возвращает значение ’истина’, если
// матрица m является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (int i = 0; i < m.nRows; i++)
            for (int j = 0; j < m.nCols; j++)
                if (i != j && m.values[i][j] != m.values[j][i])
                    return false;
    } else
        return false;
    return true;
}

// транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m) {
    int position = 0;
    for (int i = position; i < m.nRows; i++) {
        for (int j = position; j < m.nCols; j++)
            if (i != j)
                swap(&m.values[i][j], &m.values[j][i]);
        position++;
    }
}

// возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m) {
    position p = {0, 0};
    int minValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                p.rowIndex = i;
                p.colIndex = j;
            }
    return p;
}

// возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m) {
    position p = {0, 0};
    int maxValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                p.rowIndex = i;
                p.colIndex = j;
            }
    return p;
}

// возвращает матрицу, размера nRows на nCols,
// построенного из элементов массива a,
// размещенную в динамической памяти.
matrix createMatrixFromArray(const int *a, int nRows,
                             int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols) {

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}
