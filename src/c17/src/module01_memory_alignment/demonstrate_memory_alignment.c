#include <stdio.h>

#include "module01_memory_alignment/demonstrate_memory_alignment.h"
#include "module01_memory_alignment/structs.h"

void demonstrate_memory_alignment_basic()
{
    size_t a = sizeof(StructByte8);
    size_t b = sizeof(StructByte12);
    printf("sizeof(StructByte8) = %zd\n", a);
    printf("sizeof(StructByte12) = %zd\n", b);
}
