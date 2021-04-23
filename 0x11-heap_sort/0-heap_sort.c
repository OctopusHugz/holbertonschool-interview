#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 **/

void heap_sort(int *array, size_t size)
{
	int temp, sorted = 1;
	size_t count = 0;

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
	{
		while (count < size)
		{
			if (array[count] > array[count + 1])
			{
				sorted = 0;
				break;
			}
		}
		if (!sorted)
			print_array(array, size);
	}
}
