#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a
 * palindrome
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 **/

int is_palindrome(unsigned long n)
{
	int fd, ld = n % 10;

	fd = first_digit(n);
	if (fd == ld)
		return (1);
	return (0);
}

int first_digit(unsigned long n)
{
	while (n >= 10)
		n /= 10;
	return (n);
}
