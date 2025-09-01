#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data_structures/dictionary/dictionary.h"
#include "data_structures/dictionary/dict_utils.h"

Dictionary* dict_init(const size_t initial_capacity) {
    int capacity =  initial_capacity;
    if (capacity == 0) {
        capacity = DEFAULT_DICT_CAPACITY;
    }

    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    if (!dict) {
        fprintf(stderr, "failed to malloc for Dictionary in dict_init\n");
        return NULL;
    }

    dict->entries = (DictEntry**)calloc(initial_capacity, sizeof(DictEntry*));
    if (!dict->entries) {
        fprintf(stderr, "failed to calloc entries in dict_init\n");
        free(dict);
        return NULL;
    }

    dict->capacity = initial_capacity;
    dict->count = 0;

    return dict;
}

void dict_destroy(Dictionary* dict) {
    if (!dict) return;

    for (size_t i = 0; i < dict->capacity; i++) {
        DictEntry* current = dict->entries[i];
        while (current) {
            DictEntry* next = current->next;
            free_entry(current);
            current = next;
        }
    }

    free(dict->entries);
    free(dict); 
}

size_t dict_get_count(const Dictionary* dict) {
    return dict ? dict->count : 0;
}

DictEntry* dict_get_entry(const Dictionary* dict, const size_t index) {
    if (!dict || index >= dict->capacity) {
        return NULL;
    }
    return dict->entries[index];
}

DictEntry* dict_find_entry(const Dictionary* dict, const DictKey* key) {
    if (!dict || !key) return NULL;

    size_t hash = key->type;
    switch (key->type) {
        case KEY_TYPE_INT:
            hash ^= *(int*)key->data;
            break;
        case KEY_TYPE_STRING:
            hash ^= strlen((const char*)key->data);
            break;
        case KEY_TYPE_POINTER:
            hash ^= (size_t)key->data;
            break;
        case KEY_TYPE_FLOAT:
            hash ^= *(unsigned int*)key->data;
            break;
        case KEY_TYPE_CHAR:
            hash ^= *(char*)key->data;
            break;
        default:
            break;
    }
    
    size_t index = hash % dict->capacity;
    
    DictEntry* current = dict->entries[index];
    while (current) {
        if (keys_are_equal(current->key, key)) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}