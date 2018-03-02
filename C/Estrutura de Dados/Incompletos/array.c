/*
	Leonardo Vencovsky
	28/02/2018
	Aula: Estrutura de Dados
	EEP
	
	Implementação de um array estático de inteiros com funções básicas
	Compiled with MinGW
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

// Array size
#define SIZE 20
#define NUMBER_OF_FUNCTIONS 3

// change to "clear" if on linux
#define CLEAR_SCREEN "cls"


void printMenu();
void println(const char *str);
int getValue();
int getPosition();

void init(int v[]);
void insert(int v[], int n, int l);
void push(int v[], int n);


int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	int vet[SIZE];
	bool exit = false;

	while (!exit) {
		
		printMenu();
		int v = getValue();
		switch (v)
		{
			case 0:
				exit = true;
				break;
			case 1:
				init(vet);
				println("Array initialized");
				break;
			case 2:
				break;
			case 3:
				println("Value :");
				printf(">");
				int val;
				scanf("%d", &val);
				int pos = getPosition();
				insert(vet, val, pos);
				break;
		}

	}

	system(CLEAR_SCREEN);
	println(" +--------------------------+");
	println(" |        Good Bye!         |");
	println(" +--------------------------+");
	system("pause");
	system(CLEAR_SCREEN);

	return 0;
}

void println(const char *str)
{
	printf("%s\n", str);
}

void printMenu()
{
	system(CLEAR_SCREEN);
	println(" +--------------------------+");
	println(" | Static Array of Integers |");
	println(" +--------------------------+\n");
	println(" [] Choose an option []\n");
	println("0 - Exit");
	println("1 - Initialize array");
	println("2 - Push integer to array");
	println("3 - Insert integer to specific location");
}

int getValue()
{
	int value = 0;

	for ( ; ; )
	{
		printf("\n>");
		scanf("%d", &value);

		if (value >= 0 && value <= NUMBER_OF_FUNCTIONS) {
			break;
		} else println("Valor inválido. Tente novamente.");
	}

	return value;
}

void init(int v[])
{
	int i;

	for (i = 0; i < SIZE; i++) {
		v[i] = 0;
	}
}

void push(int v[], int n)
{
	int i = 0;
	int j;

	for (j = 0; j < SIZE; j++) {
		if (v[j] != 0 && j < SIZE) {
			v[j] = n;
			break;
		}
	}

}

void insert(int v[], int n, int p)
{
	v[p] = n; 
}

int getPosition()
{
	int p;
	bool ok = false;

	println("Position:");
	while (!ok)
	{
		printf(">");
		scanf("%d", &p);
		if (p < 0 || p >= SIZE) {
			println("Invalid position. Try again:");
		} else ok = true;
	}

	return p;
}