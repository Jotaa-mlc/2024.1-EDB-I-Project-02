#ifndef FEATURES_
#define FEATURES_
#include "hash.h"
#define BUFFER_SIZE 100

void inserir_concurso(Hash *h);
void buscar_concurso(Hash *h);
void remover_concurso(Hash *h);
void listar_concursos(Hash *h);
void carregar_arquivo(Hash *h);
void print_statistics_menu();
void apresentar_estatisticas(Hash *h);
void estatisticas_sorteio_1numero(Hash *h);
void estatisticas_10mais_sorteados(Hash *h);
void estatisticas_10menos_sorteados(Hash *h);
void estatisticas_concursos_ano(Hash *h);

#endif