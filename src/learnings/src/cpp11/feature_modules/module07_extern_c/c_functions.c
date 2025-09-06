#include "cpp11/feature_modules/module07_extern_c/c_functions.h"

void print_c_version(void)
{
    printf("C standard version: %ld\n", __STDC_VERSION__);
}

char to_lower(char letter)
{
    if (!is_letter(letter))
        return letter;

    if ((letter >= 'A') && (letter <= 'Z'))
        return letter - 'A' + 'a';

    return letter;
}

char to_upper(char letter)
{
    if (!is_letter(letter))
        return letter;

    if ((letter >= 'a') && (letter <= 'z'))
        return letter - 'a' + 'A';

    return letter;
}

bool is_letter(char letter)
{
    return (letter >= 'A' && letter <= 'Z') ||
           (letter >= 'a' && letter <= 'z');
}

size_t get_length(const char *const str)
{
    if (str == NULL)
        return 0;

    const char *ptr = str;
    while (*ptr != '\0')
        ptr++;

    return ptr - str;
}

void str_copy(const char *src, char *dest)
{
    if (src == NULL || dest == NULL)
        return;

    while ((*dest++ = *src++) != '\0')
        ;

    /* explanation for while ((*dest++ = *src++) != '\0');
    char temp;
    do
    {
        temp = *src;
        *dest = temp;
        src++;
        dest++;
    } while (temp != '\0');
    */
}

void swap(int *first, int *second)
{
    if (first == NULL || second == NULL)
        return;

    int temp = *first;
    *first = *second;
    *second = temp;
}

void swap_by_callback(int *first, int *second, CallBackSwapFunc callback)
{
    callback(first, second);
}

void up_and_down(int n)
{
    printf("Level %d: n location %p\n", n, (void *)&n); // 1
    if (n < 4)
        up_and_down(n + 1);
    printf("LEVEL %d: n location %p\n", n, (void *)&n); // 2
}

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
