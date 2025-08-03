#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

bool is_letter(char letter);
char to_lower(char letter);
char to_upper(char letter);
size_t get_length(const char * const str);

int main(void)
{
    printf("C standard version: %ld\n", __STDC_VERSION__);

    char zero = 0;
    printf("zero is %c\n", zero);

    char A = 'A';
    printf("A is %d\n", A);
    char a = 'a';
    printf("a is %d\n", a);

    wchar_t LA = L'A';
    printf("LA is %d, sizeof('%lc') is %zd\n", LA, LA, sizeof(LA));
    wchar_t La = L'a';
    printf("La is %d, and is %lc\n", La, La);

    printf("to_lower('%c') = %c\n", 'Z', to_lower('Z'));
    printf("to_upper('%c') = %c\n", 'a', to_upper('a'));

    char str[] = "c language is really good!";
    printf("length of `%s` is %td\n", str, get_length(str));

    return 0;
}

char to_lower(char letter)
{
    if(!is_letter(letter))
        return letter;

     if((letter >= 'A') && (letter <= 'Z')) 
        return letter - 'A' + 'a';

    return letter;
}

char to_upper(char letter)
{
    if(!is_letter(letter))
        return letter;
        
    if((letter >= 'a') && (letter <= 'z'))
        return letter - 'a' + 'A';

    return letter;
}

bool is_letter(char letter)
{
    return (letter >= 'A' && letter <= 'Z') || 
        (letter >= 'a' && letter <= 'z');
}

size_t get_length(const char * const str)
{
    if(str ==NULL)
        return 0;

    const char *ptr = str;
    while(*ptr !='\0')
        ptr++;

    return ptr - str;
}
