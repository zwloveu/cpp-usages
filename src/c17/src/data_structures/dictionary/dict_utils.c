#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data_structures/dictionary/dict_utils.h"

bool keys_are_equal(const DictKey* key1, const DictKey* key2) {
    if (!key1 || !key2 || key1->type != key2->type) {
        return false;
    }

    switch (key1->type) {
        case KEY_TYPE_INT:
            return *(int*)key1->data == *(int*)key2->data;
        case KEY_TYPE_STRING:
            return strcmp((const char*)key1->data, (const char*)key2->data) == 0;
        case KEY_TYPE_POINTER:
            return key1->data == key2->data;
        case KEY_TYPE_FLOAT:
            return *(float*)key1->data == *(float*)key2->data;
        case KEY_TYPE_CHAR:
            return *(char*)key1->data == *(char*)key2->data;
        default:
            return false;
    }
}

bool dict_resize(Dictionary* dict, const size_t new_capacity) {
    if (!dict || new_capacity <= dict->capacity) {
        return false;
    }

    DictEntry** new_entries = (DictEntry**)realloc(
        dict->entries, new_capacity * sizeof(DictEntry*)
    );
    if (!new_entries) {
        fprintf(stderr, "failed to resize dict\n");
        return false;
    }

    if (new_capacity > dict->capacity) {
        memset(&new_entries[dict->capacity], 0, 
               (new_capacity - dict->capacity) * sizeof(DictEntry*));
    }

    dict->entries = new_entries;
    dict->capacity = new_capacity;

    return true;
}

void free_key(DictKey* key) {
    if (!key) return;

    switch (key->type) {
        case KEY_TYPE_INT:
        case KEY_TYPE_FLOAT:
        case KEY_TYPE_CHAR:
            free(key->data);
            break;
        case KEY_TYPE_STRING:
            free((void*)key->data);
            break;
        case KEY_TYPE_POINTER:
            // handled by outer caller
            break;
        default:
            break;
    }
    free(key);
}

void free_value(DictValue* value) {
    if (!value) return;

    switch (value->type) {
        case VALUE_TYPE_INT:
        case VALUE_TYPE_FLOAT:
        case VALUE_TYPE_CHAR:
            free(value->data);
            break;
        case VALUE_TYPE_STRING:
            free((void*)value->data); 
            break;
        case VALUE_TYPE_POINTER:
        case VALUE_TYPE_FUNCTION:
            // handled by outer caller
            break;
        default:
            break;
    }
    free(value);
}

void free_entry(DictEntry* entry) {
    if (!entry) return;
    
    free_key(entry->key);
    free_value(entry->value);
    free(entry);
}