#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
1. Faça um programa que imprima um menu de 4 pratos na tela e uma quinta opção para sair
do programa. O programa deve imprimir o prato solicitado. O programa deve terminar
quando for escolhido a quinta opção.
*/
/*
int main()
{
    int i, p;

    for (i=0; p!=5; i++) {
        printf("\n\nEscolha um menu de 1 a 4 e use 5 para sair: ");
        scanf("%d", &p);

        if (p==1) {
            printf("\n\tSalada\n\tArroz\n\tFeijao\n\tBatata Frita\n\tBife");
        }

        else if (p==2) {
            printf("\n\tMacarrao\n\tMolho branco\n\tMolho vermelho\n\t");
        }

        else if (p==3) {
            printf("\n\tMandioca Frita\n\tArroz colorido\n\tVagem\n\tBrocolois");
        }

        else if (p==4) {
            printf("\n\tSushi\n\tTemaki\n\tPeixe frito\n\tShimeji\n\tHot roll");
        }

        else printf("Digite um numero valido \n");

    }
}
*/

/*
2. Faça um programa que lê dois números inteiros positivos a e b. Utilizando laços, o seu
programa deve calcular e imprimir o valor a^b.
*/

int main()
{
    int a, b, i, j, k, aux=0;

    printf("Valor de a: ");
    scanf("%d", &a);
    printf("Valor de b: ");
    scanf("%d", &b);

    for (i=0; i<b; i++) {
        for (j=0; aux<a; aux++);
    }

    printf("%d", aux);

}





























