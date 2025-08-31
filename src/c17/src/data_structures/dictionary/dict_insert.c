#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data_structures/dictionary/dict_insert.h"

static DictKey *create_key(KeyType type, const void *const data)
{
    DictKey *key = (DictKey *)malloc(sizeof(DictKey));
    if (!key)
    {
        fprintf(stderr, "failed to malloc key in create_key\n");
        return NULL;
    }

    key->type = type;
    key->value_ptr = NULL;

    switch (type)
    {
    case KEY_TYPE_INT:
        key->data = malloc(sizeof(int));
        if (key->data)
            *(int *)key->data = *(const int *)data;
        break;
    case KEY_TYPE_STRING:
        key->data = strdup((const char *)data);
        break;
    case KEY_TYPE_POINTER:
        key->data = (void *)data;
        break;
    case KEY_TYPE_FLOAT:
        key->data = malloc(sizeof(float));
        if (key->data)
            *(float *)key->data = *(const float *)data;
        break;
    case KEY_TYPE_CHAR:
        key->data = malloc(sizeof(char));
        if (key->data)
            *(char *)key->data = *(const char *)data;
        break;
    default:
        free(key);
        return NULL;
    }

    if (!key->data)
    {
        fprintf(stderr, "failed to malloc data in create_key\n");
        free(key);
        return NULL;
    }

    return key;
}

static DictValue *create_value(ValueType type, const void *const data)
{
    DictValue *value = (DictValue *)malloc(sizeof(DictValue));
    if (!value)
    {
        fprintf(stderr, "failed to malloc malloc in create_value\n");
        return NULL;
    }

    value->type = type;

    switch (type)
    {
    case VALUE_TYPE_INT:
        value->data = malloc(sizeof(int));
        if (value->data)
            *(int *)value->data = *(const int *)data;
        break;
    case VALUE_TYPE_STRING:
        value->data = strdup((const char *)data);
        break;
    case VALUE_TYPE_POINTER:
    case VALUE_TYPE_FUNCTION:
        value->data = (void *)data;
        break;
    case VALUE_TYPE_FLOAT:
        value->data = malloc(sizeof(float));
        if (value->data)
            *(float *)value->data = *(const float *)data;
        break;
    case VALUE_TYPE_CHAR:
        value->data = malloc(sizeof(char));
        if (value->data)
            *(char *)value->data = *(const char *)data;
        break;
    default:
        free(value);
        return NULL;
    }

    if (!value->data)
    {
        fprintf(stderr, "failed to malloc data in create_value\n");
        free(value);
        return NULL;
    }

    return value;
}

static DictEntry *create_entry(DictKey *key, DictValue *value)
{
    if (!key || !value)
        return NULL;

    DictEntry *entry = (DictEntry *)malloc(sizeof(DictEntry));
    if (!entry)
    {
        fprintf(stderr, "failed to malloc entry in create_entry\n");
        return NULL;
    }

    entry->key = key;
    entry->value = value;
    entry->next = NULL;

    key->value_ptr = value;

    return entry;
}

static size_t get_hash_index(const Dictionary *dict, const DictKey *key)
{
    if (!dict || !key)
        return 0;

    size_t hash = key->type;
    switch (key->type)
    {
    case KEY_TYPE_INT:
        hash ^= *(int *)key->data;
        break;
    case KEY_TYPE_STRING:
        hash ^= strlen((const char *)key->data);
        break;
    case KEY_TYPE_POINTER:
        hash ^= (size_t)key->data;
        break;
    case KEY_TYPE_FLOAT:
        hash ^= *(unsigned int *)key->data;
        break;
    case KEY_TYPE_CHAR:
        hash ^= *(char *)key->data;
        break;
    default:
        break;
    }

    return hash % dict->capacity;
}

static int dict_insert_generic(Dictionary *dict, DictKey *key, DictValue *value)
{
    if (!dict || !key || !value)
        return 0;

    if (dict->count > dict->capacity * DEFAULT_EXPANSION_FACTOR)
    {
        if (!dict_resize(dict, dict->capacity * 2))
        {
            free_key(key);
            free_value(value);
            return 0;
        }
    }

    size_t index = get_hash_index(dict, key);

    DictEntry *entry = create_entry(key, value);
    if (!entry)
    {
        free_key(key);
        free_value(value);
        return 0;
    }

    entry->next = dict->entries[index];
    dict->entries[index] = entry;
    dict->count++;

    return 1;
}

bool dict_insert_int_key_int_value(Dictionary *dict, int key, int value)
{
    DictKey *dict_key = create_key(KEY_TYPE_INT, &key);
    DictValue *dict_value = create_value(VALUE_TYPE_INT, &value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_str_key_int_value(Dictionary *dict, const char *const key, int value)
{
    DictKey *dict_key = create_key(KEY_TYPE_STRING, key);
    DictValue *dict_value = create_value(VALUE_TYPE_INT, &value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_int_key_str_value(Dictionary *dict, int key, const char *const value)
{
    DictKey *dict_key = create_key(KEY_TYPE_INT, &key);
    DictValue *dict_value = create_value(VALUE_TYPE_STRING, value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_str_key_str_value(Dictionary *dict, const char *const key, const char *const value)
{
    DictKey *dict_key = create_key(KEY_TYPE_STRING, key);
    DictValue *dict_value = create_value(VALUE_TYPE_STRING, value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_char_key_float_value(Dictionary *dict, char key, float value)
{
    DictKey *dict_key = create_key(KEY_TYPE_CHAR, &key);
    DictValue *dict_value = create_value(VALUE_TYPE_FLOAT, &value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_float_key_str_value(Dictionary *dict, float key, const char *const value)
{
    DictKey *dict_key = create_key(KEY_TYPE_FLOAT, &key);
    DictValue *dict_value = create_value(VALUE_TYPE_STRING, value);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_str_key_func_value(Dictionary *dict, const char *const key, void (*const func)())
{
    DictKey *dict_key = create_key(KEY_TYPE_STRING, key);
    DictValue *dict_value = create_value(VALUE_TYPE_FUNCTION, func);
    return dict_insert_generic(dict, dict_key, dict_value);
}

bool dict_insert_ptr_key_ptr_value(Dictionary *dict, const void *const key, const void *const value)
{
    DictKey *dict_key = create_key(KEY_TYPE_POINTER, key);
    DictValue *dict_value = create_value(VALUE_TYPE_POINTER, value);
    return dict_insert_generic(dict, dict_key, dict_value);
}
