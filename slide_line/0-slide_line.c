#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */

#include "slide_line.h"
#include <stdio.h>

/**
 * slide_left - Slides and merges an array to the left.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_left(int *line, size_t size)
{
    size_t i, j;
    
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (j < i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j++;
        }
    }

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1] && line[i] != 0)
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }
    
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (j < i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j++;
        }
    }
}

/**
 * slide_right - Slides and merges an array to the right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_right(int *line, size_t size)
{
    size_t i, j;
    
    for (i = size, j = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            if (j > i)
            {
                line[j - 1] = line[i - 1];
                line[i - 1] = 0;
            }
            j--;
        }
    }

    for (i = size; i > 1; i--)
    {
        if (line[i - 1] == line[i - 2] && line[i - 1] != 0)
        {
            line[i - 1] *= 2;
            line[i - 2] = 0;
        }
    }
    
    for (i = size, j = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            if (j > i)
            {
                line[j - 1] = line[i - 1];
                line[i - 1] = 0;
            }
            j--;
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return (1);
}
