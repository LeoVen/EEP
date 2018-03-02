/////////////////////////////////////////
//  - Leonardo Vencovsky 201710276    ///
//  - Igor Prata 201710277            ///
/////////////////////////////////////////

/*
    /////////    Projeto de Cadastro de Pessoas      /////////
    /////////    Escrevendo e lendo em arquivos      /////////

                    Data de Entrega:
                        Assim que poss�vel

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

/* Deve conter as seguintes fun��es:
        Inclus�o
        Altera��o
        Pesquisa
        Exclus�o
*/
/* Deve ler e escrever a partir de um arquivo
		.txt
		.dat
*/

#include <stdio.h>
#include <stdlib.h> //Para system()
#include <locale.h> //Para setlocale()
#include <stdbool.h> //Para bool
#include <string.h>

typedef struct
{
    bool ler;
    int id;
    char nome[50];
    int idade;
    char sexo;
    float peso;
    float altura;
    char telefone[15];
} usuario;

//FUN��ES

void cadastro();
void alterar();
void pesquisar();
void excluir();
void pesquisarTodos();


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese"); //Utilizando caracteres da l�ngua portuguesa

    //Vari�veis
    int choice;
    bool exit = false;

    while (!exit)
    {
        system("cls");
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
            cadastro();
            break;
        case 2:
            system("cls");
            alterar();
            break;
        case 3:
            system("cls");
            pesquisar();
            break;
        case 4:
            system("cls");
            excluir();
            break;
        case 0:
            system("cls");
            printf("Volte sempre");
            exit = true; //Breaks loop
            break;
        default:
            system("cls");
            printf("N�mero Inv�lido. Tente novamente");
            system("cls");
        } //End Switch
    } //End While

    return 0;
}


