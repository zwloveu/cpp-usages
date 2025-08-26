#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structures/dictionary/dictionary.h"

struct DicNode
{
    char *key;
    void *value;
    DicNode *next;
};

struct Dictionary
{
    DicNode **table;
    size_t size;
    size_t count;
};

unsigned int hash(const char *const key, size_t size)
{
    unsigned int hash = 0;
    for (size_t i = 0; i < size; i++)
    {
        hash = hash * 31 + key[i];
    }
    return hash % size;
}

Dictionary *dict_create(size_t size)
{
    if (size == '\0')
        return NULL;

    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    if (!dict)
        return NULL;

    dict->size = size;
    dict->count = 0;
    dict->table = (DicNode **)calloc(size, sizeof(DicNode *));

    return dict;
}

void dict_insert(Dictionary *dict, const char *const key, void *const value)
{
    if (!dict || !key || !value)
        return;

    unsigned int index = hash(key, dict->size);

    DicNode *current = dict->table[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    DicNode *new_node = (DicNode *)malloc(sizeof(DicNode));
    if (!new_node)
        return;

    new_node->key = (char *)malloc(strlen(key) + 1);
    strncpy(new_node->key, key, strlen(key) + 1);
    new_node->key[strlen(key)] = '\0';
    // if (new_node->key != NULL)
    // {
    //     strcpy(new_node->key, key);
    // }
    new_node->value = value;
    new_node->next = dict->table[index];
    dict->table[index] = new_node;
    dict->count++;
}

void *dict_find(Dictionary *dict, const char *const key)
{
    if (!dict || !key)
        return NULL;

    unsigned int index = hash(key, dict->size);
    DicNode *current = dict->table[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void dict_delete(Dictionary *dict, const char *const key)
{
    if (!dict || !key)
        return;

    unsigned int index = hash(key, dict->size);
    DicNode *current = dict->table[index];
    DicNode *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                dict->table[index] = current->next;
            }

            free(current->key);
            free(current);
            dict->count--;
            return;
        }

        prev = current;
        current = current->next;
    }
}

void dict_destroy(Dictionary *dict)
{
    if (!dict)
        return;

    for (size_t i = 0; i < dict->size; i++)
    {
        DicNode *current = dict->table[i];
        while (current)
        {
            DicNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }

    free(dict->table);
    free(dict);
}

void dict_iterate(Dictionary *dict, void (*func)(const char *const key, const void *const value))
{
    if (!dict || !func)
        return;

    for (size_t i = 0; i < dict->size; i++)
    {
        DicNode *current = dict->table[i];
        while (current)
        {
            func(current->key, current->value);
            current = current->next;
        }
    }
}