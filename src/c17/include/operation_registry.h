#ifndef OPERATION_REGISTRY_H
#define OPERATION_REGISTRY_H

#include <stdlib.h>
#include <string.h>

typedef void (*OperationFunc)(void);

typedef struct OperationNode
{
    char *key;
    OperationFunc func;
    struct OperationNode *next;
} OperationNode;

static struct
{
    OperationNode *head;
} s_registry = {NULL};

static void register_operation(const char *const key, OperationFunc func)
{
    OperationNode *node = (OperationNode *)malloc(sizeof(OperationNode));
    node->key = strdup(key);
    node->func = func;
    node->next = s_registry.head;
    s_registry.head = node;
}

#endif // OPERATION_REGISTRY_H
