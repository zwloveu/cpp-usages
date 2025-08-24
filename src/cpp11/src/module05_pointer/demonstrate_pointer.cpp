#include <iostream>
#include <iomanip>

#include "module05_pointer/demonstrate_pointer.h"

void demonstrate_pointer_basic()
{
    int rows = 3, cols = 4;
    int *const p_flat_array = new int[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p_flat_array[i * cols + j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "table1[" << i << "] [" << j << "]: " << &p_flat_array[i * cols + j] << std::endl;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << p_flat_array[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] p_flat_array;
}

void demonstrate_pointer_p2array()
{
    constexpr int rows = 3, cols = 4;
    int (*const p_2d_row_array)[cols] = new int[rows][cols];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "p2arrayrow[" << i << "] [" << j << "]: " << &p_2d_row_array[i][j] << std::endl;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p_2d_row_array[i][j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << p_2d_row_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] p_2d_row_array;
}

void demonstrate_pointer_p2p()
{
    int rows = 3, cols = 4;
    int **const p2p = new int *[rows]; // memory is not continuous for each row
    for (int i = 0; i < rows; i++)
    {
        p2p[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "p2p[" << i << "] [" << j << "]: " << &p2p[i][j] << std::endl;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p2p[i][j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << p2p[i][j] << " "; //*(*(p2p + i) + j)
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] p2p[i];
    }
    delete[] p2p;
}

void demonstrate_pointer_p_to_first()
{
    const unsigned short array_flat[]{10, 20, 30, 40, 50, 60, 70, 80};
    const unsigned short array_2d[][4]{{1, 2, 3, 4}, {5, 6, 7, 8}};
    const int array_3d[][2][2]{{{-1, -2}, {-3, -4}}, {{-5, -6}, {-7, -8}}};

    const unsigned short *const pointer_to_first_element_of_flat_array = array_flat;
    const unsigned short (*const pointer_to_first_element_of_2d_array)[4] = array_2d;
    const int (*const pointer_to_first_element_of_3d_array)[2][2] = array_3d;

    for (size_t index = 0; index < 8; index++)
    {
        std::cout << "pointer_to_first_element_of_flat_array[" << index << "] = " << pointer_to_first_element_of_flat_array[index] << std::endl;
    }

    for (size_t index = 0; index < 8; index++)
    {
        std::cout << "pointer_to_first_element_of_2d_array[" << index << "] = " << (*pointer_to_first_element_of_2d_array)[index] << std::endl;
    }

    for (size_t index = 0; index < 8; index++)
    {
        std::cout << "pointer_to_first_element_of_3d_array[" << index << "] = " << (**pointer_to_first_element_of_3d_array)[index] << std::endl;
    }
}

void demonstrate_pointer_void()
{
    // void (*print_data)(const void *const data, const char type) = ......
    auto print_data = [](const void *const data, const char type)
    {
        switch (type)
        {
        case 'i':
            std::cout << "Integer: " << *(int *)data << std::endl;
            break;
        case 'f':
            std::cout << "Float: " << std::fixed << std::setprecision(2) << *(float *)data << std::endl;
            break;
        case 'c':
            std::cout << "Character: " << *(char *)data << std::endl;
            break;
        default:;
        }
    };

    int num = 10;
    float pi = 3.14F;
    char ch = 'A';

    print_data(&num, 'i');
    print_data(&pi, 'f');
    print_data(&ch, 'c');
}