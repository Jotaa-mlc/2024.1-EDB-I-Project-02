#include "headers/features.h"
#include "headers/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir_concurso(Hash *h)
{
    char buffer[BUFFER_SIZE] = {0};
    Sortition sort = {0};
    printf("\nInserindo um concurso\nPor favor insira as informações conforme solicitado.\n");

    int contest_ok = 0;
    while (!contest_ok)
    {
        printf("Número do concurso: ");
        fgets(buffer, BUFFER_SIZE - 1, stdin);

        sort.contest = atoi(buffer);
        
        if (search_item_hash(h, sort.contest).contest != 0)
        {
            printf("Já existe um concurso com o número: %u\n", sort.contest);
            printf("Por favor, insira um número que não esteja cadastrado.\n");
        }
        else
        {
            contest_ok = 1;
        }
        memset(buffer, 0, BUFFER_SIZE);
    }

    printf("Insira a data no formato dd-MM-yyyy (Ex.: 23-7-2003): ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    sscanf(buffer,"%u-%u-%u\n", &sort.dt.day, &sort.dt.month, &sort.dt.year);
    memset(buffer, 0, BUFFER_SIZE);

    printf("Insira os números sorteados no formato");

    for (int i = 0; i < DRAW_NUM; i++)
        printf(" n%i", i + 1);
    printf(": ");

    fgets(buffer, BUFFER_SIZE - 1, stdin);
    char *buff = strtok(buffer, " ");
    for (int i = 0; i < DRAW_NUM; i++)
    {
        sort.draw_num[i] = atoi(buff);
        buff = strtok(NULL, " ");
    }
    memset(buffer, 0, BUFFER_SIZE);

    if (!insert_hash(h, &sort))
    {
        printf("Não foi possível inserir o sorteio.\n");
    }
    else
    {
        printf("O Concurso foi inserido com sucesso.\n");
    }
}

void buscar_concurso(Hash *h)
{
    char buffer[BUFFER_SIZE] = {0};
    unsigned int contest = 0;
    printf("\nDigite o número do concurso que deseja buscar: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    contest = atoi(buffer);

    Sortition sort = search_item_hash(h, contest);
    if (sort.contest != 0)
    {
        printf("\nFoi encontrado o seguite Sorteio:\n");
        print_sortition(sort);
    }
    else
    {
        printf("\nNão foi possível localizar nenhum concurso com o número: %u\n", contest);
    }
}

void remover_concurso(Hash *h)
{
    char buffer[BUFFER_SIZE] = {0};
    unsigned int contest = 0;
    printf("\nDigite o número do concurso que deseja remover: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    contest = atoi(buffer);

    Sortition sort = remove_item_hash(h, contest);
    if (sort.contest != 0)
    {
        printf("O seguinte sorteio foi removido:\n");
        print_sortition(sort);
    }
    else
    {
        printf("Não foi possível localizar o concurso de número: %u\n", contest);
    }
}

void listar_concursos(Hash *h)
{
    printf("\nLista de todos os Sorteios:\n");
    print_sortition_header();

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

        for (int i = 0; i < DRAW_NUM; i++)
        {
            buff = strtok(NULL, sep);
            sort->draw_num[i] = atoi(buff);
        }
        
        memset(buffer, 0, BUFFER_SIZE);
        if (!insert_hash(h, sort))
            printf("\nNão foi possível inserir o sorteio de numero %u.\nJá existe um concurso com esse número", sort->contest);
    }   
}

void print_statistics_menu()
{
    printf("/-----------------------------------------------\\\n");
    printf("|    1 - Quantidade de sorteios de um número    |\n");
    printf("|         2 - Dez números mais sorteados        |\n");
    printf("|        3 - Dez números menos sorteados        |\n");
    printf("|            4 - Concursos de um ano            |\n");
    printf("\\-----------------------------------------------/\n");
}

void apresentar_estatisticas(Hash *h)
{
    print_statistics_menu();
    char buffer[BUFFER_SIZE] = {0};
    int cmd;

    fgets(buffer, BUFFER_SIZE - 1, stdin);
    cmd = atoi(buffer);

    switch (cmd)
    {
        case 1:
            estatisticas_sorteio_1numero(h);
            break;
        
        case 2:
            estatisticas_10mais_sorteados(h);
            break;
        
        case 3:
            estatisticas_10menos_sorteados(h);
            break;
        
        case 4:
            estatisticas_concursos_ano(h);
            break;
        
        default:
            printf("Comando inválido!\nFavor insira um comando descrito no menu.\n");
            break;
    }
}