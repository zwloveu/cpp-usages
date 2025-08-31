#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data_structures/dictionary/dictionary.h"

static bool keys_are_equal(const DictKey* key1, const DictKey* key2) {
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

static void free_key(DictKey* key) {
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

static void free_value(DictValue* value) {
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

static void free_entry(DictEntry* entry) {
    if (!entry) return;
    
    free_key(entry->key);
    free_value(entry->value);
    free(entry);
}

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