#include "headers/features.h"
#include "headers/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100


void inserir_concurso(Hash *h)
{

}

void buscar_concurso(Hash *h)
{
    
}

void remover_concurso(Hash *h)
{

}

void listar_concursos(Hash *h)
{
    printf("\nLista de todos os Sorteios:\n");
    printf("Concurso - Data - Bola 1 - Bola 2 - Bola 3 - Bola 4 - Bola 5 - Bola 6\n");

    for (unsigned int i = 0; i < h->capacity; i++)
    {
        if (h->table[i])
        {
            print_list(h->table[i]);  
        }
    }
}

void carregar_arquivo(Hash *h)
{
    char file_path[BUFFER_SIZE] = {0};
    char buffer[BUFFER_SIZE] = {0};
    char *sep;

    printf("\nInforme o caminho do arquivo que deseja carregar: ");
    fgets(file_path, 49, stdin);
    file_path[strcspn(file_path, "\n")] = 0;

    sep = strstr(file_path, ".csv") ? "," : "\t";

    FILE *sortition_file = fopen(file_path, "r");

    if (!sortition_file)
    {
        printf("ERRO: Não foi possível abrir o arquivo especificado.\n");
        return;
    }

    fgets(buffer, BUFFER_SIZE - 1, sortition_file);

    while (fgets(buffer, BUFFER_SIZE - 1, sortition_file))
    {
        char *buff;
        Sortition *sort = calloc(1, sizeof(Sortition));
        
        buff = strtok(buffer, sep);
        sort->contest = atoi(buff);

        buff = strtok(NULL, sep);
        sscanf(buff, "%u-%u-%u", &sort->dt.day, &sort->dt.month, &sort->dt.year);

        for (int i = 0; i < 6; i++)
        {
            buff = strtok(NULL, sep);
            sort->draw_num[i] = atoi(buff);
        }
        
        memset(buffer, 0, BUFFER_SIZE);
        if (!insert_hash(h, sort))
            printf("\nNão foi possível inserir o sorteio de numero %u.\nJá existe um concurso com esse número", sort->contest);
    }   
}

void apresentar_estatisticas(Hash *h)
{

}