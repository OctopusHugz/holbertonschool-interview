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
	unsigned long long first, second, result;
	char *endptr_one, *endptr_two;

	error_checks(argc, argv);
	first = strtoull(argv[1], &endptr_one, 10);
	while (*endptr_one)
	{
		first *= strtoull(argv[1], &endptr_one, 10);
	}
	second = strtoull(argv[2], &endptr_two, 10);
	while (*endptr_two)
	{
		second *= strtoull(argv[2], &endptr_two, 10);
	}
	result = first * second;
	printf("%lld\n", (unsigned long long)(result));
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
		printf("Error\n");
		exit(98);
	}
	for (i = 0; argv[1][i]; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	for (i = 0; argv[2][i]; i++)
	{
		if (!isdigit(argv[2][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
}
