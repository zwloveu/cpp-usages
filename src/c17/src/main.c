#include <stdio.h>

// #include "data_structures/dictionary/dictionary.h"

void print_pair(const char *key, const void *const value)
{
    printf("%s: %s\n", key, (const char *)value);
}

int main(void)
{
    printf("C version: %ld\n", __STDC_VERSION__);

    // Dictionary *dict = dict_create(10);

    // dict_insert(dict, "name", "simon");
    // dict_insert(dict, "age", "25");
    // dict_insert(dict, "city", "beijing");

    // dict_iterate(dict, print_pair);

    return 0;
}
