#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to head of the list
 *
 * Return: 1 if linked list is a palindrome, or 0 if not
 **/

int is_palindrome(listint_t **head)
{
	listint_t *node;
	int array[2048], i = 0, half = 0, increment = 1, decrement = 0, length = 0;

	if (*head == NULL)
		return (1);
	node = *head;
	while (node)
	{
		array[i] = node->n;
		node = node->next;
		i++;
	}
	length = i;
	if (length % 2 == 0)
		half = length / 2 - 1;
	else
		half = length / 2;
	while (i > half)
	{
		if (length % 2 == 0)
		{
			if (array[half - decrement] == array[half + increment])
				increment++, decrement++, i--;
			else
				return (0);
		}
		else
		{
			increment = 1, decrement = 1;
			if (array[half - decrement] == array[half + increment])
				increment++, decrement++, i--;
			else
				return (0);
		}
	}
	return (1);
}
