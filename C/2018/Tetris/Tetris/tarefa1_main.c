#include "include\tetris.h"

int main() {
	int n;
	int l, a, x, desl, rot, y, valido, pontos = 0;
	int i, j, k;

	int matriz[ALTURA_TABULEIRO][LARGURA_TABULEIRO];

	for (j = 0; j < ALTURA_TABULEIRO; j++) {
		for (i = 0; i < LARGURA_TABULEIRO; i++) {
			matriz[j][i] = 0;
		}
	}

	scanf_s("%d", &n);

	for (k = 0; k < n; k++) {
		scanf_s("%d %d %d %d %d", &l, &a, &x, &desl, &rot);

		atualiza_posicao(&l, &a, &x, desl, rot);
		y = encontra_y(matriz, l, x);
		valido = posicao_final_valida(a, y);

		if (valido) {
			posiciona_bloco(matriz, l, a, x, y);
			pontos += atualiza_matriz(matriz);

			printf("bloco %d\n", k);
			printf("%d pontos\n", pontos);

			for (j = ALTURA_TABULEIRO - 1; j >= 0; j--) {
				for (i = 0; i < LARGURA_TABULEIRO; i++) {
					printf("%d", matriz[j][i]);
				}

				printf("\n");
			}
		}
		else {
			printf("\nGame Over");
			break;
		}
	}

	return 0;
}
