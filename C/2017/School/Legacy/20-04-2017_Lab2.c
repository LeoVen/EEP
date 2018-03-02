// LEONARDO VENCOVSKY - RA: 201710276

/*
O objetivo do programa � simular uma luta entre dois jogadores do jogo Street Fighter
As entradas consistem de valores positivos inteiros (golpes dados) e valores negativos inteiros (golpes recebidos)
Para se terminar a rodada o pr�ximo numero dever� ser 0 (zero)
Ganha Ryu se tiver uma pontua��o de golpes maior que a pontua��o de golpes recebidos, caso contr�rio perder� o round para Ken
Cada round consiste de numeros positivos e depois de numeros negativos
Um novo round come�a ao inserir novos numeros positivos
Ganha no final quem tiver vencido mais rounds
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, hit, round=0;

    printf("Luta Ryu vs Ken\n");
    system("PAUSE");
    printf("\nFIGHT!\n\n");

        for(i=0; i>-1; i++){

            int total=0;

            do {
                scanf("%d", &hit);
                total = total + hit;
                if (hit == 0){
                    break;
            }
            } while(hit>0);
            do {
                scanf("%d", &hit);
                total = total + hit;
                if (hit == 0){
                    break;
            }
            } while(hit<0);

            if (total>0) round = round + 1;
            else if (total<0) round = round - 1;
            else round = round;

            if (hit == 0) break;

        }

        if(round>0) printf("Ryu venceu");
        else if (round<0) printf("Ken venceu");
        else if (round == 0) printf("empatou");


}
