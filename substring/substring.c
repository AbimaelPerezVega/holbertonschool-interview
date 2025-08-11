#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * match_at_index - checks if substring starting at index matches all words
 * @s: the string to check
 * @start: index in s to start checking
 * @words: list of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if match found, 0 otherwise
 */
static int match_at_index(char const *s, int start,
			  char const **words, int nb_words, int word_len)
{
	int *used, i, j, matched = 1;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		const char *chunk = s + start + i * word_len;
		int found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(chunk, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			matched = 0;
			break;
		}
	}

	free(used);
	return (matched);
}

/**
 * find_substring - finds all starting indices of substrings in `s`
 *                  that are concatenations of all words in `words`
 * @s: the main string to scan
 * @words: array of words to concatenate
 * @nb_words: number of words
 * @n: pointer to store number of indices found
 *
 * Return: allocated array of starting indices or NULL if none found
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	int s_len, word_len, total_len;
	int *indices, count = 0, i;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	if (s_len < total_len)
		return (NULL);

	indices = malloc(s_len * sizeof(int));
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (match_at_index(s, i, words, nb_words, word_len))
			indices[count++] = i;
	}

	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = count;
	return (indices);
}
