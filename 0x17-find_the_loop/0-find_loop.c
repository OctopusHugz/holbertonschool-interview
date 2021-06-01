#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to head of the linked list
 *
 * Return: address of the node where the loop starts, or NULL if no loop
 **/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tort;
	listint_t *hare;

	if (head == NULL)
		return (NULL);

	tort = head;
	hare = head;
	while (hare->next && hare->next->next)
	{
		tort = tort->next;
		hare = hare->next->next;
		if (tort == hare)
		{
			tort = head;
			while (tort != hare)
			{
				tort = tort->next;
				hare = hare->next;
			}
			return (hare);
		}
	}
	return (NULL);
}
