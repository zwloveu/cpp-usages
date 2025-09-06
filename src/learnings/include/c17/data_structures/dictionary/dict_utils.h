#ifndef DATA_STRUCTURES_DICTIONARY_DICT_UTILS_H
#define DATA_STRUCTURES_DICTIONARY_DICT_UTILS_H

#include <stdbool.h>
#include "data_structures/dictionary/dict_types.h"

bool keys_are_equal(const DictKey* key1, const DictKey* key2);
bool dict_resize(Dictionary* dict, const size_t new_capacity);
void free_key(DictKey* key);
void free_value(DictValue* value);
void free_entry(DictEntry* entry);

#endif // DATA_STRUCTURES_DICTIONARY_DICT_UTILS_H