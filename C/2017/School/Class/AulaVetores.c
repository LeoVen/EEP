#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
int main()
{

    //Variaveis
    float soma, media;
    int i;
    float notas[5];

    //Codigo
    //Loop
    for( i = 0; i < 5; i++){
        printf("Digite a nota \t %d", i+1);
        scanf("%f", &notas[i]);
    }//Fim Loop
    soma = 0;
    //Loop
    for( i = 0; i < 5; i++){
        soma = soma + notas[i];
    }//Fim Loop
    printf("Soma das Notas: %f", soma);

    media = soma / 5;
    printf("Media = %f", media);
    return 0;
}
*/
/*
int main()
{
    int n;

    scanf("%d", &n);

    int i, j;
    int v[n];

    for(i=0; i<=n; i++){
        v[i] = i;
        printf("\n%d", v[i]);
    }

    return 0;
}
*/
/*
int main()
{
    int a[10];
    int x, maior, menor;

    for(x=0; x<10; x++){
        printf("Digite um numero ");
        scanf("%d", &a[x]);
    }
    maior = a[0];
    menor = a[0];

    for(x=1; x<10; x++){
        if(a[x]<menor){
            menor = a[x];
        }
        else if(a[x]>maior){
            maior = a[x];
        }
    }
    printf("Maior numero: %d, e menor numero: %d", maior, menor);

    return 0;

}
*/
//Ex 4
/*Ler 7 elementos e guardar em um vetor.
    Imprimir o vetor em ordem inversa */
/*
int main()
{
    //Variables
    int v[7];
    int i, j;

    //Code
    //Loop
    for(i=0; i<7; i++){
        printf("Digite um numero ");
        scanf("%d", &v[i]);
    }
    printf("\nAo inverso:");
    //Loop
    for(j=6; j>-1; j--){
        printf("%d", v[j]);
    }
    return 0;
}
*/

//Ex 5
//Ler um vetor A de 8 posições de inteiros. Calcular a media dos valores do vetor
//Copiar os valores do vetor A em um vetor B, substituindo os valores acima da média por -1
//Imprimir os dois vetores
/*
int main()
{
    //Variables
    int a[8];
    int b[8];
    int i, j, x;
    float media=0;

    //Code
    //Loop
    for(i=0; i<8; i++){
        printf("Digite um numero...");  //To read the vector
        scanf("%d", &a[i]);
        media += a[i];
    }//End Loop
    media /= 8;
    //Loop
    for(j=0; j<8; j++){
        if(a[j] > media) b[j] = -1;     //To change positions to -1 if above average
        else b[j] = a[j];
    }//End Loop
    //Loop
    for(x=0; x<8; x++){
        printf("\n%d", b[x]);           //To print out the resulting vector
    }//End Loop
}
*/
//Ex 6
//Ler dois vetores A e B de 10 elementos inteiros cada
//Imprimir o conjunto intersecção dos elementos desses vetores
//////////////////////Still need implementations ////////////////////////
/*
int main()
{
    //Variables
    int a[10], b[10], intsec[20];
    int i, j, x;

    //Code
    //Loops
    printf("\nConjunto A: \n");
    for (i=0; i<10; i++){
        scanf("%d", &a[i]);     //Vector A
    }
    printf("\nConjunto B: \n");
    for (j=0; j<10; j++){
        scanf("%d", &b[j]);     //Vector B
    }
    printf("\nIntersection: \n");
    for (x=0; x<10; x++){       //Intersection
        if (a[x] == b [x]){
            printf("\n%d", a[x]);
        }
    }


}
*/
//Ex 7
//Ler dois vetores A e B de 7 elementos inteiros cada
//Gerar um conjunto uniao de A e B em C
//Imprimir C
/*
int main()
{
    //Variables
    int a[7], b[7], c[14];
    int i, j, x, k;

    //Code
    //Loop
        printf("\nConjunto A: \n");
    for (i=0; i<7; i++){
        scanf("%d", &a[i]);     //Vector A
    }
    printf("\nConjunto B: \n");
    for (j=0; j<7; j++){
        scanf("%d", &b[j]);     //Vector B
    }
    printf("\nUnion: \n");
    for (x=0; x<7; x++){       //Union
       c[x] = a[x];
    }
    for (x=7; x<14; x++){
        c[x] = b[x];
    }
    for (k=0; k<14; k++){
        printf("\n%d", c[k]);
    }
    printf("\n\n%d", c[7]);
}

*/
//Exercício Aleatório //////// 11/05/2017 ////////
/*
EXERCICIO DE COLOCAR UM VETOR EM ORDEM CRESCENTE
*/
/*
int main()
{

    int x[10];
    int cont, ord, aux;

    for (cont=0; cont<10; cont++) {
        printf("Digite um numero ");
        scanf("%d", &x[cont]);
    }
    //ordenação
    ord = 9;

    while (ord > 0) {
        for (cont = 0; cont < 10; cont++) {
            if (x[cont] > x[cont + 1]) { //TROCAR O SINAL PARA IR DO MENOR PARA O MAIOR
                aux = x[cont];
                x[cont] = x[cont + 1];
                x[cont+1] = aux;
            }
        }
        ord--;
    }
    for (cont = 0; cont < 10; cont++) {
        printf("%d ", x[cont]);
    }
}
*/

int main()
{
    //Variables
    int i, j, k, colunas, altura;

    //Code
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    printf("Digite a altura maxima: ");
    scanf("%d", &altura);

    int vetor[colunas];

    for (i = 0; i < colunas; i++){
        scanf("%d", &vetor[i]);
    }

    for (j = altura; j > 0 ; j--) {

        for (k = 0; k < colunas; k++) {

            if (vetor[k] < j) {
                printf("  ");
            }
            else printf("# ");
        }
        printf("\n");
    }
}





























