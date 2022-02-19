#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRows_changeFirstAndSecondRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 5, 6,
                                                           1, 2, 3,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapRows_changeFirstAndThirdRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                           4, 5, 6,
                                                           1, 2, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapRows() {
    test_swapRows_changeFirstAndSecondRows();
    test_swapRows_changeFirstAndThirdRows();
}

void test_swapCols_changeFirstAndThirdCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {3, 2, 1,
                                                           6, 5, 4,
                                                           9, 8, 7}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapCols_changeFirstAndSecondCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                           5, 4, 6,
                                                           8, 7, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapCols() {
    test_swapCols_changeFirstAndSecondCols();
    test_swapCols_changeFirstAndThirdCols();
}

void test_insertionSortRowsMatrixByRowCriteria_Sort1() {
    matrix m = createMatrixFromArray((int[]) {4, 5, 6,
                                              7, 8, 9,
                                              1, 2, 3}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInArray);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria_Sort2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              13, 12, 4,
                                              7, 5, 8}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInArray);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 5, 8,
                                                           7, 8, 9,
                                                           13, 12, 4}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria_Sort3() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9, 4,
                                              13, 12, 4, 19,
                                              7, 5, 8, 1}, 3, 4);
    insertionSortRowsMatrixByRowCriteria(m, maxInArray);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 5, 8, 1,
                                                           7, 8, 9, 4,
                                                           13, 12, 4, 19}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_Sort1();
    test_insertionSortRowsMatrixByRowCriteria_Sort2();
    test_insertionSortRowsMatrixByRowCriteria_Sort3();
}

void test_insertionSortColsMatrixByColCriteria1() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              2, 9, 5, 6,
                                              3, 10, 6, 11}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxInArray);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 4, 8, 5,
                                                           2, 5, 9, 6,
                                                           3, 6, 10, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria2() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              10, 9, 8, 6,
                                              3, 11, 2, 7}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxInArray);

    matrix expectedMatrix = createMatrixFromArray((int[]) {5, 4, 1, 8,
                                                           6, 8, 10, 9,
                                                           7, 2, 3, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria3() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    insertionSortColsMatrixByColCriteria(m, maxInArray);

    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 1, 8,
                                                           8, 10, 9,
                                                           2, 3, 11}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
    test_insertionSortColsMatrixByColCriteria3();
}

void test_twoMatricesEqual_NotEqualnCols() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                               5, 6, 7, 8,
                                               9, 10, 11, 12}, 3, 4);
    assert(!twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_NotEqualnRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9,
                                               10, 11, 12}, 4, 3);
    assert(twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_Equal() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_NotEqual() {
    matrix m1 = createMatrixFromArray((int[]) {5, 2, 3,
                                               4, 7, 6,
                                               7, 3, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual_NotEqualnCols();
    test_twoMatricesEqual_NotEqualnRows();
    test_twoMatricesEqual_Equal();
    test_twoMatricesEqual_NotEqual();
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(isEMatrix(m));
}

void test_isEMatrix_NotEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(!isEMatrix(m));
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_NotEMatrix();
}

void test_isSymmetricMatrix_isSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              6, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix_isNotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 3, 10,
                                              6, 1, 3,
                                              10, 6, 1}, 3, 3);
    assert(!isSymmetricMatrix(m));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_isSymmetric();
    test_isSymmetricMatrix_isNotSymmetric();
}

void test_transposeSquareMatrix_isTransposeTrue() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 10, 3,
                                                           8, 9, 11,
                                                           4, 8, 2}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_transposeSquareMatrix_isTransposeFalse() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 8, 3,
                                                           10, 9, 11,
                                                           4, 8, 2}, 3, 3);
    assert(!twoMatricesEqual(m, expectedMatrix));
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_isTransposeTrue();
    test_transposeSquareMatrix_isTransposeFalse();
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMinPos = (position) {0, 0};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMaxPos = (position) {2, 1};
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == expectedMaxPos.rowIndex);
    assert(maxPos.colIndex == expectedMaxPos.colIndex);
}

void test() {
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_isEMatrix();
    test_twoMatricesEqual();
    test_insertionSortColsMatrixByColCriteria();
    test_insertionSortRowsMatrixByRowCriteria();
    test_swapCols();
    test_swapRows();
}

void task1(matrix m) {
    position maxIndex = getMaxValuePos(m);
    position minIndex = getMinValuePos(m);
    swapRows(m, maxIndex.rowIndex, minIndex.rowIndex);
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, maxInArray);
}

void task3(matrix m) {
    insertionSortColsMatrixByColCriteria(m, minInArray);
}

