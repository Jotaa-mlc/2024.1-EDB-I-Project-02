#include "headers/hash.h"
#include <stdlib.h>

Hash *initialize_hash(int capacity)
{
    Hash *h = calloc(1, sizeof(Hash));
    if (h)
    {
        h->size = 0;
        h->capacity = capacity;
        h->table = calloc(h->capacity, sizeof(List*));
    }
    else
    {
        h = NULL;
    }
    
    return h;
}

void destruct_hash(Hash *h)
{
    for (unsigned int i = 0; i < h->capacity; i++)
    {
        if (h->table[i] != NULL)
        {
            free(h->table[i]);
        }
    }

    free(h->table);
    free(h);
}

int hash_fun(int key, int capacity)
{
    return key % capacity;
}

int insert_hash(Hash *h, Sortition *sort)
{
    if (search_item_hash(h, sort->contest).contest != 0)
    {
        int key = hash_fun(sort->contest, h->capacity);

        if (h->table[key])
        {
            push_back(h->table[key], sort);
        }
        else
        {
            h->table[key] = initialize_list();
            push_back(h->table[key], sort);
        }        
    }
    else // Sortition alredy exist 
    {
        return -1;
    }
}

int remove_rash(Hash *h, int contest)
{
    int key = hash_fun(contest, h->capacity);

    if (h->table[key])
    {
        if(search_item_list(h->table[key], contest).contest != 0)
        {
            
        }
    }

    return 0;
}

Sortition search_item_hash(Hash *h, int contest)
{
    int key = hash_fun(contest, h->capacity);

    if (h->table[key])
        return search_item_list(h->table[key], contest);
    
    Sortition sort = {0};
    return sort;
}
