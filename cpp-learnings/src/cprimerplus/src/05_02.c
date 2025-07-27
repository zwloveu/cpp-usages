#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

#define STOP '|'

int main(void)
{
    int ch;
    while ((ch = _getch()) != EOF && ch != '#') // unbuffered read
    {
        putchar(ch);
    }

    int c;               // read in characiter
    char prev;           // previous character read
    long n_chars = 0L;   // number of characters
    int n_lines = 0;     // number of lines
    int n_words = 0;     // number of words
    int p_lines = 0;     // number of partial lines
    bool inword = false; // == true if c is in a word

    const char new_line_char = '\n';

    printf("Enter text to be analyzed (| to terminate):\n");
    prev = new_line_char;
    while ((c = getchar()) != EOF && c != STOP)
    {
        n_chars++;
        if (c == new_line_char)
        {
            n_lines++;
        }

        if (!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }

        if (isspace(c) && inword)
        {
            inword = false;
        }
        prev = (char)c;
    }

    if (prev != new_line_char)
    {
        p_lines = 1;
    }

    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);

    return 0;
}