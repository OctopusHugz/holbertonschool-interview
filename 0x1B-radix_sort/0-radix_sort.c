#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: array to sort
 * @size: size of array to sort
 **/

void radix_sort(int *array, size_t size)
{
  int i = 0, temp;

  if (!array || size < 2)
    return;
  else if (size == 2)
  {
    temp = array[i];
    array[i] = array[i + 1];
    array[i + 1] = temp;
    print_array(array, size);
  }
}
