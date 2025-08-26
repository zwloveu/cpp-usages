#ifndef OPERATION_REGISTRY_H
#define OPERATION_REGISTRY_H

#include <stdlib.h>
#include <string.h>

#include "data_structures/dictionary/dictionary.h"

typedef void (*OperationFunc)(void);

static struct
{
    Dictionary *dict;
} s_registry = {NULL};

static void init_registry(void)
{
    if (!s_registry.dict)
    {
        s_registry.dict = dict_create(20);
    }
}

static void register_operation(const char *const key, OperationFunc func)
{
    init_registry();
    if (!s_registry.dict)
        return;

    dict_insert(s_registry.dict, key, (void *)func);
}

#endif // OPERATION_REGISTRY_H
