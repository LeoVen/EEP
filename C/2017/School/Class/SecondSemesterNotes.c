#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //Poder usar o pt
#include <math.h>
#include <conio.h>


//Exercicio 1
/*
Ler uma string de at� 100 caracteres. Mostrar o tamanho da string
Obs: Emitir 2 saidas:
    - Com fun��o strlen
    - Manipulando cadeia
*/
/*
int main()
{
    int len, lens;
    char string[100];

    printf("Escreva uma string de ate 100 caracteres:\n");
    gets(string);

    len = 0;
    lens = 0;
    while (string[len] != '\0')
    {
        len++;
        lens++;
        if (string[len] == ' '){
            lens--;
        }

    }

    printf("O tamanho da string por strlen e: %d, e por for loop: %d, e o tamanho sem contar os espacos: %d", strlen(string), len, lens);
}
*/


//Exercicio 2
/*
Nome: 100
Fone: (14) - (19) 99999-9999
Idade: Inteiro
Data Hoje: (10) 99/99/9999
*/
/*
int main()
{
    char nome[101]={'0'};
    char fone[15];
    char idade[4];
    char dn[11];
    char c;
    int i;

    i=0;
    printf("Digite seu nome:");
    do{
       c=_getch() ;
       if (c!=13){
           if ((c>=65 && c<=90) || (c>=97 && c<=122)){
               if (i<=100){
                 nome[i]=c;
                 i++;
                 putchar(c);
               }
           }
           else if(c==32){
            //putchar(32);
            nome[i]=c;
            i++;
           }
           else if(c==8){
            //putchar(8);
            nome[i]=' ';
            i--;
           }
       }
    }while(c!=13);
    printf("\n\n\n%s",nome);
    return 0;
}
*/

///////////////////////////// STRINGS /////////////////////////////

//char cor[] = "azul";
//char *ptr = "azul";
//char cor[] = {'a', 'z', 'u', 'l', '\0'}

//Erros Comuns
//-Alocar espa�o insuficiente
//-Imprimir string que n�o contem caractere '\0'
//-Garantir que a maior string possa ser armazenada

//Leituras:
//scanf("%s", word) -> scanf("%20s", word)//Apenas 20 caracteres ser�o considerados
//scanf("%c", &word)
/* N�O USAR:
void main(void)
{
    char nome[20];

    scanf("%20s", nome);
    printf("%20s", nome);
}
*/
/*  ////////////////////// gets()
void main(void)
{
    char nome[20];

    gets(nome);
    printf("%s", nome);
}
*/
/*  ////////////////////// _getch()
void main(void)
{
    char letra;

    letra = _getch();
    printf("%c", letra);
}
*/
/*  ////////////////////// getchar()
void main(void)
{
    char letra;

    letra = getchar();
    printf("%c", letra);
}
*/
/*  ////////////////////// isdigit()
void main(void)
{
    char letra;

    letra = _getch();

    if (isdigit(letra))
    {
        printf("Voce digitou um numero");
    }
    else
    {
        printf("Voce digitou uma letra ou algum outro caractere");
    }
}
*/

//FUN��ES PREVIAMENTE VISTAS

// * strlen() -> Tamanho da String
// * strcat(s1, s2) -> Concatena��o de Strings. Primeiro par�metro recebe a segunda, cuja essa ultima n�o muda
// * strmp(s1, s2) -> Retorna um inteiro de quantas letras diferentes ha em cada string
// * strcpy(s1, s2) -> Segunda string � copiada na primeira
// * gets() -> Gets a string


//FUN��ES PARA STRINGS

// * isdigit() -> verdadeiro se for um n�mero, caso contr�rio, falso
// * isalnum() -> Verdadeiro se for n�mero ou letra (A ~ Z & a ~ z), caso contr�rio, falso
// * isxdigit() ->Verdadeiro se entrada � um n�mero Hexadecimal, caso contr�rio, falso
// * islower() -> Verdadeiro se as letras est�o em min�scula, caso contr�rio, falso
// * isupper() -> Verdadeiro se as letras est�o em mai�scula, caso contr�rio, falso
// * tolower() -> Converte letras para min�scula
// * toupper() -> Converte letras para mai�scula
// * isspace() -> Verdadeiro se � um espa�o que foi digitado, caso contr�rio, falso
// * iscntrl() -> Verdadeiro se � uma tecla de controle, caso contr�rio, falso
// * ispunct() -> Verdadeiro se for um caractere print�vel al�m de um espa�o, letra ou n�mero; caso contr�rio, falso
// * isprint() -> Verdadeiro se for um caractere print�vel SPACE INCLUSO, caso contr�rio, falso
// * isgraph() -> Verdadeiro se for um caractere print�vel SPACE EXCLUSO, caso contr�rio, falso

//OUTRAS FUN��ES

// * atof() -> Converte para um tipo Float
// * atoi() -> Converte para um tipo Inteiro
// * atol() -> Converte para um tipo Long
// * strtod(str, &local) -> String to Decimal
// * strtol(str, &local, 0) -> String to Long
// * snprintf(str, 50, "%f", x) -> (tipo, tamanho(max), tipo, local) N�mero - Texto

/*
void main(void)
{
    double x = 123456789.987654321;
    char str[50];

    snprintf(str, 50, "%f", x);
    printf("%s", str);
}
*/

