#ifndef MODULE01_MEMORY_ALIGNMENT_STRUCTS_H
#define MODULE01_MEMORY_ALIGNMENT_STRUCTS_H

typedef struct StructByte8
{
    int i;
    char c;
    char ccc[3];
} StructByte8;

typedef struct StructByte12
{
    char c;
    int i;
    char ccc[3];
} StructByte12;

#endif // MODULE01_MEMORY_ALIGNMENT_STRUCTS_H