void cadastro()
{
    while (1)
    {
        system("cls");
        char correto;
        printf("-Cadastro- Cadastro de usu�rios\n");

        usuario cadastro;
        usuario *ptr;

        ptr = &cadastro;

        cadastro.ler = true;

        FILE *p = fopen("registro.dat", "ab");
        fclose(p);

        /*
        fflush(stdin);
        printf("-Cadastro- ID do usu�rio: ");
        scanf("%d", &cadastro.id);
        if (cadastro.id == 0) break;*/

        //Achando o ID
        int id = 1;
        usuario temp;
        char ch;
        FILE *ponteiro = fopen("registro.dat", "rb");
        if (ponteiro == NULL) {
            printf("Erro ao abrir o arquivo");
            getch();
        }
        ch = fgetc(ponteiro);
        while (ch != EOF)
        {
            fread(&temp, sizeof(usuario), 1, ponteiro);
            id++;
            ch = getc(ponteiro);
        }
        cadastro.id = id;
        fclose(ponteiro);


        fflush(stdin);
        printf("-Cadastro- Nome do usu�rio: ");
        fgets(cadastro.nome, 50, stdin);

        //Removendo /n de cadastro.nome
        size_t ln1 = strlen(cadastro.nome) - 1;
        if (*cadastro.nome && cadastro.nome[ln1] == '\n')
            cadastro.nome[ln1] = '\0';

        fflush(stdin);
        printf("-Cadastro- Idade do usu�rio: ");
        scanf("%d", &cadastro.idade);

        //While para a digita��o de um sexo v�lido
        printf("-Cadastro- Sexo: \n");
        printf("-Cadastro- (m: masculino\tf: feminino\tn: n�o definido)");
        while (1)
        {
            fflush(stdin);
            printf("\n-Cadastro- ");
            cadastro.sexo = getc(stdin);
            if (cadastro.sexo == 'm' || cadastro.sexo == 'f' || cadastro.sexo == 'n')
            {
                break;
            } else printf("-Cadastro- Valor inv�lido. Tente novamente:");
        }


	    fflush(stdin);
	    printf("-Cadastro- Peso: ");
	    scanf("%f", &cadastro.peso);

	    fflush(stdin);
	    printf("-Cadastro- Altura: ");
	    scanf("%f", &cadastro.altura);

	    fflush(stdin);
	    printf("-Cadastro- Telefone: ");
	    fgets(cadastro.telefone, 15, stdin);

        //Removendo /n de cadastro.telefone
        size_t ll = strlen(cadastro.telefone) - 1;
        if (*cadastro.telefone && cadastro.telefone[ll] == '\n')
            cadastro.telefone[ll] = '\0';

        printf("-Cadastro- Os dados est�o corretos? y/n");
        while (1)
        {
            fflush(stdin);
            printf("\n-Cadastro- ");
            correto = getc(stdin);
            if (correto == 'y' || correto == 'n')
            {
                break;
            } else printf("-Cadastro- Valor inv�lido. Tente novamente:");
        }

        if (correto == 'y' || correto == 'Y') {
            printf("-Cadastro- Usu�rio cadastrado com sucesso");
            getch();
        } else {
            int mudar;
            bool sair = false;
            while(1)
            {
                system("cls");
                printf("-Alterar- Qual campo voc� gostaria de alterar?\n");
                printf("-Alterar- (1) Pronto\n");
                printf("-Alterar- (2) Nome : %s\n", cadastro.nome);
                printf("-Alterar- (3) Idade : %d\n", cadastro.idade);
                printf("-Alterar- (4) Sexo : %c\n", cadastro.sexo);
                printf("-Alterar- (5) Peso : %.2f\n", cadastro.peso);
                printf("-Alterar- (6) Altura : %.2f\n", cadastro.altura);
                printf("-Alterar- (7) Telefone : %s\n", cadastro.telefone);
                printf("-Alterar- ");
                scanf("%d", &mudar);

                switch (mudar)
                {
                case 1:
                    sair = true;
                    break;
                case 2:
                    printf("-Alterar- Nome: ");
                    fflush(stdin);
                    fgets(cadastro.nome, 50, stdin);
                    //Removendo /n de cadastro.nome
                    size_t ln1 = strlen(cadastro.nome) - 1;
                    if (*cadastro.nome && cadastro.nome[ln1] == '\n')
                        cadastro.nome[ln1] = '\0';
                    break;
                case 3:
                    printf("-Alterar- Idade: ");
                    fflush(stdin);
                    scanf("%d", &cadastro.idade);
                    break;
                case 4:
                    while (1)
                    {
                        fflush(stdin);
                        printf("-Alterar- Sexo: ");
                        cadastro.sexo = getc(stdin);
                        if (cadastro.sexo == 'm' || cadastro.sexo == 'f' || cadastro.sexo == 'n')
                        {
                            break;
                        } else printf("Valor inv�lido. Tente novamente:\n");
                    }
                    break;
                case 5:
                    printf("-Alterar- Peso: ");
                    fflush(stdin);
                    scanf("%f", &cadastro.peso);
                    break;
                case 6:
                    printf("-Alterar- Altura: ");
                    fflush(stdin);
                    scanf("%f", &cadastro.altura);
                    break;
                case 7:
                    printf("-Alterar- Telefone: ");
                    fflush(stdin);
                    fgets(cadastro.telefone, 15, stdin);
                    //Removendo /n de cadastro.telefone
                    size_t ll = strlen(cadastro.telefone) - 1;
                    if (*cadastro.telefone && cadastro.telefone[ll] == '\n')
                        cadastro.telefone[ll] = '\0';
                    break;
                default:
                    printf("-Alterar- Porfavor insira um n�mero v�lido");
                    break;
                }
                if (sair) break;
            }
        }

        //Escrevendo no arquivo
	    FILE *file = fopen("registro.dat", "ab");
	    if (file == NULL) {
            printf("Erro ao abrir o arquivo");
            getch();
	    }

	    fwrite(ptr, sizeof(usuario), 1, file);

	    fclose(file);
        printf("\n-Cadastro- Deseja cadastrar outro usu�rio? y/n\n");
        char cha;
        fflush(stdin);
        scanf("%c", &cha);

        if (cha == 'n' || cha == 'N') {
            break;
        }
        else if (cha == 'y' || cha == 'Y')
        {
            continue;
        }
        else break;
    }
}


