#ifndef LIST_
#define LIST_
#include "node.h"

typedef struct list
{
    unsigned int size;
    Node *header;
} List;

List *initialize_list();
int push_back(List *l, Sortition *sort);
Sortition pop_front(List *l);
Sortition pop_back(List *l);
Sortition remove_item_list(List *l, unsigned int contest);
Sortition search_item_list(List *l, unsigned int contest);
void print_list(List *l);
#endif