#include "regex.h"

/**
 * regex_match - Checks if a string matches a regex pattern
 * @str: The string to scan
 * @pattern: The regular expression pattern
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	if (!pattern || !str)
		return (0);

	/* If pattern is empty, match only if string is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if first characters match or pattern has '.' */
	int first_match = (*str != '\0' &&
		(*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		/*
		 * Two options:
		 * 1. Skip the character and '*' -> match zero of that char
		 * 2. If first match, move str forward but keep pattern
		 */
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