void alterar()
{
    printf("-Alterar- Alterar par�metros de usu�rios\n");
    while (1)
    {
        printf("-Alterar- Digite o ID do usu�rio que voc� gostaria de alterar\n");
    }
    int alterado, excluido;
    char cha;

    FILE *file = fopen("registro.dat", "ab+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        getch();
    }

    //Loop para haver infinitas modifica��es
    while (1)
    {
        printf("-Alterar- Qual ID voc� deseja alterar?\n");
        printf("-Alterar- ");
        scanf("%d", &alterado);

        usuario temp;
        usuario *ptr;
        ptr = &temp;


        //quantos registros existem
        FILE *ponteiro = fopen("registro.dat", "ab+");
        char ch;
        int tamanho_arquivo = 0;
        ch = fgetc(ponteiro);
        while (ch != EOF)
        {
            fread(&temp, sizeof(usuario), 1, ponteiro);
            tamanho_arquivo++;
            ch = getc(ponteiro);
        }
        fclose(ponteiro);

        if (alterado > tamanho_arquivo)
        {
            printf("-Pesquisar- Erro. N�o existe Id com este n�mero. O ultimo registro � de:\n");
            printf("-Pesquisar- %d\n", tamanho_arquivo);
            getch();
            return;
        }


        //Buscando o struct selecionado
        fseek(file, (excluido - 1) * sizeof(usuario), SEEK_SET);
        fread(&temp, sizeof(usuario), 1, file);
        if (temp.ler)
        {
           printf("-Alterar- //////////Usu�rio//////////\n");
            printf("-Alterar- ID: %d\n", temp.id);
            printf("-Alterar- Nome: %s\n", temp.nome);
            printf("-Alterar- Idade: %d\n", temp.idade);
            printf("-Alterar- Sexo: %c\n", temp.sexo);
            printf("-Alterar- Peso: %.2f\n", temp.peso);
            printf("-Alterar- Altura: %.2f\n", temp.altura);
            printf("-Alterar- Telefone: %s\n", temp.telefone);
            printf("-Alterar- ///////////////////////////\n");
        } else {
            printf("-Alterar- Este usu�rio foi exclu�do ...");
            getch();
            break;
        }


        printf("-Alterar- � este usu�rio que voc� deseja alterar? y/n\n");
        printf("-Alterar- ");
        fflush(stdin);
        scanf("%c", &cha);

        if (cha == 'n' || cha == 'N') {
            break;
        }
        else if (cha == 'y' || cha == 'Y')
        {
            FILE *wptr = fopen("registro.dat", "ab+");
            if (wptr == NULL) {
                printf("Erro ao abrir o arquivo");
                getch();
            }
            //Exclui usu�rio
            //fseek(wptr, (excluido - 1) * sizeof(usuario), SEEK_SET);
            rewind(wptr);
            temp.ler = false;
            fseek(wptr, (excluido - 1) * sizeof(usuario), SEEK_SET);
            fwrite(ptr, sizeof(usuario), 1, wptr);
            fclose(wptr);
        }
        else break;

        printf("-Excluir- Voc� deseja excluir outro usu�rio? y/n\n");
        fflush(stdin);
        scanf("%c", &cha);
        if (cha == 'n' || cha == 'N') {
            break;
        } else continue;

    }

}


void pesquisar()
{
    printf("-Pesquisar- Pesquisa de usu�rios\n");
    printf("-Pesquisar- (1) Listar todos os usu�rios\n-Pesquisar- (2) Buscar Usu�rios por ID\n");

    int choice;
    printf("-Pesquisar- ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        pesquisarTodos();
        break;
    case 2:
        system("cls");
        pesquisarUnico();
        break;
    default:
        printf("-Pesquisar- Erro, valor inv�lido ...\n");
        getch();
        break;
    }
}


void pesquisarTodos()
{
    printf("-Pesquisar- Todos os usu�rios cadastrados: \n\n");

    usuario user;
    FILE *file_read = fopen("registro.dat", "rb");
    if (file_read == NULL) {
        printf("Erro ao abrir o arquivo");
        getch();
    }

    while (1)
    {
        fread(&user, sizeof(usuario), 1, file_read);
        if (!feof(file_read)) {
            if (user.ler) {
                printf("-Pesquisar- //////////Usu�rio//////////\n");
                printf("-Pesquisar- ID: %d\n", user.id);
                printf("-Pesquisar- Nome: %s\n", user.nome);
                printf("-Pesquisar- Idade: %d\n", user.idade);
                printf("-Pesquisar- Sexo: %c\n", user.sexo);
                printf("-Pesquisar- Peso: %.2f\n", user.peso);
                printf("-Pesquisar- Altura: %.2f\n", user.altura);
                printf("-Pesquisar- Telefone: %s\n", user.telefone);
                printf("-Pesquisar- ///////////////////////////\n");
            }
            else break;
        }
        else break;

    }
    getch();
    fclose(file_read);
}

