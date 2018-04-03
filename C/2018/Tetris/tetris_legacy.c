
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