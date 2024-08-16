#include "headers/features.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_CALCULADOS 10

int *calcular_sorteios_por_numero(Hash *h)
{
    int *numbers = calloc(MAX_DRAW, sizeof(int));

    for (unsigned int i = 0; i < h->capacity; i++)
    {
        if (h->table[i])
        {
            Node *current = h->table[i]->header;
            while (current)
            {
                for (int i = 0; i < DRAW_NUM; i++)
                {
                    numbers[current->sort.draw_num[i] - 1]++;
                }
                current = current->next;
            }
        }
    }
    return numbers;
}

void estatisticas_sorteio_1numero(Hash *h)
{
    char buffer[BUFFER_SIZE] = {0};
    int num = 0;
    printf("\nDe qual número deseja saber a quantidade de vezes que ele foi sorteado? ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);

    num = atoi(buffer);
    if (num > 0 || num <= MAX_DRAW)
    {
        int *numeros = calcular_sorteios_por_numero(h);
        int count = numeros[num - 1];


        printf("De %u sorteios, o número %i foi sorteado %i vezes.\n", h->size, num, count);
        double per = ((double)count / (double)h->size * 100.0);
        printf("Ele esteve presente em %6.3lf %% dos sorteios", per);
        free(numeros);
    }
    else
    {
        printf("Por favor insira um número válido para o sorteio.\n");
    }
}

void estatisticas_10mais_sorteados(Hash *h)
{
    int *numeros = calcular_sorteios_por_numero(h);
    int numeros_mais[NUM_CALCULADOS] = {0};
    int qte_numeros_mais[NUM_CALCULADOS] = {0};

    for (int i = 0; i < NUM_CALCULADOS; i++)
    {
        int max = 0;
        int num_max = 0;
        for (int j = 0; j < MAX_DRAW; j++)
        {
            if (numeros[j] > max)
            {
                max = numeros[j];
                num_max = j;
            }
        }
        qte_numeros_mais[i] = max; 
        numeros_mais[i] = num_max;
        numeros[num_max] = 0;
    }

    printf("Os %i números mais sorteados foram:\n", NUM_CALCULADOS);
    printf("N° - Vezes Sorteado - Sorteado em %% dos jogos\n");

    for (int i = 0; i < NUM_CALCULADOS; i++)
    {
        double per = ((double)qte_numeros_mais[i] / (double)h->size * 100.0);
        printf("%2i - %4i - %6.3lf %%\n", numeros_mais[i] + 1, qte_numeros_mais[i], per);
    }
    
    free(numeros);
}

void estatisticas_10menos_sorteados(Hash *h)
{
    int *numeros = calcular_sorteios_por_numero(h);
    int numeros_menos[NUM_CALCULADOS] = {0};
    int qte_numeros_menos[NUM_CALCULADOS] = {0};

    for (int i = 0; i < NUM_CALCULADOS; i++)
    {
        int min = (int)h->size;
        int num_min = 0;
        for (int j = 0; j < MAX_DRAW; j++)
        {
            if (numeros[j] < min)
            {
                min = numeros[j];
                num_min = j;
            }
        }
        qte_numeros_menos[i] = min; 
        numeros_menos[i] = num_min;
        numeros[num_min] = (int)h->size;
    }

    printf("Os %i números menos sorteados foram:\n", NUM_CALCULADOS);
    printf("N° - Vezes Sorteado - Sorteado em %% dos jogos\n");

    for (int i = 0; i < NUM_CALCULADOS; i++)
    {
        double per = ((double)qte_numeros_menos[i] / (double)h->size * 100.0);
        printf("%2i - %4i - %6.3lf %%\n", numeros_menos[i] + 1, qte_numeros_menos[i], per);
    }
    
    free(numeros);
}

void estatisticas_concursos_ano(Hash *h)
{
    List *concursos_ano = initialize_list();
    unsigned int year = 0;
    char buffer[BUFFER_SIZE] = {0};
    printf("\nDe qual ano está buscando os concursos? ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);

    year = atoi(buffer);

    for (unsigned int i = 0; i < h->capacity; i++)
    {
        if (h->table[i])
        {
            Node *current = h->table[i]->header;
            while (current)
            {
                if (current->sort.dt.year == year)
                    push_back(concursos_ano, &current->sort);
                current = current->next;
            }
        }
    }

    if (concursos_ano->size > 0)
    {
        printf("Foram encontrados %4u concursos no ano de %4u.\n", concursos_ano->size, year);
        print_sortition_header();
        print_list(concursos_ano);
    }
    else
    {
        printf("Não foram encontrados concursos para o ano de %4u.\n", year);
    }
    free(concursos_ano);
}