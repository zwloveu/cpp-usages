#ifndef DATA_STRUCTURES_DICTIONARY_DICT_INSERT_H
#define DATA_STRUCTURES_DICTIONARY_DICT_INSERT_H

#include <stdbool.h>
#include "data_structures/dictionary/dict_types.h"

#define DEFAULT_EXPANSION_FACTOR 0.7

bool dict_insert_int_key_int_value(Dictionary *dict, int key, int value);
bool dict_insert_str_key_int_value(Dictionary *dict, const char *key, int value);
bool dict_insert_int_key_str_value(Dictionary *dict, int key, const char *const value);
bool dict_insert_str_key_str_value(Dictionary *dict, const char *key, const char *const value);
bool dict_insert_char_key_float_value(Dictionary *dict, char key, float value);
bool dict_insert_float_key_str_value(Dictionary *dict, float key, const char *const value);
bool dict_insert_str_key_func_value(Dictionary *dict, const char *const key, void (*const func)());
bool dict_insert_ptr_key_ptr_value(Dictionary *dict, const void *const key, const void *const value);

#endif // DATA_STRUCTURES_DICTIONARY_DICT_INSERT_H