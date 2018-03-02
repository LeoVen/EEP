#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//AULA DE STRINGS
/*
char name[20] = "Luciana"; // L U C I A N A \0
char frase[100];
gets(frase); //Gets a String // gets();
ou
scanf("%s", frase);

imprimir uma string ///////////////////////////////////////////////////
printf("%s", frase);

imprimir toda a string ///////////////////////////////////////////////////

for (i=0; frase[i]!='\0'; i++) {
    printf("%c", frase[i]);
}

tamanho da string ///////////////////////////////////////////////////

int l;
char s[20];
gets(s);
l=strlen(s);  //String Length // strlen();
printf("%d", l);

concatenação ///////////////////////////////////////////////////

char s1[20];
char s2[30];
gets(s1);
gets(s2);
strcat(s1, s2); //String Concatenation // strcat(); obs: first variable receives second variable; second variable does not change
printf("%s", s1);

comparação ///////////////////////////////////////////////////

char senha[5] = "AULA";
char senha2[5];
gets(senha2);
if (strcmp(senha, senha2) == 0) printf("Logou");  // Compara String // strmp(); -----Retorna um inteiro de quantas letras diferentes ha em cada string
else printf("Erro de login");

Copiar String

char s1 = "Primeiro";
char s2 = "Segundo";
strcpy

manipulando string ///////////////////////////////////////////////////

1-Ler uma frase de até 100 caracteres. Calcular e imprimir quantas vezes aparece a letra 'a'.
2-Ler DDD e fone e guardar em strings distintas. Concatenar as strings e apresentar no formato: (99)9999-9999
3-Ler uma frase e mostrar quantas vezes aparece cada vogal

*/
/*
int main()
{
    //EXERCICIO 1

    //Variables
    char s[100];
    int i, x=0;

    //CODE
    gets(s);

    for (i=0; s[i]!='\0'; i++) {
        if (s[i] == 'a') {
            x++;
        }
    }
    printf("%d", x);
}
*/
/*
int main()
{
    //EXERCICIO 2

    //Variables
    int ddd[3], num1[5], num2[5];

    //CODE
    printf("Digite o DDD: ");
    gets(ddd);
    printf("Digite o numero de telefone: ");
    gets(num1)



}
*/
/*
int main()
{
   //EXERCICIO 3

   //VARIABLES


}
*/


int main()
{

    //TRABALHANDO COM STRCPY(); E STRCAT();
    char s1[20];
    char s2[30];
    char s3[30];
    gets(s1);
    gets(s2);
    gets(s3);
    strcpy(s3, strcat(s1, s2));
    printf("%s", s3);
}



//LISTA DE EXERCICIOS NO MOODLE


