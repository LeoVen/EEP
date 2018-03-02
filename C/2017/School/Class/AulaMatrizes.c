#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//AULA DE MATRIZES
/*
int main()
{
    //MATRIZ:

    int m[3][3];
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            scanf("%d", &m[i][j]); //Ler uma matriz
        }
    }

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%c%d", ' ', m[i][j]); //Mostrar a matriz
        }
        printf("\n");
    }
}
*/

/*
EXERCICIOS

1-Declarar uma matriz 3x3 e carregar com 0s. Imprimir a matriz (feito acima).
2-Ler uma matriz quadrada 3x3 com valores de usuário. Imprimir os elementos da diagonal principal.
*/
/*
int main()
{
   //EXERCICIO 2


}
*/

int main()
{
    //Exercício de encontrar o Determinante da matriz

    int m[3][3];
    int i, j, d;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            scanf("%d", &m[i][j]); //Ler uma matriz
        }
    }

    printf("\nA matriz: \n\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%c%5d", ' ', m[i][j]); //Mostrar a matriz
        }
        printf("\n");
    }
    //CALCULO DA DETERMINANTE:
    d = (m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[1][0] * m[2][1] * m[0][2]) - (m[0][1] * m[1][0] * m[2][2]) - (m[0][0] * m[1][2] * m[2][1]) - (m[0][2] * m[1][1] * m[2][0]);


    printf("Tem um Determinante de: %d", d);

}
