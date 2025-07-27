#include <stdio.h>

#define SIZE 10

int main(void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf scores: \n", SIZE);
    for (index = 0; index < SIZE; index++)
    {
        scanf("%d", &score[index]);
    }
    printf("The scores read in are as follow:\n");
    for (index = 0; index < SIZE; index++)
    {
        printf("%5d", score[index]);
    }
    printf("\n");

    for (index = 0; index < SIZE; index++)
        sum += score[index];
    average = (float)sum / SIZE;
    printf("Sum of scores = %d, average = %.2f\n", sum, average);

    return 0;
}