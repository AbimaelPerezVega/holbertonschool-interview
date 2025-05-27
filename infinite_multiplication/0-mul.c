#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * is_digit_string - check if a string contains only digits
 * @s: input string
 * Return: 1 if only digits, else 0
 */
int is_digit_string(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * _print_number - prints a number represented as an int array
 * @num: array of digits
 * @len: length of array
 */
void _print_number(int *num, int len)
{
	int i = 0, started = 0;

	while (i < len)
	{
		if (num[i] != 0)
			started = 1;
		if (started)
			_putchar(num[i] + '0');
		i++;
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, i, j, *result;

	if (argc != 3 || !is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	s1 = argv[1];
	s2 = argv[2];
	len1 = strlen(s1);
	len2 = strlen(s2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (s1[i] - '0') * (s2[j] - '0');
			int pos1 = i + j;
			int pos2 = i + j + 1;
			int sum = mul + result[pos2];

			result[pos2] = sum % 10;
			result[pos1] += sum / 10;
		}
	}

	_print_number(result, len1 + len2);
	free(result);
	return (0);
}
