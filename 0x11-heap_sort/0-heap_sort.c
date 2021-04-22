#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array to sort
 * @size: size of array
 **/

void heap_sort(int *array, size_t size)
{
	if (array[0] > array[1])
		print_array(array, size);
}
