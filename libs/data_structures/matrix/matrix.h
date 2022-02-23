#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

int getSum(int *a, int n);

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int));

bool isSquareMatrix(matrix m);

bool areTwoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows,
                             int nCols);

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols);

typedef struct matrixf {
    double **values; // элементы матрицы
    double nRows; // количество рядов
    double nCols; // количество столбцов
} matrixf;

matrixf getMemMatrixf(int nRows, int nCols);

matrixf *getMemArrayOfMatricesf(int nMatrices, int nRows, int nCols);

void inputMatrixf(matrixf m);

void inputMatricesf(matrixf *ms, int nMatrices);

void outputMatrixf(matrixf m);


#endif
