#include <stdio.h>
#include <string.h>
#include "mymath/mymath.h"
#include <thirdparty/mymath2/mymath.h>

#define DENSITY 62.4

int main(void)
{
    double weight, volume;
    size_t size, letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s", name);

    printf("%s, what's your weight in pounds?\n", name);
    scanf("%lf", &weight);

    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;

    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %zd letters,\n", letters);
    printf("and we have %zd bytes to store it.\n", size);

    printf("1 + 2 = %d\n", add(1, 2));
    printf("3 + 4 = %d\n", add2(3, 4));

    return 0;
}