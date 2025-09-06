#ifndef DATA_STRUCTURES_DICTIONARY_DICTIONARY_H
#define DATA_STRUCTURES_DICTIONARY_DICTIONARY_H

#include <stddef.h>

#include "data_structures/dictionary/dict_types.h"

#define DEFAULT_DICT_CAPACITY 20

Dictionary* dict_init(const size_t initial_capacity);
void dict_destroy(Dictionary* dict);
size_t dict_get_count(const Dictionary* dict);
DictEntry* dict_get_entry(const Dictionary* dict, const size_t index);
DictEntry* dict_find_entry(const Dictionary* dict, const DictKey* key);

#endif // DATA_STRUCTURES_DICTIONARY_DICTIONARY_H
