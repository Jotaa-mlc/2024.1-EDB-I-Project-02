#include "headers/sortition.h"
#include <stdio.h>

void print_sortition(Sortition sort)
{
    printf("%u | ", sort.contest);
    printf("%2u/%2u/%4u | ", sort.dt.day, sort.dt.month, sort.dt.year);
    for (int i = 0; i < 6; i++)
    {
        printf("%2u | ", sort.draw_num[i]);
    }
    printf("\n");
}