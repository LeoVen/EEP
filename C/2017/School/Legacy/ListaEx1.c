#include <stdio.h>
#include <stdlib.h>

int main()
{
//3
/*
    float x, f;
    printf("Insira o valor de X para f(x)=sqrt(x) + (x/2) + sqr(x) \n");
        scanf("%f", &x);
    f = sqrt(x) + (x/2) + pow(x, 2);
    printf("f(x) = %.2f",f);
*/

//4
/*
    int x, y;
    printf("Digite X\n");
        scanf("%d", &x);
    printf("Digite Y\n");
        scanf("%d", &y);
    printf("Com resultados invertidos : X=%d e Y=%d", y, x);
    return 0;
*/
//5
/*
float a, b, c, p, A;
    printf("Digite os tres lados de um triangulo \n"); scanf("%f %f %f", &a, &b, &c);

        if((a+b)>c && (a+c)>b && (b+c)>a){
        p = (a + b + c)/2;
        A = sqrt(p*(p-a)*(p-b)*(p-c));
            if (a == b && b == c){
                printf("Triangulo Equilatero de area %f", A);
            return 0;
            }
            else if (a==b || b==c || c==a){
                printf("Triangulo Isosceles de area %f", A);
            return 0;
            }
            else !(a==b || b==c || c==a);{
                printf("Triangulo Escaleno de area %f", A);
            return 0;
            }
        }
        else !((a+b)>c && (a+c)>b && (b+c)>a);{
            printf("Nao e um triangulo");
            return 0;
        }
*/
//6
/*


    int a;
    printf("Digite um número inteiro:");
        scanf("%d", &a);
        if( ( a % 2 == 0) && (a<100) )
            printf("O número é par e menor que 100\n");
        else if( ( a % 2 == 0 ) && ( a >= 100 ) )
            printf("O número é par e maior ou igual a 100\n");
        else if( ( a % 2 != 0) && (a<100) )
            printf("O número é ímpar e menor que 100\n");
        else if (( a % 2 != 0) && (a >= 100))
            printf("O número é ímpar e maior que 100\n");
        else
            return 0;
*/
//7
/*
    float n1, n2, n3;
    printf("Digite tres numeros\n");
        scanf("%f %f %f", &n1, &n2, &n3);
    if (n1 > n2 && n1 > n3){
        if (n2 > n3){
            printf("%.2f %.2f %.2f", n3, n2, n1);
                return 0;
        }
        else (n2 < n3);{
            printf("%.2f %.2f %.2f", n2, n3, n1);
                return 0;
        }
    }
    else if (n2 > n1 && n2 > n3){
        if (n1 > n3){
            printf("%.2f %.2f %.2f", n3, n1, n2);
                return 0;
        }
        else (n1 < n3);{
            printf("%.2f %.2f %.2f", n1, n3, n2);
                return 0;
        }
    }
    else if (n3 > n2 && n3 > n1){
        if (n1 > n2){
            printf("%.2f %.2f %.2f", n2, n1, n3);
                return 0;
        }
        else (n1 < n2);{
            printf("%.2f %.2f %.2f", n1, n2, n3);
                return 0;
        }
    }
*/
//8
/*
    char temp;
    double c, f;
        printf("Digite F para colocar a temperatura em Fahrenheit ou C para Celsius \n");
            scanf("%c", &temp);

        if (temp=='c' || temp=='C'){
            printf("Digite a temperatura em Celsius \n");
                scanf("%lf", &c);
            f = ((9*c)+160)/5;
            printf("A temperatura em Fahrenheit e igual a %.2lf \n", f);
                return 0;
        }
        else if (temp=='f' || temp=='F'){
            printf("Digite a temperatura em Fahrenheit \n");
                scanf("%lf", &f);
            c = (f-32)/1.8;
            printf("A temperatura em Celsius e igual a %.2lf \n", c);
                return 0;
        }
        else printf("Digite um valor valido \n");
*/
//9
/*
    int ano;
    printf("Digite um ano\n");
        scanf("%d", &ano);

    if( ano % 400 == 0){
        printf("O ano %d e bissexto\n", ano);
            return 0;
    }
    else if (( ano % 4 == 0)&&(ano % 100 != 0)){
        printf("O ano %d e bissexto\n", ano);
            return 0;
    }
    else printf("O ano %d nao e bissexto\n", ano);
*/
//10
/*
    int a1, a2, m1, m2, d1, d2;
    printf("Escreva o ano da primeira data: \n");
        scanf("%d", &a1);
    printf("Escreva o mes da primeira data: \n");
        scanf("%d", &m1);
    printf("Escreva o dia da primeira data: \n");
        scanf("%d", &d1);
    printf("\nEscreva o ano da segunda data: \n");
        scanf("%d", &a2);
    printf("Escreva o mes da segunda data: \n");
        scanf("%d", &m2);
    printf("Escreva o dia da segunda data: \n");
        scanf("%d", &d2);

    if( a1 > a2){
        printf("A primeira data e maior");
            return 0;
    }
    else if( a2 > a1){
        printf("A segunda data e maior");
            return 0;
    }
    else if( a1 == a2){

        if( m1 > m2){
            printf("A primeira data e maior");
                return 0;
        }
        else if( m2 > m1){
            printf("A segunda data e maior");
                return 0;
        }
        else if( m1 == m2){

            if( d1 > d2){
                printf("A primeira data e maior");
                    return 0;
            }
            else if( d2 > d1){
                printf("A segunda data e maior");
                    return 0;
            }
            else if( d1 == d2){
                printf("As datas sao iguais");
                    return 0;
            }
        }
    }
*/
//11
/*
    char sexo;
    unsigned int idade, cont;
        printf("Digite M para masculino ou F para feminino \n");
            scanf("%c", &sexo);

        if (!(sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm')) {
            printf("Digite um valor valido");
                return 0;
        }
        else {

        printf("Digite sua idade \n");
            scanf("%u", &idade);
        printf("Digite quantos anos de contribuicao \n");
            scanf("%u", &cont);

        if (sexo == 'M' || sexo == 'm'){

            if (idade >= 65){

                    if (cont >= 10){
                        printf("Aposentavel");
                            return 0;
                    }
                    else {
                        printf("Nao aposentavel");
                            return 0;
                    }

            }
            else if (idade >= 63 && idade < 65){

                if (cont >= 15){
                    printf("Aposentavel");
                        return 0;
                }
                else {
                    printf("Nao aposentavel");
                        return 0;
                }

            }
            else {
                printf("Nao aposentavel \n");
                    return 0;
            }
        }
        else if (sexo == 'F' || sexo == 'f'){

            if (idade >= 63){

                if (cont >= 10){
                    printf("Aposentavel");
                        return 0;
                }
                else {
                    printf("Nao aposentavel");
                        return 0;
                }

            }
            else if (idade >= 61 && idade < 63){

                if (cont >= 15){
                    printf("Aposentavel");
                        return 0;
                }
                else {
                    printf("Nao aposentavel");
                        return 0;
                }

            }
            else {
                printf("Nao aposentavel");
                    return 0;
            }
        }
        }
*/
}


