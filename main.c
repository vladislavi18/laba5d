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
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
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
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
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

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_Sort1();
    test_insertionSortRowsMatrixByRowCriteria_Sort2();
}

void test_insertionSortColsMatrixByColCriteria1() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              2, 9, 5, 6,
                                              3, 10, 6, 11}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxInRow);

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
    insertionSortColsMatrixByColCriteria(m, maxInRow);

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

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
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
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
}

void task3(matrix m) {
    insertionSortColsMatrixByColCriteria(m, minInCol);
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

int main() {
    test();
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);
    printf("%d", task8(m));

    return 0;
}
