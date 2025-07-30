#include <stdio.h>

void butler(void);
void interchange(int *, int *);

int main(void)
{
    int num;
    num = 1;

    printf("I am a simple ");
    printf("computer.\n");
    printf("My favourte number is %d because it is first.\n", num);

    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n");

    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(&x, &y);
    printf("Now x = %d and y = %d.\n", x, y);

    return 0;
}

void butler(void)
{
    printf("You rang, sir?\n");
}

void interchange(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}