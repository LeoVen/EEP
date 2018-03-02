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
        Endereço
        Sexo
        Peso
        Altura
        Idade
        Telefone
*/

/*Deve conter as seguintes funções:
        Inclusão
        Alteração
        Pesquisa
        Exclusão
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

//Funções

usuario cadastro();
usuario alterar(int mod);

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Utilizando caracteres da língua portuguesa

    //Declaração de Variáveis
    int choice, op;
    bool exit = false;

    int index = 0; //Index de usuários
    usuario lista[100]; //Lista de usuários

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
        printf("Olá bem vindo ao menu. Escolha o que gostaria de fazer:\n");
        printf("\t1- Cadastrar Usuário\n");
        printf("\t2- Alterar Dados de Usuário\n");
        printf("\t3- Pesquisar Usuários\n");
        printf("\t4- Excluir Usuários\n");
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
            printf("Qual usuário você gostaria de modificar?\n");
            scanf("%d", &op);
            lista[op] = alterar(op);
            printf("\nUsuário alterado com sucesso\n");
            break;
        case 3:
            system("cls");
            printf("Qual usuário você gostaria de pesquisar?\n");
            scanf("%d", &op);
            if (lista[op].ler) //Vendo se o usuário foi excluido ou não
            {
                printf("//////////Usuário//////////\n");
                printf("Nome: %s\n", lista[op].nome);
                printf("Sexo: %c\n", lista[op].sexo);
                printf("Peso: %.2f\n", lista[op].peso);
                printf("Altura: %.2f\n", lista[op].altura);
                printf("Idade: %d\n", lista[op].idade);
                printf("Telefone: %s\n", lista[op].telefone);
                printf("///////////////////////////\n");
            }
            else {
                printf("Esse usuário não existe\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("Qual usuário você gostaria de excluir?\n");
            scanf("%d", &op);
            lista[op].ler = false; //Excluindo o usuário
            printf("Usuário excluido com sucesso\n");
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
            printf("\t\tEscolha um número válido\n\n");
            break;
        } //End Switch
    } //End While



    return 0;
}

usuario cadastro()
{
    //Cadastro de Usuários
    printf("//////////Cadastro de Usuário//////////\n\n");
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
    //Modificação de Usuários
    printf("//////////Modificação de Usuário//////////\n\n");
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


