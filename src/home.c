#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers/features.h"

void print_main_menu()
{
    printf("/-----------------------------------------------\\\n");
    printf("|              1 - Inserir Concurso             |\n");
    printf("|              2 - Buscar Concurso              |\n");
    printf("|              3 - Remover Concurso             |\n");
    printf("|           4 - Listar todos Concursos          |\n");
    printf("|              5 - Carregar arquivo             |\n");
    printf("|           6 - Apresentar estatísticas         |\n");
    printf("|             7 - Ecerrar o Programa            |\n");
    printf("\\-----------------------------------------------/\n");
}

int sair()//confirmação de saida
{
    char resposta = ' ';
    printf("Certeza que deseja deixar o programa?\nDigite 's' para confirmar\n");

    scanf("\n%c", &resposta);
    resposta = tolower(resposta);
    if(resposta == 's')
        return 1;
    else
        return 0;
}

int main()
{
    Hash *hash_table = initialize_hash(3000);

    int logout = 0;
    char buffer[10] = {0};
    int cmd;

    while (!logout)
    {
        print_main_menu();

        cmd = atoi(fgets(buffer, 4, stdin));

        switch (cmd)
        {
            case 1://Inserir Concurso
                inserir_concurso(hash_table);
                break;
            
            case 2://Buscar Concurso
                buscar_concurso(hash_table);
                break;
            
            case 3://Remover Concurso
                remover_concurso(hash_table);
                break;
            
            case 4://Listar todos os Concursos
                listar_concursos(hash_table);
                break;
            
            case 5://Carregar arquivo
                carregar_arquivo(hash_table);
                break;
            
            case 6://Apresentar estatísticas
                apresentar_estatisticas(hash_table);
                break;
            
            case 7://sair do programa
                logout = sair();
                break;
            
            default:
                printf("Comando inválido!\nFavor insira um comando descrito no menu.\n");
                break;
        }
        printf("\n\n");
    }
    return 0;
}