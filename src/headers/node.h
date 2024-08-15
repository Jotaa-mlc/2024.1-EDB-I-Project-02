#ifndef NODE_DEFINITION
#define NODE_DEFINITION
#include "sortition.h"

typedef struct node
{
    Sortition sort;
    struct node *next;
    struct node *prev;
}Node;

#endif