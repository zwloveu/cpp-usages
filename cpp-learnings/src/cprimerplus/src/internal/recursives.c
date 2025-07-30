#include <stdio.h>
#include "recursives.h"

void recursive_print(char ch, int count)
{
    if (count <= 0)
        return;

    recursive_print(ch, count - 1);

    for (int i = 0; i < count; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
}

void recursive_print_times_table(unsigned short count)
{
    if (count >= 9)
        count = 9;

    if (count <= 0)
        return;

    recursive_print_times_table(count - 1);

    for (int i = 0; i < count; i++)
    {
        printf("%2d * %2d = %2d  ", count, i + 1, count * (i + 1));
    }
    printf("\n");
}