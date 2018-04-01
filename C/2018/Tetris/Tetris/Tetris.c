/* Tarefa 1 - Tetris
 * Nome: Leonardo Vencovsky
 * RA: 201710276
 *
 * Created on 01/04/2018
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum Status {
	OK,
	SUCCESS,
	ERROR
} Status;

#define ALTURA_TABULEIRO 10
#define LARGURA_TABULEIRO 10

#define CLEAR_SCREEN "cls"
//#define CLEAR_SCREEN "clear"

/* Funcao: atualiza_posicao
 *
 * Parametros:
 *     *l: apontador para a largura do bloco que ira cair
 *     *a: apontador para a altura do bloco que ira cair
 *     *x: apontador para a posicao horizontal inicial do bloco que ira cair
 *   desl: deslocamento horizontal a ser aplicado ao bloco (positivo para direita, negativo para a esquerda)
 *    rot: 1 se deve rotacionar o bloco, 0 caso contrario
 *
 * Retorno:
 *   NULL
 */
void atualiza_posicao(int *l, int *a, int *x, int desl, int rot) {
	/* Implementar a funcao */
}

/* Funcao: encontra_y
 *
 * Parametros:
 *    mat: matriz representando o tabuleiro
 *      l: largura do bloco que ira cair
 *      x: posicao horizontal do bloco que ira cair
 *
 * Retorno:
 *   altura final y do canto inferior esquerdo do bloco apos
 *   este descer o maximo possivel
 */
int encontra_y(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int x) {
	/* Implementar a funcao e trocar o valor de retorno */
	return 0;
}

/* Funcoes: posicao_final_valida
 *
 * Parametros:
 *      a: altura do bloco que caiu
 *      y: altura final do bloco que caiu
 *
 * Retorno:
 *   1 se o bloco naquela posicao estiver contido dentro do tabuleiro, ou 0 caso contrario.
 */
int posicao_final_valida(int a, int y) {
	/* Implementar a funcao e trocar o valor de retorno */
	return 0;
}

/* Funcoes: posiciona_bloco
 *
 * Parametros:
 *    mat: matriz do tabuleiro
 *      l: largura do novo bloco
 *      a: altura do novo bloco
 *      x: posicao horizontal do novo bloco
 *      y: altura final do novo bloco
 *
 *      Deve preencher com 1s as novas posições ocupadas pelo bloco que caiu
 * Retorno:
 *   NULL
 */
void posiciona_bloco(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int a, int x, int y) {
	/* Implementar a funcao */
}

/* Funcoes: atualiza_matriz
 *
 * Parametros:
 *    mat: matriz do tabuleiro
 *
 *         Deve remover as linhas totalmente preenchidas do tabuleiro copiando
 *         linhas posicionadas acima.
 * Retorno:
 *   retorna o numero de linhas totalmente preenchidas que foram removidas apos
 *   a atualizacao do tabuleiro.
 */
int atualiza_matriz(int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO]) {
	/* Implementar a funcao e trocar o valor de retorno */
	return 0;
}

/**
 * Inicializa novo tetris
 *
 * Cada posicao do tabuleiro é inicializada com 0 representado nenhum bloco
 * naquele local
 *
 * @param[in] largura Largura do tabuleiro
 * @param[in] altura ALtura do tabuleiro
 * @param[out] tetris Tabuleiro tetris a ser inicializado
 *
 * @return Status SUCCESS se a inicialização foi bem sucedida
 */
Status pega_tetris(size_t largura, size_t altura, int*** tetris)
{
	int i, j;
	*tetris = (int**)malloc(largura * sizeof(int**));
	for (i = 0; i < largura; i++)
		(*tetris)[i] = (int *)malloc(altura * sizeof(int*));
	for (i = 0; i < largura; i++) {
		for (j = 0; j < altura; j++) {
			(*tetris)[i][j] = 0;
		}
	}
	return SUCCESS;
}

/**
 * Mostra o tabuleiro tetris no console
 *
 * @param[in] tetris Matriz do tabuleiro tetris
 */
void display_tetris(int** tetris)
{
	int i, j;
	for (i = 0; i < LARGURA_TABULEIRO; i++) {
		for (j = 0; j < ALTURA_TABULEIRO; j++) {
			printf("%d ", tetris[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |             Tetris Game             |\n");
	printf(" |                                     |\n");
	printf(" |  Created by                         |\n");
	printf(" |  Leonardo Vencovsky                 |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" | Instruções                          |\n");
	printf(" |                                     |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	printf("\nPressione Enter para continuar...\n> ");
	getchar();

	int** tetris;
	if (pega_tetris(LARGURA_TABULEIRO, ALTURA_TABULEIRO, &tetris) == SUCCESS) {
		printf("\nTetris Inicializado\n");
	}
	display_tetris(tetris);

	system(CLEAR_SCREEN);
	printf("\n");
	free(tetris);
	return 0;
}