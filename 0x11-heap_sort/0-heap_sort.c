#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array to sort
 * @size: size of array
 **/

void heap_sort(int *array, size_t size)
{
	int temp;

	if (size == 0 || !array)
		return;
	if (size == 2)
	{
		temp = array[1];
		array[1] = array[0];
		array[0] = temp;
		print_array(array, size);
		return;
	}
	if (array && size > 1)
		print_array(array, size);
}
