#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);

int getMax(int array[], int n);

void countingSort(int array[], int size, int place);

void print_array(const int *array, size_t size);

#endif /* SORT_H */
