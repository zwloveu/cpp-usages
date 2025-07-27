#include <stdio.h>

int main(void)
{
    char ch = 'A';
    printf("The char is %c, and it is %d.\n", ch, ch);

    short end = 200;
    printf("The short is %hd and %d.\n", end, end);

    unsigned int un = 300000000;
    printf("The unsigned int is %u and not %d.\n", un, un);

    long big = 65537;
    printf("The long is %ld and not %hd.\n", big, big);

    long long very_big = 12345678908642;
    printf("The long long is %lld.\n", very_big);

    float about = 32000.0;
    printf("The float %f can be written %e.\n", about, about);

    double abet = 2.14e9;
    printf("The double %f can be written %e.\n", abet, abet);

    long double dip = 5.32e-5;
    printf("The long double %Lf can be written %Le.\n", dip, dip);

    printf("Gramps sez, \"a \\ is a backslash.\"\n");
    printf("The nonprinting zero ASCII `\\0` is %c and is %c. It is used to mark the end of a string", '\0', 0);

    return 0;
}