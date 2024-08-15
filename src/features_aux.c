#include "headers/features.h"
#include <stdio.h>
#include <stdlib.h>

void estatisticas_sorteio_1numero(Hash *h)
{
    char buffer[BUFFER_SIZE] = {0};
    int num = 0;
    int count = 0;
    printf("\nDe qual número deseja saber a quantidade de vezes que ele foi sorteado? ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);

    num = atoi(buffer);

    for (unsigned int i = 0; i < h->capacity; i++)
    {
        if (h->table[i])
        {
            Node *current = h->table[i]->header;
            while (current)
            {
                for (int i = 0; i < DRAW_NUM; i++)
                {
                    if (current->sort.draw_num[i] == num)
                        count++;
                }
                current = current->next;
            }
        }
    }

    printf("De %u sorteios, o número %i foi sorteado %i vezes.\n", h->size, num, count);
    double per = ((double)count / (double)h->size * 100.0);
    printf("Ele esteve presente em %5.3lf %% dos sorteios", per);
}

void estatisticas_10mais_sorteados(Hash *h)
{
    
}

void estatisticas_10menos_sorteados(Hash *h)
{
}

void estatisticas_concursos_ano(Hash *h)
{
}