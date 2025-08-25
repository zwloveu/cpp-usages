#ifndef DATA_STRUCTURES_DICTIONARY_DICTIONARY_H
#define DATA_STRUCTURES_DICTIONARY_DICTIONARY_H

typedef struct DicNode
{
    char *key;
    void *value;
    struct DicNode *next;
} DicNode;

typedef struct Dictionary
{
    struct DicNode **table;
    size_t size;
    size_t count;
} Dictionary;

unsigned int hash(const char *const key, size_t size);

struct Dictionary *dict_create(size_t size);
void dict_insert(Dictionary *dict, const char *const key, const void *const value);
void *dict_find(Dictionary *dict, const char *const key);
void dict_delete(Dictionary *dict, const char *const key);
void dict_destroy(Dictionary *dict);
void dict_iterate(Dictionary *dict, void (*func)(const char *const key, const void *const value));

#endif // DATA_STRUCTURES_DICTIONARY_DICTIONARY_H
