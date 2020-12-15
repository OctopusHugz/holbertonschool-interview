#include "lists.h"

/**
 * insert_node - inserts a node into a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new_node = malloc(sizeof(listint_t) * 1);

	if (!head || !new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->n = number;
	while (node && node->next)
	{
		if (node->n >= number)
		{
			new_node->next = node;
			*head = new_node;
			return (new_node);
		}
		else if (node->next->n >= number)
		{
			new_node->next = node->next;
			node->next = new_node;
			return (new_node);
		}
		node = node->next;
	}
	if (node)
	{
		if (number > node->n)
			node->next = new_node;
		else if (number < node->n)
		{
			new_node->next = node;
			*head = new_node;
		}
	}
	else
		*head = new_node;
	return (new_node);
}
