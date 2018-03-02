#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

int main()
{
// Leonardo Vencovsky RA: 201710276

    float ce, ck, a, dk, de;
    printf("Calcular a circunferencia de um planeta com o angulo formado por dois lugares e a distancia entre eles \n");
    printf("Digite a distancia entre os dois lugares em estadios \n"); scanf("%f", &de);
    printf("Digite o angulo formado entre os dois lugares \n"); scanf("%f", &a);
    dk = de*0.1764;
    ck = (dk*360)/a ;
    ce = (de*360)/a;
    printf("%.1f \n %.1f", ce, ck);


    return 0;
}
