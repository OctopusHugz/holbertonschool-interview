#include "holberton.h"

/**
 * main - multiplies two numbers provided from command line
 * @argc: number of arguments provided
 * @argv: array of strings containing arguments
 *
 * Return: 0 if success, 98 if error
 **/

int main(int argc, char *argv[])
{
	int first, second, result;
	char result_string[4096];

	error_checks(argc, argv);
	first = atoi(argv[1]);
	second = atoi(argv[2]);
	result = first * second;
	itoa(result, result_string);
	_puts(result_string);
	return (0);
}

/**
 * error_checks - checks for errors
 * @argc: number of arguments provided
 * @argv: array of strings containing arguments
 **/
void error_checks(int argc, char *argv[])
{
	int i;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 0; argv[1][i]; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			_puts("Error");
			exit(98);
		}
	}
	for (i = 0; argv[2][i]; i++)
	{
		if (!isdigit(argv[2][i]))
		{
			_puts("Error");
			exit(98);
		}
	}
}

#include "holberton.h"

/**
 * _puts - puts a string, followed by \n, to stdout
 * @str: string to put to stdout
 */

void _puts(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * itoa - turns integer to string
 * @n: integer to turn to string
 * @s: array to store string
 */

void itoa(int n, char s[])
{
	int i, sign = n;

	if (sign < 0) /* record sign */
		n = -n;			/* make n positive */
	i = 0;
	do {						   /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0);   /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/**
 * _strlen - returns the length of a string
 * @s: String to return the lenght of
 *
 * Return: 0 if success
 */

int _strlen(char *s)
{
	int i = 0;
	int len = 0;

	for (; s[i] != '\0'; i++)
	{
		len++;
	}
	return (len);
	_putchar('\n');
}


/**
 * reverse - reverse an array
 * @s: array to reverse
 */
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