/*
i% - Inteiro sem sinal (o sinal n�o importa)

        %i com &var
    Ser� impresso o local na mem�ria que a vari�vel foi alocada

*/
/*
int main()
{
    int i;
    char c;
    int a;
    int b;
    int x;
    struct {
        int x;
        int y;
    }ponto;

    int v[4];
    printf("%i\n", &c);
    printf("%i\n", &a);
    printf("%i\n", &ponto);
    printf("%i\n", &v[0]);
    printf("%i\n", &v[1]);
    printf("%i\n", &v[2]);
    printf("%i\n", &v[3]);
    printf("%i\n", &x);

    return 0;
}
*/

/*

///////////////////////////// Ponteiros /////////////////////////////

Apontam para um espa�o da mem�ria
Se *ponteiro = x;
A vari�vel a qual o ponteiro aponta receber� o valor de x
*/
/*
int main()
{
    int *p;
    int a = 3;
    p = &a;
    *p = 10;
    printf("%d\n\n", *p);

    printf("%i\n%i", &a, &p);
    return 0;
}
*/


///////////////////////////// Registros e Structs /////////////////////////////
/*
Um registro (record) � um pacote de vari�veis, possivelmente de tipos diferentes.
Cada vari�vel � um campo do registro. Em C s�o conhecidas como Structs

////// Defini��o e Manipula��o
*/
/*
void main()
{
    struct
    {
        int dia;
        int mes;
        int ano;
    };
    //Dica : � uma boa ideia dar um nome � classe dos registros:
    struct dma
    {
        int dia;
        int mes;
        int ano;
    };
    struct dma x;
    //Acesso ao campo:
    x.dia = 26;
    x.mes = 8;
    x.ano = 2017;
}
*/
////// Registros como novos tipos de dados:
/*
        typedef struct dma data;
        data x, y;
*/
// Ex :
/*
struct dma
{
    int dia, mes, ano;
}x;

typedef struct dma data;

void main()
{
    data a;

    scanf("%d %d %d", &a.dia, &a.mes, &a.ano);

    printf("Dia: %d\n", a.dia);
    printf("Mes: %d\n", a.mes);
    printf("Ano: %d\n", a.ano);
    printf("\n\n%d / %d / %d", a.dia, a.mes, a.ano);
}
*/

//Exerc�cio
/*
    1- Criar uma estrutura para cadastro de clientes:
        - RG
        - CPF
        - Nome
        - Fone
        - Idade
        - Sexo


    2- Implementar um programa para:
        - Gravar dados
        - Ler dados
*/

// Ex 1 :
/*
struct cadastro
{
    int rg, cpf, fone, idade;
    char nome[50], sexo;
};

typedef struct cadastro cliente; //Novo tipo de vari�vel cliente, que tem a estrutura cl

void main()
{
    int i, n;
    printf("Quantos clientes voce deseja cadastrar?\n");
    scanf("%d", &n);

    cliente ficha[n]; //Vetor de 5 posi��es onde cada posi��o � do tipo data (definido logo acima)

    printf("Cadastro de %d Clientes", n);

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\n\n");
        printf("//////Cliente %d//////\n", i + 1);

        printf("Nome: ");
        gets(ficha[i].nome);
        //scanf("%s", ficha[i].nome);

        printf("Sexo: ");
        scanf("%c", &ficha[i].sexo);

        printf("Idade: ");
        scanf("%d", &ficha[i].idade);

        printf("Telefone: ");
        scanf("%d", &ficha[i].fone);

        printf("RG: ");
        scanf("%d", &ficha[i].rg);

        printf("CPF: ");
        scanf("%d", &ficha[i].cpf);
    }

    printf("%s", ficha[0].nome);

}
*/
/*
int main()
{
    int k;
    int *p;
    p = calloc(3000000, sizeof(int *));
    //p = malloc(3000000 * sizeof(int *));

    for (k=0;k<3000000;k++)
    {
        p[k] = k;
    }

    return k;
}
*/
/*
int main()
{
    int a=5, *b, **c;

    b = &a;
    c = &b;

    printf("%d\n", a);
    printf("%d\n", *b);
    printf("%d\n", **c);

    return **c;
}
*/

//      ARQUIVOS        //
/*
Os arquivos permitem gravar os dados de um programa de forma permanente em m�dia digital

O tipo FILE est� definido na stdio.h

FILE *ponteiro; //ponteiro que aponta para um arquivo

*/
//Variaveis __DATE__ e __TIME__ s�o %s

int main()
{

    FILE *ptr;
    FILE *ptr_read;
    char palavra[20];
    int idade;
    char c;

    printf("Digite 0 para sair\n\n");



    while (sizeof(int)==4)
    {
        ptr = fopen("arquivo.txt", "a"); //File open

        if (ptr == NULL)
        {
            printf("Error, file could not be opened");
            return 1;
        }

        printf("\n\nDigite sua idade: \n");
        scanf("%d", &idade);
        fflush(stdin);
        if (idade == 0)
        {
            fclose(ptr);
            break;
        }
        printf("Escreva seu nome: \n");
        gets(palavra);
        fflush(stdin);


        fprintf(ptr, "%s\t\t%d\tData: %s\tHora: %s\n", palavra, idade, __DATE__, __TIME__); //Writes in file

        fclose(ptr); //File close
    }



    ptr_read = fopen("arquivo.txt", "r"); //Leitura apenas de arquivo

    if (ptr_read == NULL)
    {
        printf("Error, file could not be opened");
        return 1;
    }

    //Fazer leitura do arquivo
    do
    {
        c = getc(ptr);

        printf("%c", c);
    } while(c != EOF);

    fclose(ptr_read); //File close

    system("start arquivo.txt"); //Abrir arquivo qualquer

    return 0;
}












