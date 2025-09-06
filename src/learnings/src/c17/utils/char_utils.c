#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "c17/utils/consts.h"
#include "c17/utils/char_utils.h"

char *chars_safe_cpy(const char *const src)
{
    if (!src)
        return NULL;

    size_t str_len = strlen(src);
    char *dest = (char *)malloc(str_len + 1);
    if (!dest)
        return NULL;

    strncpy(dest, src, str_len);
    dest[str_len] = TERMINAL_SYMBOL;

    return dest;
}

/*
 * free pointer created by chars_safe_cpy
 * Example
 * char *str = chars_safe_cpy("example");
 * chars_safe_free(&str);
 */
void chars_safe_free(char **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}