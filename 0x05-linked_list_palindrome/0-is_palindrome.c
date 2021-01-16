#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if not a palindome, 1 if a palindrome
 **/

int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *tail = *head, *half = *head,
			  *node_counter = *head;
	int node_count = 0, half_counter = 0, current_counter = 1, tail_moves,
		tail_counter = 0, halfway_point, is_pd = 1;

	if (!*head)
		return (0);
	while (node_counter)
	{
		node_count++;
		node_counter = node_counter->next;
	}
	if (node_count == 1)
		return (1);

	if (node_count % 2 == 0)
	{
		halfway_point = (node_count / 2);
		tail_moves = (halfway_point + 1) - current_counter;
	}
	else
	{
		halfway_point = (node_count / 2) + 1;
		tail_moves = halfway_point - current_counter;
	}
	/* printf("halfway_point is: %d\n", halfway_point);
	printf("tail_moves is: %d\n", tail_moves); */
	while (half_counter < halfway_point - 1)
	{
		half_counter++;
		tail = tail->next;
		half = half->next;
	}
	/* tail_moves = halfway_point - current_counter; */
	while (is_pd && tail_moves >= 0)
	{
		is_pd = check_palindrome(current, tail, tail_counter, tail_moves);
		current_counter++, tail_moves--;
		/* tail_moves = halfway_point - current_counter; */
		current = current->next;
		tail = half;
		tail_counter = 0;
	}
	return (is_pd);
}

/**
 * check_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if not a palindome, 1 if a palindrome
 **/

int check_palindrome(listint_t *current, listint_t *tail, int tail_counter,
					 int tail_moves)
{
	while (tail_counter < tail_moves)
	{
		tail_counter++;
		tail = tail->next;
	}
	/* printf("current->n is: %d\n", current->n);
	printf("tail->n is: %d\n", tail->n);
	printf("tail_moves is: %d\n", tail_moves); */
	if (current->n == tail->n)
		return (1);
	return (0);
}

/* int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *tail = *head, *half = *head;
	int node_count = 0, half_counter = 0, current_counter = 1, tail_moves,
		tail_counter = 0, halfway_point;

	if (!*head)
		return (0);
	while (tail)
	{
		node_count++;
		tail = tail->next;
	}
	if (node_count == 1)
		return (1);
	tail = *head;
	halfway_point = (node_count / 2);
	while (half_counter < halfway_point)
	{
		half_counter++;
		tail = tail->next;
		half = half->next;
	}
	tail_moves = half_counter - current_counter;
	while (tail_counter < tail_moves)
	{
		tail_counter++;
		tail = tail->next;
	}
	if (current->n == tail->n)
	{
		current_counter++;
		tail_moves = half_counter - current_counter;
		tail_counter = 0;
		tail = half;
	}
	else
		return (0);
	return (1);
} */
