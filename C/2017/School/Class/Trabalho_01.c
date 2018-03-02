/////////////////////////////////////////
//  - Leonardo Vencovsky 201710276    ///
//  - Igor Prata 201710277            ///
/////////////////////////////////////////

/*
    /////////    Projeto de Cadastro de Pessoas      /////////

                    Data de Entrega:
                        16/09/2017

    //////////////////////////////////////////////////////////

*/

/* Deve conter:
        Nome
        Endere�o
        Sexo
        Peso
        Altura
        Idade
        Telefone
*/

/*Deve conter as seguintes fun��es:
        Inclus�o
        Altera��o
        Pesquisa
        Exclus�o
*/

#include <stdio.h>
#include <stdlib.h> //Para system()
#include <locale.h> //Para setlocale()
#include <stdbool.h> //Para bool

typedef struct
{
    bool ler;
    char nome[50];
    char sexo;
    float peso;
    float altura;
    int idade;
    char telefone[15];

}usuario;

//Fun��es

usuario cadastro();
usuario alterar(int mod);

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Utilizando caracteres da l�ngua portuguesa

    //Declara��o de Vari�veis
    int choice, op;
    bool exit = false;

    int index = 0; //Index de usu�rios
    usuario lista[100]; //Lista de usu�rios

            /*
            printf("%s\n", lista[0].nome);
            printf("%c\n", lista[0].sexo);
            printf("%.2f\n", lista[0].peso);
            printf("%.2f\n", lista[0].altura);
            printf("%d\n", lista[0].idade);
            printf("%s\n", lista[0].telefone);
            */
    //Menu
    while (!exit)
    {
        printf("Ol� bem vindo ao menu. Escolha o que gostaria de fazer:\n");
        printf("\t1- Cadastrar Usu�rio\n");
        printf("\t2- Alterar Dados de Usu�rio\n");
        printf("\t3- Pesquisar Usu�rios\n");
        printf("\t4- Excluir Usu�rios\n");
        printf("\t0- Sair\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            lista[index] = cadastro();
            index += 1;
            break;
        case 2:
            system("cls");
            printf("Qual usu�rio voc� gostaria de modificar?\n");
            scanf("%d", &op);
            lista[op] = alterar(op);
            printf("\nUsu�rio alterado com sucesso\n");
            break;
        case 3:
            system("cls");
            printf("Qual usu�rio voc� gostaria de pesquisar?\n");
            scanf("%d", &op);
            if (lista[op].ler) //Vendo se o usu�rio foi excluido ou n�o
            {
                printf("//////////Usu�rio//////////\n");
                printf("Nome: %s\n", lista[op].nome);
                printf("Sexo: %c\n", lista[op].sexo);
                printf("Peso: %.2f\n", lista[op].peso);
                printf("Altura: %.2f\n", lista[op].altura);
                printf("Idade: %d\n", lista[op].idade);
                printf("Telefone: %s\n", lista[op].telefone);
                printf("///////////////////////////\n");
            }
            else {
                printf("Esse usu�rio n�o existe\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("Qual usu�rio voc� gostaria de excluir?\n");
            scanf("%d", &op);
            lista[op].ler = false; //Excluindo o usu�rio
            printf("Usu�rio excluido com sucesso\n");
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            printf("Volte Sempre\n");
            exit = true; //Breaks loop
            break;
        default:
            system("cls");
            printf("\t\tEscolha um n�mero v�lido\n\n");
            break;
        } //End Switch
    } //End While



    return 0;
}

usuario cadastro()
{
    //Cadastro de Usu�rios
    printf("//////////Cadastro de Usu�rio//////////\n\n");
    fflush(stdin);

    usuario user; //Variavel de retorno

    user.ler = true;

    printf("Nome: ");
    gets(user.nome);
    fflush(stdin);

    printf("Sexo: ");
    scanf("%c", &user.sexo);
    fflush(stdin);

    printf("Idade: ");
    scanf("%d", &user.idade);
    fflush(stdin);

    printf("Altura: ");
    scanf("%f", &user.altura);
    fflush(stdin);

    printf("Peso: ");
    scanf("%f", &user.peso);
    fflush(stdin);

    printf("Telefone: ");
    gets(user.telefone);

    printf("\n");
    printf("//////////Seu cadastro foi um sucesso!//////////\n\n\n");
    system("pause");
    system("cls");

    return user;
}

usuario alterar(int mod)
{
    //Modifica��o de Usu�rios
    printf("//////////Modifica��o de Usu�rio//////////\n\n");
    fflush(stdin);

    usuario user; //Variavel de retorno

    user.ler = true;

    printf("Nome: ");
    gets(user.nome);
    fflush(stdin);

    printf("Sexo: ");
    scanf("%c", &user.sexo);
    fflush(stdin);

    printf("Idade: ");
    scanf("%d", &user.idade);
    fflush(stdin);

    printf("Altura: ");
    scanf("%f", &user.altura);
    fflush(stdin);

    printf("Peso: ");
    scanf("%f", &user.peso);
    fflush(stdin);

    printf("Telefone: ");
    gets(user.telefone);

    printf("\n");
    system("pause");
    system("cls");

    return user;
}


