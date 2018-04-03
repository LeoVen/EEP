#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define ALTURA_TABULEIRO 10
#define LARGURA_TABULEIRO 10

	void atualiza_posicao(int *l, int *a, int *x, int desl, int rot);
	int encontra_y(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int x);
	int posicao_final_valida(int a, int y);
	void posiciona_bloco(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int a, int x, int y);
	int atualiza_matriz(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO]);

#ifdef __cplusplus
}
#endif