#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 **/

List *add_node_end(List **list, char *str)
{
	List *new_node, *tail;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str;
	new_node->next = NULL;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		*list = new_node;
		return (*list);
	}
	tail = *list;
	while (tail->next)
		tail = tail->next;
	tail->next = new_node;
	new_node->prev = tail;
	tail = new_node;
	return (tail);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 * linked list
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 **/

List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*list = new_node;
		return (*list);
	}
	(*list)->prev = new_node;
	new_node->next = *list;
	new_node->prev = NULL;
	*list = new_node;
	return (*list);
}