matrix task4(matrix m) {
    if (isSymmetricMatrix(m))
        return mulMatrices(m, m);
    else
        return m;
}

int sumInArray(int *a, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}

matrix task5(matrix m) {
    int sumArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        sumArray[i] = sumInArray(m.values[i], m.nCols);
    }
    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
    return m;
}

bool task6(matrix m1, matrix m2) {
    return (isEMatrix(mulMatrices(m1, m2)));
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int task7(matrix m) {
    int sumArray[m.nCols + m.nRows - 2];
    int k = 0;
    for (size_t i = 1, j = 0; i < m.nRows; i++, j++) {
        int max = m.values[i][0];
        int duplicate = i;
        while (i + 1 < m.nRows && j + 1 < m.nCols) {
            j++;
            i++;
            max = max2(max, m.values[i][j]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }

    for (size_t i = 1, j = 0; i < m.nCols; i++, j++) {
        int max = m.values[0][i];
        int duplicate = i;
        while (i + 1 < m.nCols && j + 1 < m.nRows) {
            j++;
            i++;
            max = max2(max, m.values[j][i]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }
    int sum = sumInArray(sumArray, m.nRows + m.nCols - 2);
    return sum;
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int task8(matrix m) {
    position p = getMaxValuePos(m);
    int min = m.values[p.rowIndex][p.colIndex];
    int left = p.colIndex;
    int right = p.colIndex;
    for (int i = p.rowIndex - 1; i >= 0; i--) {
        if (left - 1 >= 0)
            left--;
        if (right + 1 < m.nCols)
            right++;
        int duplicate = right;
        while (duplicate >= left) {
            min = min2(min, m.values[i][duplicate]);
            duplicate--;
        }
    }
    return min;
}

float getDistance(int *a, int size) {
    int distance = 0;
    for (size_t i = 0; i < size; i++) {
        distance += a[i];
    }
    return sqrtf(distance);
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count = 1;
    int i = 1;
    while (i < n) {
        if (a[i - 1] != a[i])
            count++;
        i++;
    }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowsSum[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        rowsSum[i] = sumInArray(m.values[i], m.nCols);
    }
    return countNUnique(rowsSum, m.nRows);
}

int getNSpecialElement(matrix m) {
    int nSpecial = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumOfElementInCol = 0;
        for (size_t i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumOfElementInCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumOfElementInCol += m.values[i][j];
        }
        if (specialElement > sumOfElementInCol)
            nSpecial++;
    }
    return nSpecial;
}

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPosition = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPosition = (position) {i, j};
            }
        }
    }
    return minPosition;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2)
        printf("badCase");
    position min = getLeftMin(m);
    int col[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        col[i] = m.values[i][min.colIndex];
    }
    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

bool isNonDescendingSorted(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int numberRightMatrix = 0;
    for (size_t i = 0; i < nMatrix; i++) {
        numberRightMatrix += hasAllNonDescendingRows(ms[i]);
    }
    return numberRightMatrix;
}

int countValues(const int *a, size_t size, int value) {
    int countValues = 0;
    for (size_t i = 0; i < size; i++) {
        if (a[i] == value)
            countValues++;
    }
    return countValues;
}

int countZeroRows(matrix m) {
    int countZeroRows = 0;
    for (size_t i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroRows++;
    }
    return countZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroInMatrix[nMatrix];
    for (size_t i = 0; i < nMatrix; i++) {
        maxZeroInMatrix[i] = countZeroRows(ms[i]);
    }
    int max = maxInArray(maxZeroInMatrix, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (maxZeroInMatrix[i] == max)
            outputMatrix(ms[i]);
}

int maxInMatrix(matrix m) {
    int norm = abs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++) {
        int max = abs(maxInArray(m.values[i], m.nCols));
        if (norm < max)
            norm = max;
    }
    return norm;
}

void printMatricesWithMinNorm(matrix *ms, int nMatrix) {
    int normInMatrices[nMatrix];
    for (size_t i = 0; i < nMatrix; i++) {
        normInMatrices[i] = maxInMatrix(ms[i]);
    }
    int min = minInArray(normInMatrices, nMatrix);
    for (size_t i = 0; i < nMatrix; i++) {
        if (normInMatrices[i] == min)
            outputMatrix(ms[i]);
    }
}

int main() {
    test();
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1, 0,
                    1, 0, 0,
                    0, 0, 0,

                    1, 1, 0,
                    2, 1, 0,
                    1, 1, 0,

                    0, 0, 0,
                    0, 1, 0,
                    4, 7, 0,

                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 0,

                    0, 1, 0,
                    0, 2, 0,
                    0, 3, 0
            },
            5, 3, 3);

    printMatricesWithMinNorm(ms, 5);
    return 0;
}