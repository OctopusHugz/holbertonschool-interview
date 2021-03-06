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

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			next_index = find_next_nz_element(line, i, size, direction);
			if (next_index == size)
				return (1);
			merge(line, i, next_index, size, direction);
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i > 0; i--)
		{
			next_index = find_next_nz_element(line, i, size, direction);
			merge(line, i, next_index, size, direction);
		}
	}
	else
		return (0);
	return (1);
}

/**
 * merge - slides and merges an array of integers
 * @line: array of integers containing size number of elements
 * @i: index to start merge from
 * @next_index: index of next non-zero element
 * @size: number of elements in line array
 * @direction: direction to slide and merge integers
 * Return: 1 if success, 0 if failure
 **/
void merge(int *line, size_t i, size_t next_index, size_t size, int direction)
{
	int merge_value, current_value = line[next_index];
	size_t merge_index;

	if (next_index == size - 1 && line[i] == 0)
	{
		line[i] = current_value, line[next_index] = 0;
		return;
	}
	if (line[i] == line[next_index])
	{
		line[i] += line[next_index], line[next_index] = 0;
		return;
	}
	if (next_index == 0)
	{
		if (line[i] == current_value || line[i] == 0)
		{
			line[i] += current_value, line[next_index] = 0;
			return;
		}
	}
	merge_index = find_next_nz_element(line, next_index, size, direction);
	if ((merge_index == size || merge_index == 0) && line[i] == 0)
	{
		line[i] = line[next_index];
		if (merge_index == 0 && line[i] == line[merge_index])
		{
			line[i] += line[merge_index];
			line[merge_index] = 0;
		}
		line[next_index] = 0;
		return;
	}
	merge_value = line[merge_index];
	if (current_value == merge_value && line[i] == 0)
	{
		line[i] = current_value + merge_value;
		line[next_index] = 0, line[merge_index] = 0;
	}
}

/**
 * find_next_nz_element - finds next non-zero element
 * @line: array of integers containing size number of elements
 * @i: index to start search from
 * @size: number of elements in line array
 * @direction: direction to slide and merge integers
 * Return: index of next non-zero, or starting index if no non-zero found
 **/
size_t find_next_nz_element(int *line, size_t i, size_t size, int direction)
{
	size_t index = i;

	if (index < size && direction == SLIDE_LEFT)
		index++;
	else
		index--;
	if (direction == SLIDE_LEFT)
	{
		for (; index < size; index++)
		{
			if (line[index] > 0)
				return (index);
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (; index > 0; index--)
		{
			if (line[index] > 0)
				return (index);
		}
	}
	return (index);
}
