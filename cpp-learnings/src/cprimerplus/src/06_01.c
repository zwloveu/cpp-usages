#include <stdio.h>
#include <string.h>
#include <assert.h>

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
    float pi = 3.14F;
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

    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    /* List all elements of the array */
    for (int i = 0; i < 9; i++)
        // here board, the name of the array, which type is `T (*)[N]`
        // will be implicitly converted to a pointer to which the first line it points.
        // then *board is the first line itself, which type is `T[N]`
        // in c, the array(here is the first line) will be
        // implicitly converted to a pointer to which the first element it points.
        // so finally *board is the address of the first element in the first line,
        // which type is T*,
        // then we can use *board +i to move the next element.
        printf(" board: %c\n", *(*board + i));

    unsigned short board1[2][3][3] = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},
        {{10, 20, 30},
         {40, 50, 60},
         {70, 80, 90}}};
    /* List all elements of the array */
    for (int i = 0; i < 18; i++)
        // board1, type is short[M][[N][O]
        // *board1 -> board1[0] which type is short (*)[N][O], and it is an array too
        // *board -> short(*)[N][O] -> short (*)[O]
        // **board -> short *, points to board1[0][0][0]
        printf(" board1[%d]: %hd\n", i, *(**board1 + i));

    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    // pz points to the first line of zippo int [2]{2, 4}
    const int (*const pz)[2] = zippo;
    int (*const pz0)[4][2] = &zippo;
    (*pz0)[3][1] = 70;
    printf("pz0's value is %p.\n", pz0);
    printf("zippo's address is %p.\n", (void *)zippo);
    printf("pz's value is %p.\n", (void *)pz);
    printf("size of pz is %zd.\n", sizeof(pz));
    assert(pz == zippo);
    assert(sizeof(pz) == sizeof(int) * 2);
    assert(*(*(pz + 0) + 0) == 2);
    assert(*(*(pz + 0) + 1) == 4);
    const int (*pz1)[2] = pz + 1;
    assert(sizeof(pz1) == sizeof(int) * 2);
    assert(*(*(pz1 + 0) + 0) == 6);
    assert(*(*(pz1 + 0) + 1) == 8);
    int item_index_in_zippo = 0;
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 2; column++)
        {
            // pz[row][column] = *(*(pz + row) + column)
            printf("zippo[%d][%d] = %d\n", row, column, pz[row][column]);
            printf("zippo[%d] = %d\n",
                   item_index_in_zippo,
                   *(*pz + item_index_in_zippo++));
        }
    }

    int *pt1 = (int[2]){10, 20};
    for (size_t index = 0; index < 2; printf("pt1[%zd] = %d\n", index, pt1[index++]))
        ;

    int (*pt2)[4] = (int[2][4]){{1, 2, 3, -9}, {4, 5, 6, -8}};
    for (size_t index = 0; index < 8; printf("pt2[%zd] = %d\n", index, (*pt2)[index++]))
        ;

    int (*pt3)[2][2] = (int[2][2][2]){{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    for (size_t index = 0; index < 8; printf("pt3[%zd] = %d\n", index, (**pt3)[index++]))
        ;

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