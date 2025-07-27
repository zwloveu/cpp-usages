#include <stdio.h>

void butler(void);

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

    return 0;
}

void butler(void)
{
    printf("You rang, sir?\n");
}