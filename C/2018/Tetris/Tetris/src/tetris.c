/* Tarefa 1 - Tetris
 * Nome: Leonardo Vencovsky
 * RA: 201710276
 */

#include "..\include\tetris.h"

/* Funcao: atualiza_posicao
 *
 * Parametros:
 *     *l: apontador para a largura do bloco que ira cair
 *     *a: apontador para a altura do bloco que ira cair
 *     *x: apontador para a posicao horizontal inicial do bloco que ira cair
 *   desl: deslocamento horizontal a ser aplicado ao bloco (positivo para
 *         direita, negativo para a esquerda)
 *    rot: 1 se deve rotacionar o bloco, 0 caso contrario
 *
 * Retorno:
 *   NULL
 */
void atualiza_posicao(int *l, int *a, int *x, int desl, int rot) {

	if (rot == 1) {
		// Ir� rotacionar, trocar altura por largura
		int k = *l;
		*l = *a;
		*a = k;

	}

	/* Se n�o h� deslocamento n�o h� mudan�a
	 * Se o usu�rio colocar um deslocamento que posicione o bloco fora do
	 * tabuleiro, por conven��o, o bloco ir� se deslocar at� o limite do
	 * tabuleiro e parar.
	 */
	if (desl > 0) {
		// Deslocamento para a direita
		if (*x + *l + desl > LARGURA_TABULEIRO)
			*x = LARGURA_TABULEIRO - *l; // Por conven��o
		else
			*x = *x + desl;
	}
	else if (desl < 0) {
		// Deslocamento para a esquerda
		if (*x + desl < 0)
			*x = 0; // Por conven��o
		else
			*x = *x + desl;
	}

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
int encontra_y(int mat[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int x) {
	
	int i, j, tot = 0, pos = 0;

	/* Escanear matriz para encontrar quanto que o bloco poder� descer sem
	 * se sobrepor a outros blocos j� posicionados. Note que precisamos checar
	 * apenas as colunas onde o bloco ir� descer pois os movimentos j� foram
	 * pr�-inseridos. O escaneamento � dado verticalmente, ou seja, o loop
	 * interno percorre a matriz na vertical.
	 */
	for (i = 0; i < LARGURA_TABULEIRO; i++) {
		for (j = x; j < x + l; j++) {
			tot += mat[i][j];
		}
		printf("\ntot: %d, i: %d, j: %d, POS: %d", tot, i, j, pos);
		if (tot == 0) {
			return i;
		}

		tot = 0;

	}

	return i;
}

/* Funcoes: posicao_final_valida
 *
 * Parametros:
 *      a: altura do bloco que caiu
 *      y: altura final do bloco que caiu
 *
 * Retorno:
 *   1 se o bloco naquela posicao estiver contido dentro do tabuleiro, ou 0 caso
 *   contrario.
 */
int posicao_final_valida(int a, int y) {
	
	/* Se o bloco ir� cair dentro do tabuleiro em rela��o � vertical. Se a altura
	 * do bloco mais sua posi��o final vertical de onde o bloco caiu for maior
	 * que a altura do tabuleiro � porque o jogador "perdeu".
	 */	
	if (y + a > ALTURA_TABULEIRO)
		return 0;

	return 1;
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
 *      Deve preencher com 1s as novas posi��es ocupadas pelo bloco que caiu
 * Retorno:
 *   NULL
 */
void posiciona_bloco(int mat[ALTURA_TABULEIRO][LARGURA_TABULEIRO], int l, int a, int x, int y) {
	
	int i, j;
	
	/* Os novos blocos s�o posicionados na matriz
	 */
	for (i = y; i < y + a; i++)
		for (j = x; j < x + l; j++)
			mat[i][j] = 1;

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
int atualiza_matriz(int mat[ALTURA_TABULEIRO][LARGURA_TABULEIRO]) {
	
	int i, j, k, l, tot = 0;

	/* O escaneamento da matriz � dado na horizontal. Se a soma dos blocos
	 * naquela linha forem igual � largura da matriz � porque aquela linha
	 * dever� ser removida. Assim todos os blocos acima devem descer uma
	 * posi��o verticalmente e ent�o uma nova linha vazia deve ser inserida
	 * na primeira linha da matriz para manter se tamanho.
	 */

	for (i = 0; i < ALTURA_TABULEIRO; i++) {

		for (j = 0; j < LARGURA_TABULEIRO; j++) {
			if (mat[i][j] == 1)
				tot++;
		}

		if (tot == LARGURA_TABULEIRO) {
			
			/* Linha deve ser removida. Come�ar opera��o de descer todos os
			 * blocos uma posi��o para baixo. Note que "i" � a vari�vel da
			 * linha a ser removida.
			 */

			for (k = i - 1; k < ALTURA_TABULEIRO; k++) {
				for (l = 0; l < LARGURA_TABULEIRO; l++) {
					mat[k - 1][l] = mat[k][l];
				}
			}


		}

		tot = 0;

	}


	return 0;
}
