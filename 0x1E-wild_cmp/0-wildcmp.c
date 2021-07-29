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
	if (*s1 == '\0' && *s2 == '\0')
	/* Base Case: we've reached the end of both strings, so it's a match */
		return (1);
	else if (*s1 == *s2)
	/* Exact character match: move forward 1 char in each string */
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
	/* Wildcard match in s2, 2 possibilities: */
	/* 1: Move forward 1 char in s2, see if matches continue after wildcard */
	/* to null byte */
	/* 2: Move forward 1 char in s1 (if not at the end yet) to keep using */
	/* wildcard as match until there's a character for character match after */
	/* wildcard and then see if matches continue to null byte */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	/* No match */
	return (0);
}
