#include "headers/list.h"
#include <stdlib.h>

List *initialize_list()
{
    List *l = calloc(1, sizeof(List));

    if (!l)
        return NULL;

    l->header = NULL;
    l->size = 0;
    return l;
}

int push_back(List *l, Sortition *sort)
{
    Node *current = l->header;
    Node *next = current;
    while (next != NULL)
    {
        current = next;
        next = current->next;
    }

    Node *new_node = calloc(1, sizeof(Node));
    if (!new_node)
        return 0;
    
    new_node->sort = *sort;
    new_node->prev = current;
    new_node->next = NULL;

    if (current != NULL)
    {
        current->next = new_node;
    }
    else
    {
        l->header = new_node;
    }
    
    l->size++;
    return 1;
}

Sortition pop_front(List *l)
{
    Node *current = l->header;
    Sortition sort = current->sort;

    l->header = current->next;
    l->size--;
    free(current);
    return sort;
}

Sortition pop_back(List *l)
{
    Sortition sort = {0};

    Node *current = l->header;
    Node *next = current->next;
    Node *prev = current->prev;

    while (next != NULL)
    {
        current = next;
        prev = current->prev;
        next = current->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL;
    }
    
    sort = current->sort;
    l->size--;
    free(current);
    return sort;
}

Sortition remove_item_list(List *l, int contest)
{
    Sortition sort = {0};
    Node *current = l->header;
    Node *next = current->next;
    Node *prev = current->prev;

    while (current && current->sort.contest != contest)
    {
        current = next;
        next = current->next;
        prev = current->prev;
    }
    
    if (current)
    {
        sort = current->sort;
        if (prev != NULL)
            prev->next = next;

        if (next != NULL)
            next->prev = prev;

        l->size--;
        free(current);
        return sort;
    }
    
    return sort;
}

Sortition search_item_list(List *l, int contest)
{
    Node *current = l->header;
    while (current && current->sort.contest != contest)
    {
        current = current->next;
    }

    if (current)
    {
        return current->sort;
    }

    Sortition sort = {0};
    return sort;
}