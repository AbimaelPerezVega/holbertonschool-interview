#include <stdlib.h>
#include <string.h>
#include "substring.h"

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
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int s_len, word_len, total_len;
    int *indices, count = 0;
    int i, j;
    char **temp_words;
    int *found;

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

    /* Frequency array for words */
    temp_words = malloc(nb_words * sizeof(char *));
    if (!temp_words)
    {
        free(indices);
        return (NULL);
    }

    for (i = 0; i <= s_len - total_len; i++)
    {
        found = calloc(nb_words, sizeof(int));
        if (!found)
        {
            free(indices);
            free(temp_words);
            return (NULL);
        }
        for (j = 0; j < nb_words; j++)
        {
            temp_words[j] = (char *)s + i + j * word_len;
            int k, matched = 0;

            for (k = 0; k < nb_words; k++)
            {
                if (!found[k] && strncmp(temp_words[j], words[k], word_len) == 0)
                {
                    found[k] = 1;
                    matched = 1;
                    break;
                }
            }
            if (!matched)
                break;
        }
        if (j == nb_words)
            indices[count++] = i;

        free(found);
    }

    free(temp_words);

    if (count == 0)
    {
        free(indices);
        return (NULL);
    }

    *n = count;
    return (indices);
}
