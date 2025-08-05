#include <stdio.h>
#include <string.h>

#define MONTHS 12

int days_sum(const int *const);
void print_data(const void *const data, const char type);

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
           "The address of the first element of days is %p.\n"
           "The address of the second element of days is %p.\n"
           "The step between the elements of days is %zd.\n"
           "days of one year is %d.\n",
           (void *)days,
           (void *)p_days,
           (void *)&days[0],
           (void *)&days[1],
           // address1-address2 with same type = elements count
           // Convert to char* to get bytes count
           (char *)&days[1] - (char *)&days[0],
           days_sum(days));

    int num = 10;
    float pi = 3.14;
    char ch = 'A';

    print_data(&num, 'i');
    print_data(&pi, 'f');
    print_data(&ch, 'c');

    printf("void * occupies %zd bytes.\n", sizeof(void *));

    char multiple[] = "a string";
    char *p = multiple;
    // char * can be implicitly converted to void *
    printf("address of multiple is %p.\n", multiple);
    for (size_t i = 0; i < strlen(multiple); i++)
        printf("\nmultiple[%td] = %c  *(p+%td) = %c  &multiple[%td] = %p  p+%td = %p",
               i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);

    int multiple1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p1 = multiple1;
    printf("address of multiple1 is %p.\n", (void *)multiple1);
    for (size_t i = 0; i < 9; i++)
        printf("\nmultiple1[%td] = %d  *(p+%td) = %d  &multiple1[%td] = %p  p+%td = %p",
               i, multiple1[i], i, *(p1 + i), i, (void *)&multiple1[i], i, (void *)(p1 + i));

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

void print_data(const void *const data, const char type)
{
    switch (type)
    {
    case 'i':
        printf("Integer: %d\n", *(int *)data);
        break;
    case 'f':
        printf("Float: %.2f\n", *(float *)data);
        break;
    case 'c':
        printf("Character: %c\n", *(char *)data);
        break;
    default:;
    }
}