#ifndef DATA_STRUCTURES_DICTIONARY_DICT_TYPES_H
#define DATA_STRUCTURES_DICTIONARY_DICT_TYPES_H

typedef enum KeyType
{
    KEY_TYPE_INT,
    KEY_TYPE_STRING,
    KEY_TYPE_POINTER,
    KEY_TYPE_FLOAT,
    KEY_TYPE_CHAR,
    KEY_TYPE_MAX
} KeyType;

typedef enum ValueType
{
    VALUE_TYPE_INT,
    VALUE_TYPE_STRING,
    VALUE_TYPE_POINTER,
    VALUE_TYPE_FLOAT,
    VALUE_TYPE_FUNCTION,
    VALUE_TYPE_CHAR,
    VALUE_TYPE_MAX
} ValueType;

typedef struct DictValue
{
    ValueType type;
    void *data;
} DictValue;

typedef struct DictKey
{
    KeyType type;
    void *data;
    struct DictValue *value_ptr;
} DictKey;

typedef struct DictEntry
{
    DictKey *key;
    DictValue *value;
    struct DictEntry *next;
} DictEntry;

typedef struct Dictionary
{
    DictEntry **entries;
    size_t capacity;
    size_t count;
} Dictionary;

#endif // DATA_STRUCTURES_DICTIONARY_DICT_TYPES_H