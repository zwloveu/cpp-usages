#include <iostream>

#include "module05_pointer/demonstrate_pointer.h"

void demonstrate_pointer_basic()
{
    int rows = 3, cols = 4;
    int **table = new int *[rows]; // memory is not continuous for each row
    for (int i = 0; i < rows; i++)
    {
        table[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "table[" << i << "] [" << j << "]: " << &table[i][j] << std::endl;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            table[i][j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] table[i];
    }
    delete[] table;
    table = nullptr;

    int *table1 = new int[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            table1[i * cols + j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "table1[" << i << "] [" << j << "]: " << &table1[i * cols + j] << std::endl;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << table1[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] table1;
    table1 = nullptr;

    constexpr int rows1 = 3, cols1 = 4;
    int (*table2)[cols1] = new int[rows1][cols1];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "table2[" << i << "] [" << j << "]: " << &table2[i][j] << std::endl;
        }
    }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            table2[i][j] = i * cols1 + j;
        }
    }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            std::cout << table2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] table2;
    table1 = nullptr;
}