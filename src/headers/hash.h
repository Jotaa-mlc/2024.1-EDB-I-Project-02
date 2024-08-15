#ifndef HASH_
#define HASH_
#include "list.h"

typedef struct hash
{
    unsigned int size;
    unsigned int capacity;
    List **table;
}Hash;

Hash *initialize_hash(int capacity);
void destruct_hash(Hash *h);
int hash_fun(int key, int capacity);
int insert_hash(Hash *h, Sortition *sort);
Sortition remove_item_hash(Hash *h, unsigned int contest);
Sortition search_item_hash(Hash *h, unsigned int contest);

#endif