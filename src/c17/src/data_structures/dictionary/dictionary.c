#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structures/dictionary/dictionary.h"

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
    dict->table = (struct DicNode **)malloc(sizeof(struct DicNode *) * size);

    return dict;
}

void dict_insert(struct Dictionary *dict, const char *const key, void *const value)
{
    if (!dict || !key || !value)
        return;

    unsigned int index = hash(key, dict->size);

    struct DicNode *current = dict->table[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    struct DicNode *new_node = (struct DicNode *)malloc(sizeof(DicNode *));
    if (!new_node)
        return;

    new_node->key = (char *)malloc(strlen(key) + 1);
    if (new_node->key != NULL)
    {
        strcpy(new_node->key, key);
    }
    new_node->value = value;
    new_node->next = dict->table[index];
    dict->table[index] = new_node;
    dict->count++;
}

void *dict_find(struct Dictionary *dict, const char *const key)
{
    if (!dict || !key)
        return NULL;

    unsigned int index = hash(key, dict->size);
    struct DicNode *current = dict->table[index];

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

void dict_delete(struct Dictionary *dict, const char *const key)
{
    if (!dict || !key)
        return;

    unsigned int index = hash(key, dict->size);
    struct DicNode *current = dict->table[index];
    struct DicNode *prev = NULL;

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

void dict_destroy(struct Dictionary *dict)
{
    if (!dict)
        return;

    for (int i = 0; i < dict->size; i++)
    {
        struct DicNode *current = dict->table[i];
        while (current)
        {
            struct DicNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }

    free(dict->table);
    free(dict);
}

void dict_iterate(struct Dictionary *dict, void (*func)(const char *const key, const void *const value))
{
    if (!dict || !func)
        return;

    for (int i = 0; i < dict->size; i++)
    {
        struct DicNode *current = dict->table[i];
        while (current)
        {
            func(current->key, current->value);
            current = current->next;
        }
    }
}