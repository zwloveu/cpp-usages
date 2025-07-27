#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#define PAGES 959
#define BLURB "Authentic imitation!"

int main(void)
{
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type long double has a size of %zd bytes.\n", sizeof(long double));

    printf("\n");

    printf("Number of bits in a char is %d.\n", CHAR_BIT);
    printf("Maximum char value is %d.\n", CHAR_MAX);
    printf("Minimum char value is %d.\n", CHAR_MIN);
    printf("Maximum signed char value is %d.\n", SCHAR_MAX);
    printf("Minimum signed char value is %d.\n", SCHAR_MIN);
    printf("Maximum unsigned char value is %u.\n", UCHAR_MAX);

    printf("Maximum short value is %d.\n", SHRT_MAX);
    printf("Minimum short value is %d.\n", SHRT_MIN);
    printf("Maximum unsigned short value is %u.\n", USHRT_MAX);

    printf("Maximum int value is %d.\n", INT_MAX);
    printf("Minimum int value is %d.\n", INT_MIN);
    printf("Maximum unsigned int value is %u.\n", UINT_MAX);

    printf("Maximum long value is %ld.\n", LONG_MAX);
    printf("Minimum long value is %ld.\n", LONG_MIN);
    printf("Maximum unsigned long value is %lu.\n", ULONG_MAX);
    printf("Maximum long long value is %lld.\n", LLONG_MAX);
    printf("Minimum long long value is %lld.\n", LLONG_MIN);
    printf("Maximum unsigned long long value is %llu.\n", ULLONG_MAX);

    printf("Number of bits in the mantissa of a float is %d.\n", FLT_MANT_DIG);
    printf("Minimum number of significant decimal digits for a float is %d.\n", FLT_DIG);
    printf("Minimum base-10 negative exponent for a float is %d.\n", FLT_MIN_10_EXP);
    printf("Maximum base-10 positive exponent for a float is %d.\n", FLT_MAX_10_EXP);
    printf("Minimum value for a positive float retaining full precision is %e.\n", FLT_MIN);
    printf("Maximum value for a positive float is %e.\n", FLT_MAX);
    printf("Difference between 1.00 and the least float value greater than 1.00 is %e.\n", FLT_EPSILON);

    printf("\n");

    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);

    printf("\n");

    const double RENT = 3852.99;
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);

    printf("\n");

    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);

    printf("\n");

    int rv = printf("[%30s]\n", BLURB);
    printf("The printf() function printed %d characters.\n", rv);

    const double ADJUST = 7.31;
    const double SCALE = 0.333;
    double shoe, foot;
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe size (men's) foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
    printf("%10.1f %15.2f\n", 9.0, 10.31);

    return 0;
}