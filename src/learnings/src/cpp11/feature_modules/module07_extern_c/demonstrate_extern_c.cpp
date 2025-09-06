#include <iostream>

#include "cpp11/feature_modules/module07_extern_c/demonstrate_extern_c.h"
#include "cpp11/feature_modules/module07_extern_c/c_functions.h"

void demonstrate_extern_c_basic()
{
    print_c_version();

    std::cout << "Is '\\n' a letter: " << is_letter('\n') << std::endl;
    std::cout << "C to_lower is: " << to_lower('C') << std::endl;
    std::cout << "c to_upper is: " << to_upper('c') << std::endl;
    const char *const src = "abcdef";
    std::cout << "src is: " << src << std::endl;
    size_t src_length = get_length(src);
    std::cout << "length of src is: " << src_length << std::endl;
    std::cout << "copy src to dest, str_copy(src, dest): " << std::endl;
    char *const dest = (char *)malloc(src_length);
    str_copy(src, dest);
    std::cout << "dest is: " << dest << std::endl;
    free(dest);

    int a = 5, b = 10;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "swap(a,b)" << std::endl;
    swap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "swap_by_callback(a, b, swap)" << std::endl;
    swap_by_callback(&a, &b, swap);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    up_and_down(1);
    recursive_print('*', 10);
    recursive_print_times_table(9);
}