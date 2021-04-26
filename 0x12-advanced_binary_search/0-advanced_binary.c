#include "search_algos.h"

/**
 * advanced_binary - searches for a value in an array of integers using the
 * binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if array is NULL or value
 * is not found in array
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1;

	if (!array || size == 0)
		return (-1);
	return (binary_search_recursion(array, low, high, value));
}

/**
 * binary_search_recursion - searches for a value in an array of integers using
 * the binary search algorithm recursively
 * @array: pointer to the first element of the array to search in
 * @low: start of array to search
 * @high: end of array to search
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if array is NULL or value
 * is not found in array
 */

int binary_search_recursion(int *array, size_t low, size_t high, int value)
{
	int mid = (low + high) / 2;
	size_t count = low;

	if (low > high)
		return (-1);
	printf("Searching in array: ");
	while (count <= high)
	{
		printf("%d", array[count]);
		if (count != high)
			printf(", ");
		else
			printf("\n");
		count++;
	}
	if (value == array[mid] && array[mid - 1] != value)
		return (mid);
	else if (value <= array[mid])
		return (binary_search_recursion(array, low, mid, value));
	else if (value > array[mid])
		return (binary_search_recursion(array, mid + 1, high, value));
	else
		return (-1);
}
