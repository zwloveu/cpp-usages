#include <stdio.h>

typedef struct z_t
{
    int i;
    char c;
    char ccc[3];
    
    
    
} z_t;

int main(void)
{
    printf("C version: %ld\n", __STDC_VERSION__);

    size_t size_z_t = sizeof(z_t);

    printf("size of z_t is %zd", size_z_t);

    return 0;
}
