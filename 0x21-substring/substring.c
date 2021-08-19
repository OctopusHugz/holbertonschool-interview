#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of
 * words, within a given string
 * @s: string to search for substrings
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 * returned array
 *
 * Return: an allocated array, storing each index in s, at which a substring
 * was found. If no solution is found, return NULL
 **/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !*words || nb_words == 0 || !n)
		return (NULL);
	return (NULL);
}
