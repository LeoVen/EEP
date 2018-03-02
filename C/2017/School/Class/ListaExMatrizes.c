#include <stdio.h>
#include <stdlib.h>

//LISTA EXERCICIOS DE MATRIZ
//Leonardo Vencovsky

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();
void ex7();
void ex8();

int main()
{
    int ex;
    while (ex!=0){

        system("cls");
        printf("Digite 0 para sair.\nEscolha o Exercicio: ");
        scanf("%d", &ex);

        switch(ex)
        {
        case 0:
            break;
        case 1:
            ex1();
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            ex2();
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            ex3();
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            ex4();
            printf("\n");
            system("PAUSE");
            break;
        case 5:
            ex5();
            printf("\n");
            system("PAUSE");
            break;
        case 6:
            ex6();
            printf("\n");
            system("PAUSE");
            break;
        case 7:
            ex7();
            printf("\n");
            system("PAUSE");
            break;
        case 8:
            ex8();
            printf("\n");
            system("PAUSE");
            break;
        default :
            printf("\n\nNumero Invalido");
            printf("\n");
            system("PAUSE");
            break;
        }
    }
}

void ex1()
{
    printf("\nExercicio 1:\n\n");

    //Variables
    int h, w, i, j, row, column;
    float max;

    //Code
    printf("Tamanho da matriz: \n");
    printf("Linhas: ");
    scanf("%d", &h);
    printf("colunas: ");
    scanf("%d", &w);

    float matriz[h][w]; //Iniciando a Matriz

    for (i=0; i<h; i++) { //Lendo a Matriz
        for (j=0; j<w; j++){
            scanf("%f", &matriz[i][j]);
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                column = j;
                row = i;
            }
        }
    }

    for (i=0; i<h; i++) { //Escrevendo a Matriz
        for (j=0; j<w; j++) {
            printf("%10.2f", matriz[i][j]);
        }
        printf("\n");
    }

    row++; //Reajuste das variáveis
    column++;

    printf("\nO maior numero esta localizado na linha %d coluna %d", row, column);
}

void ex2()
{
    printf("\nExercicio 2:\n\n");

    //Variables
    int i, j, matriz[5][5];

    //Code
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            if (i == j) {
                printf("%5d", 1);
            } else printf("%5d", 0);
        }
        printf("\n");
    }
}

void ex3()
{
    printf("\nExercicio 3:\n\n");

    //Variables
    int h, w, i, j, count=0;


    //Code
    printf("Tamanho da matriz: \n");
    printf("Linhas: ");
    scanf("%d", &h);
    printf("colunas: ");
    scanf("%d", &w);

    float matriz[h][w];

    for (i=0; i<h; i++) { //Lendo a Matriz
        for (j=0; j<w; j++){
            scanf("%f", &matriz[i][j]);
            if (matriz[i][j] > 10) {
                count++;
            }
        }
    }

    for (i=0; i<h; i++) { //Escrevendo a Matriz
        for (j=0; j<w; j++) {
            printf("%10.2f", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nA quantidade de numeros maior que 10 e: %d", count);
}

void ex4()
{
    printf("\nExercicio 4:\n\n");

    //Variables
    int i, j, h, w, row=-1, column=-1, count=0;
    float x;

    //Code
    printf("Tamanho da matriz: \n");
    printf("Linhas: ");
    scanf("%d", &h);
    printf("colunas: ");
    scanf("%d", &w);

    float matriz[h][w];

    for (i=0; i<h; i++) { //Lendo a Matriz
        for (j=0; j<w; j++){
            //scanf("%f", &matriz[i][j]);
            matriz[i][j] = count;
            count++;
        }
    }

    printf("Digite o numero que busca na matriz: ");
    scanf("%f", &x);

    for (i=0; i<h; i++) { //Buscando na Matriz
        for (j=0; j<w; j++){
            if (matriz[i][j] == x) {
                row = i;
                column = j;
            }
        }
    }

    if (row == -1 && column == -1){
        printf("Numero nao encontrado na Matriz");
    }
    else {
        row++; //Reajuste de Variáveis
        column++;

        printf("\nO numero foi encontrado na linha %d coluna %d\n", row, column);
    }

    for (i=0; i<h; i++) { //Imprimindo a Matriz
        for (j=0; j<w; j++){
            printf("%8.2f", matriz[i][j]);
            }
            printf("\n");
        }
}

void ex5()
{
    printf("\nExercicio 5:\n\n");

    //Variables
    int h, w, i, j;
    float aux;


    //Code
    printf("Tamanho da matriz: \n");
    printf("Linhas: ");
    scanf("%d", &h);
    printf("colunas: ");
    scanf("%d", &w);

    float matriz[h][w];

    for (i=0; i<h; i++) { //Lendo a Matriz
        for (j=0; j<w; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz Original: \n");

    for (i=0; i<h; i++) { //Escrevendo a Matriz
        for (j=0; j<w; j++) {
            printf("%10.2f", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz Trocando a primeira linha pela quarta coluna: \n");

    for (i=0; i<h; i++) { //Trocando a primeira linha pela quarta coluna
        for (j=0; j<w; j++) {
            aux = matriz[i][j];

        }
    }
}

void ex6()
{
    printf("\nExercicio 6:\n\n");

    //Variables

    //Code
}

void ex7()
{
    printf("\nExercicio 7:\n\n");

    //Variables

    //Code
}

void ex8()
{
    printf("\nExercicio 8:\n\n");

    //Variables

    //Code
}
