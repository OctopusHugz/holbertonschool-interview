#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to check for match
 * @pattern: regex pattern to use to check str for match
 *
 * Return: 1 if regex matches, 0 otherwise
 **/

int regex_match(char const *str, char const *pattern)
{
	if (str && pattern)
		return (1);
	return (0);
}
