#include <stdio.h>
#include "recursives.h"

void up_and_down(int);

int main(void)
{
    up_and_down(1);

    recursive_print('*', 10);

    recursive_print_times_table(9);

    return 0;
}

void up_and_down(int n)
{
    printf("Level %d: n location %p\n", n, (void *)&n); // 1
    if (n < 4)
        up_and_down(n + 1);
    printf("LEVEL %d: n location %p\n", n, (void *)&n); // 2
}