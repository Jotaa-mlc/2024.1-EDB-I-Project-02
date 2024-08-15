#include "headers/sortition.h"
#include <stdio.h>

void print_sortition(Sortition sort)
{
    printf("%04u | ", sort.contest);
    printf("%02u/%02u/%04u | ", sort.dt.day, sort.dt.month, sort.dt.year);
    for (int i = 0; i < DRAW_NUM; i++)
    {
        printf("%02u | ", sort.draw_num[i]);
    }
    printf("\n");
}