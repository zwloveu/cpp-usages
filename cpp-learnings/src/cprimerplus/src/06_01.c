#include <stdio.h>

#define MONTHS 12

int days_sum(const int *const);

int main(void)
{
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int index = 0; index < MONTHS; index++)
        printf("Month %2d has %d days.\n", index + 1,
               *(days + index));

    int *p_days = days;
    for (int index = 0; index < MONTHS; index++)
        printf("Month %2d has %d days.\n", index + 1,
               p_days[index]);

    printf("The address of days is %p.\n"
           "The value of p_days is %p.\n"
           "The address of the first elemment of days is %p.\n"
           "The address of the second elemment of days is %p.\n"
           "The step between the elements of days is %zd.\n"
           "days of one year is %d",
           days,
           p_days,
           &days[0],
           &days[1],
           // address1-address2 with same type = elements count
           // Convert to char* to get bytes count
           (char *)&days[1] - (char *)&days[0],
           days_sum(days));

    return 0;
}

int days_sum(const int *const days)
{
    int total = 0;

    for (int index = 0; index < MONTHS; index++)
    {
        total += *(days + index);
    }

    return total;
}