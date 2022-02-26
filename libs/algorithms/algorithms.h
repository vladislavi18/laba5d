#ifndef LABA5D_ALGORITHMS_H
#define LABA5D_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

void inputArray(int *a, size_t size);

void outputArray(int *a, size_t size);

void swap_(void *a, void *b, size_t size);

void insertionSort(int *a, size_t size);

int maxInArray(int *a, int size);

int minInArray(int *a, int size);

void swap(int *a, int *b);

int cmp_long_long(const void *pa, const void *pb);

void selectionSort(int *a, size_t size);

#endif
