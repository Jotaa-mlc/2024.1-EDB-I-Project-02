#ifndef SORTEIO_
#define SORTEIO_

#define DRAW_NUM 6
#define MAX_DRAW 60

typedef struct date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
}Date;

typedef struct sortition
{
    unsigned int contest;
    Date dt;
    int draw_num[DRAW_NUM];
}Sortition;

void print_sortition(Sortition sort);
#endif