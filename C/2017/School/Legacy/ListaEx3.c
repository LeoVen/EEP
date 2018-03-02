#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//EXERCICIO 2
int main()
{
    //Variables
    int i, j, s, cond=0, aux, a, b, n, cond1=0, cond2=0;

    //Code
    printf("Digite o tamanho dos dois vetores: ");
    scanf("%d", &s);

    int vet1[s], vet2[s], vet[2*s];

    printf("\nDigite o primeiro vetor: ");
    for (i=0; i<s; i++) {
        scanf("%d", &vet1[i]);
    }

    printf("\nDigite o segundo vetor: ");
    for (i = 0; i < s; i++) {
        scanf("%d", &vet2[i]);
    }

    //Reagrupando em ordem crescente vetor 1 e 2

    for (i = 1; i < s; i++) {
        cond = 0;
        for (j = 0; j < s-i; j++) {
            if (vet1[j] > vet1[j+1]) {
                aux = vet1[j];
                vet1[j] = vet1[j + 1];
                vet1[j + 1] = aux;
                cond = 1;
            }
        }
        if (cond == 0) {
            break;
        }
    }

    for (i = 1; i < s; i++) {
        cond = 0;
        for (j = 0; j < s-i; j++) {
            if (vet2[j] > vet2[j+1]) {
                aux = vet2[j];
                vet2[j] = vet2[j + 1];
                vet2[j + 1] = aux;
                cond = 1;
            }
        }
        if (cond == 0) {
            break;
        }
    }

    //Escrevendo vetores 1 e 2

    printf("A: ");

    for (i=0; i<s; i++) {
        printf("%5d", vet1[i]);
    }
    printf("\nB: ");
    for (i=0; i<s; i++) {
        printf("%5d", vet2[i]);
    }

    //Checando Multiplicação

    printf("\nProduto da multiplicacao: ");
    scanf("%d", &n);

    for (i = 0; i < s; i++) {
        if (cond1 == 1) break;
        else if (cond2 == 0) {
            printf("Nao ha resultados");
            break;
        }
        for (j = 0; j < s; j++) {
            if (vet1[i] * vet2[j] == n) {
                a = vet1[i];
                b = vet2[j];
                cond1 = 1;
                cond2 = 1;
                printf("%d X %d = %d", a, b, n);
                break;
            }
        }
    }



}
