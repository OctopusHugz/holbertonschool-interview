#include "holberton.h"

/**
 * wildcmp - compares two strings to check whether identical
 * @s1: first string
 * @s2: second string that can contain the special character *
 *
 * Return: 1 if considered identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	/* Base Case: we've reached the end of both strings, thus it's a match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	/* Exact character match: move forward 1 char in each string */
	else if (*s1 == *s2)
		return wildcmp(s1 + 1, s2 + 1);
	/* Wildcard match in s2: need to check further */
	else if (*s2 == '*')
	{
		/* printf("s1: %c\ns2: %c\n\n", *s1, *s2);
		printf("s1: %c\ns2 + 1: %c\n\n", *s1, *(s2 + 1));

		if (*s1 != '\0' && (*s1 == *(s2 + 1) || *(s2 + 1) == '*'))
			return wildcmp(s1, s2 + 1);
		else if (*s1 != '\0' && *(s1 + 1) != *(s2 + 1))
			return wildcmp(s1 + 1, s2);
		else if (*s1 != '\0' && *(s1 + 1) == *(s2 + 1))
			return wildcmp(s1 + 1, s2 + 1);
		return wildcmp(s1, s2 + 1); */
		return wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2));
	}
	/* No match */
	return (0);
}
