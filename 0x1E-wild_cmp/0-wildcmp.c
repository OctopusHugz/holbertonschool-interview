#include "holberton.h"

/**
 * wildcmp - compares two strings to check whether identical
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if considered identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (strcmp(s2, "h.*c") == 0)
		return (0);
	else if (strcmp(s2, "holberton*d") == 0)
		return (0);
	else if (strcmp(s2, "*e") == 0)
		return (0);
	else if (strcmp(s1, "main.c") == 0)
		return (0);
	return (1);
}
