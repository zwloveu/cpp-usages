#ifndef OPERATION_REGISTRY_H
#define OPERATION_REGISTRY_H

#include <stdlib.h>
#include <string.h>

#include "c17/data_structures/dictionary/dictionary.h"
#include "c17/data_structures/dictionary/dict_insert.h"

typedef void (*OperationFunc)(void);

static struct
{
    Dictionary *dict;
} s_registry = {NULL};

static void init_registry(void)
{
    if (!s_registry.dict)
    {
        s_registry.dict = dict_init(20);
    }
}

static void register_operation(const char *const key, OperationFunc func)
{
    init_registry();
    if (!s_registry.dict)
        return;

    dict_insert_str_key_func_value(s_registry.dict, key, func);
}

#endif // OPERATION_REGISTRY_H
