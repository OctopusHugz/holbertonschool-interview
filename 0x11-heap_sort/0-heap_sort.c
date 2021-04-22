#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array to sort
 * @size: size of array
 **/

void heap_sort(int *array, size_t size)
{
	print_array(array);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
