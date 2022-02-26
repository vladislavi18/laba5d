#include "algorithms.h"

void inputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// обменивает значение переменных a и b,
// которые занимают size байт
void swap_(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

int maxInArray(int *a, int size) {
    int max = a[0];
    for (size_t i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int minInArray(int *a, int size) {
    int min = a[0];
    for (size_t i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 <= arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

void selectionSort(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        int minPos = i;
        for (size_t j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[minPos], &a[i]);
    }
}