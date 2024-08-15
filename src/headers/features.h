#ifndef FEATURES_
#define FEATURES_
#include "hash.h"

void inserir_concurso(Hash *h);
void buscar_concurso(Hash *h);
void remover_concurso(Hash *h);
void listar_concursos(Hash *h);
void carregar_arquivo(Hash *h);
void apresentar_estatisticas(Hash *h);

#endif