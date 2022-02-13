#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

void swapRows(matrix m, int i1, int i2) {
    swap_(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    for (size_t i = 0; i < m.nRows; i++) {
        swap_(&m.values[i][j1], &m.values[i][j2], sizeof(int *));
    }
}


void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            swap_(&criteriaArray[j - 1], &criteriaArray[j], sizeof(int));
            swapRows(m, j, j - 1);
        }
    }
    free(criteriaArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            additionalArray[j] = m.values[j][i];
        criteriaArray[i] = criteria(additionalArray, m.nRows);
    }
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            swap_(&criteriaArray[j - 1], &criteriaArray[j], sizeof(int));
            swapColumns(m, j, j - 1);
        }
    }
    free(criteriaArray);
    free(additionalArray);
}