void pesquisarUnico()
{
    int pesquisado;
    printf("-Pesquisar- Qual ID voc� deseja pesquisar?\n");
    printf("-Pesquisar- ");
    scanf("%d", &pesquisado);

    FILE *file = fopen("registro.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        getch();
    }


    usuario temp;
    char ch;
    FILE *ponteiro = fopen("registro.dat", "rb");
    if (ponteiro == NULL) {
        printf("Erro ao abrir o arquivo");
        getch();
    }

    //quantos registros existem
    int tamanho_arquivo = 0;
    ch = fgetc(ponteiro);
    while (ch != EOF)
    {
        fread(&temp, sizeof(usuario), 1, ponteiro);
        tamanho_arquivo++;
        ch = getc(ponteiro);
    }
    fclose(ponteiro);

    if (pesquisado > tamanho_arquivo)
    {
        printf("-Pesquisar- Erro. N�o existe Id com este n�mero. O ultimo registro � de:\n");
        printf("-Pesquisar- %d\n", tamanho_arquivo);
        getch();
        return;
    }


    fseek(file, (pesquisado - 1) * sizeof(usuario), SEEK_SET);
    fread(&temp, sizeof(usuario), 1, file);

    if (temp.ler)
    {
        printf("-Pesquisar- //////////Usu�rio//////////\n");
        printf("-Pesquisar- ID: %d\n", temp.id);
        printf("-Pesquisar- Nome: %s\n", temp.nome);
        printf("-Pesquisar- Idade: %d\n", temp.idade);
        printf("-Pesquisar- Sexo: %c\n", temp.sexo);
        printf("-Pesquisar- Peso: %.2f\n", temp.peso);
        printf("-Pesquisar- Altura: %.2f\n", temp.altura);
        printf("-Pesquisar- Telefone: %s\n", temp.telefone);
        printf("-Pesquisar- ///////////////////////////\n");
        getch();
    } else {
        printf("-Pesquisar- Este usu�rio foi exclu�do ou n�o existe ...");
        getch();
    }

    fclose(file);
}

void excluir()
{
    int excluido;
    char cha;

    FILE *file = fopen("registro.dat", "ab+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        getch();
    }

    //Loop para haver infinitas modifica��es
    while (1)
    {
        printf("-Excluir- Qual ID voc� deseja excluir?\n");
        printf("-Excluir- ");
        scanf("%d", &excluido);

        usuario temp;
        usuario *ptr;
        ptr = &temp;


        //quantos registros existem
        FILE *ponteiro = fopen("registro.dat", "ab+");
        char ch;
        int tamanho_arquivo = 0;
        ch = fgetc(ponteiro);
        while (ch != EOF)
        {
            fread(&temp, sizeof(usuario), 1, ponteiro);
            tamanho_arquivo++;
            ch = getc(ponteiro);
        }
        fclose(ponteiro);

        if (excluido > tamanho_arquivo)
        {
            printf("-Pesquisar- Erro. N�o existe Id com este n�mero. O ultimo registro � de:\n");
            printf("-Pesquisar- %d\n", tamanho_arquivo);
            getch();
            return;
        }


        //Buscando o struct selecionado
        fseek(file, (excluido - 1) * sizeof(usuario), SEEK_SET);
        fread(&temp, sizeof(usuario), 1, file);
        if (temp.ler)
        {
           printf("-Excluir- //////////Usu�rio//////////\n");
            printf("-Excluir- ID: %d\n", temp.id);
            printf("-Excluir- Nome: %s\n", temp.nome);
            printf("-Excluir- Idade: %d\n", temp.idade);
            printf("-Excluir- Sexo: %c\n", temp.sexo);
            printf("-Excluir- Peso: %.2f\n", temp.peso);
            printf("-Excluir- Altura: %.2f\n", temp.altura);
            printf("-Excluir- Telefone: %s\n", temp.telefone);
            printf("-Excluir- ///////////////////////////\n");
        } else {
            printf("-Excluir- Este usu�rio j� foi deletado ...");
            getch();
            break;
        }


        printf("-Excluir- � este usu�rio que voc� deseja excluir? y/n\n");
        printf("-Excluir- ");
        fflush(stdin);
        scanf("%c", &cha);

        if (cha == 'n' || cha == 'N') {
            break;
        }
        else if (cha == 'y' || cha == 'Y')
        {
            FILE *wptr = fopen("registro.dat", "ab+");
            if (wptr == NULL) {
                printf("Erro ao abrir o arquivo");
                getch();
            }
            //Exclui usu�rio
            //fseek(wptr, (excluido - 1) * sizeof(usuario), SEEK_SET);
            rewind(wptr);
            temp.ler = false;
            fseek(wptr, (excluido - 1) * sizeof(usuario), SEEK_SET);
            fwrite(ptr, sizeof(usuario), 1, wptr);
            fclose(wptr);
        }
        else break;

        printf("-Excluir- Voc� deseja excluir outro usu�rio? y/n\n");
        fflush(stdin);
        scanf("%c", &cha);
        if (cha == 'n' || cha == 'N') {
            break;
        } else continue;

    }

    fclose(file);
}

