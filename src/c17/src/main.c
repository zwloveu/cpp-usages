#include <stdio.h>

#include "data_structures/dictionary/dictionary.h"

void print_pair(const char *key, const void *const value)
{
    printf("%s: %s\n", key, (char *)value);
}

int main(void)
{
    printf("C version: %ld\n", __STDC_VERSION__);

    Dictionary *dict = dict_create(10);
    if (!dict)
    {
        printf("字典创建失败\n");
        return 1;
    }

    dict_insert(dict, "name", "张三");
    dict_insert(dict, "age", "25");
    dict_insert(dict, "city", "北京");

    printf("\n所有条目:\n");
    dict_iterate(dict, print_pair);

    return 0;
}
