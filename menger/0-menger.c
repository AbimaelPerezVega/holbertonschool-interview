#include "menger.h"

/**
 * is_blank - Determines if a position should be blank
 * @x: X coordinate
 * @y: Y coordinate
 *
 * Return: 1 if blank, 0 otherwise
 */
int is_blank(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return (1);
        x /= 3;
        y /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: Level of the Menger Sponge
 */
void menger(int level)
{
    int size, x, y;

    if (level < 0)
        return;

    size = pow(3, level);

    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            if (is_blank(x, y))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
