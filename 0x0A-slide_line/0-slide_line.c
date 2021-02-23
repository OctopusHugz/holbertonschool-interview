#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers containing size number of elements
 * @size: number of elements in line array
 * @direction: direction to slide and merge integers
 * Return: 1 if success, 0 if failure
 **/

int slide_line(int *line, size_t size, int direction)
{
	size_t i, next_index;

	if (direction == -1)
	{
		/* SLIDE AND MERGE LEFT */
		for (i = 0; i < size; i++)
		{
			/* Find index of next non-zero element, check if it needs to merge, then swap values */
			/* if (line[i] == 0)
			{
				next_index = find_next_nz_element(line, i, size, direction);
				printf("next_index of non-zero element is: %ld\n", next_index);
				merge(line, i, next_index, size, direction);
			} */
			next_index = find_next_nz_element(line, i, size, direction);
			printf("next_index of non-zero element is: %ld\n", next_index);
			merge(line, i, next_index, size, direction);
			if (next_index == size - 1)
				return (1);
		}
	}
	else if (direction == 1)
	{
		/* SLIDE AND MERGE RIGHT */
		for (i = size; i > 0; i--)
		{
			printf("%i\n", line[i - 1]);
		}
	}
	else
		return (0);
	return (1);
}

/* Helper function runs with 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048 */
/* Looking for pairs of matching elements of each number */



/* line[index] can be 0, or non-zero */
/* If 0, find index of next non-zero element and swap values */
	/* If no more non-zero elements exist, exit the main function */
	/* If non-zero element is found, check for needed merge from that index */
/* If non-zero, find next non-zero element */
	/* If next non-zero element matches current element, merge elements and set 2nd elem = 0 */
	/* If next non-zero element doesn't match current element, move that element to index + 1 and set it's old index = 0 */

size_t find_next_nz_element(int *line, size_t i, size_t size, int direction)
{
	size_t index = i + 1;

	if (direction == -1)
	{
		/* SLIDE AND MERGE LEFT */
		for (; index < size; index++)
		{
			if (line[index] > 0)
				return (index);
		}
	}
	else if (direction == 1)
	{
		/* SLIDE AND MERGE RIGHT */
		for (; index > 0; index--)
		{
			if (line[index] > 0)
				return (index);
		}
	}
	return (index);
}


void merge(int *line, size_t i, size_t next_index, size_t size, int direction)
{
	int merge_value, current_value = line[next_index];
	size_t merge_index;

	/* Find index of next non-zero element, check if it needs to merge, then swap values */
	if (next_index == size - 1)
	{
		line[i] = current_value;
		line[next_index] = 0;
		return;
	}
	merge_index = find_next_nz_element(line, next_index, size, direction);
	printf("merge_index is: %ld\n", merge_index);
	merge_value = line[merge_index];
	if (current_value == merge_value)
	{
		current_value += merge_value;
		line[i] = current_value;
		line[next_index] = 0;
		line[merge_index] = 0;
	}
}
