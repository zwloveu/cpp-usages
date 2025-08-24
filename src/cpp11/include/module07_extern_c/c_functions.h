#ifndef MODULE07_EXTERN_C_C_FUNCTIONS_H
#define MODULE07_EXTERN_C_C_FUNCTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

    void print_c_version();

    bool is_letter(char letter);
    char to_lower(char letter);
    char to_upper(char letter);
    size_t get_length(const char *const str);
    void str_copy(const char *const src, char *const dest);

    void swap(int *first, int *second);
    typedef void (*CallBackSwapFunc)(int *, int *);
    void swap_by_callback(int *first, int *second, CallBackSwapFunc callback);

    void up_and_down(int n);
    void recursive_print(char, int);
    void recursive_print_times_table(unsigned short);

#ifdef __cplusplus
}
#endif
#endif