/*
	Leonardo Vencovsky
	28/02/2018
	Aula: Estrutura de Dados
	EEP
	
	Implementação de um array estático de inteiros com funções básicas
	Compiled with MinGW

	push()   - Insere um inteiro na primeira posição livre
	insert() - Insere um inteiro na posição indicada em um parametro
	remove() - Remove (limpa) uma posição do vetor
	update() - Atualiza um valor de uma posição indicada do vertor
	switch() - Troca uma valor de uma posição pelo valor de outra
	init()   - Inicializa todas as posições do vetor com um certo valor
	printV() - Listar todos os dados do vetor

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

// Array size
#define SIZE 20
#define NUMBER_OF_FUNCTIONS 8

// change to "clear" if on linux
#define CLEAR_SCREEN "cls"

// Utility functions
void printMenu(); // Prints options
void println(const char *str); // Automatically prints a line
int getValue(); // Gets user's choice
int getPosition(); // Gets array position

void pause();
void error();

// Main functions
void push(int v[], int n);
void insert(int v[], int n, int l);
void init(int v[]);
void printV(int v[], int l);

// Switch() functions
void state_1(int v[]); // Init          1
void state_2(int v[]); // Push          2
void state_3(int v[]); // Insert        3
void state_4(int v[]); // Update        4
void state_5(int v[]); // Switch        5
void state_6(int v[]); // Remove        6
void state_7(int v[]); // Print Values  7
void state_8(int v[]); // Print 1 value 8

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
				state_1(vet);
				break;
			case 2:
				state_2(vet);
				break;
			case 3:
				state_3(vet);
				break;
			case 4:
				state_4(vet);
				break;
			case 5:
				state_5(vet);
				break;
			case 6:
				state_6(vet);
				break;
			case 7:
				state_7(vet);
				break;
			case 8:
				state_8(vet);
				break;
			default:
				error();
				break;
		}

	}

	system(CLEAR_SCREEN);
	println(" +--------------------------+");
	println(" |        Good Bye!         |");
	println(" +--------------------------+");
	pause();
	system(CLEAR_SCREEN);

	return 0;
}

/*

+-----------------------------------------+
|           Utility Functions             |
+-----------------------------------------+

*/

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
	println("1 - Initialize array (with 0's)                []");
	println("2 - Push integer to array                      [int integer]");
	println("3 - Insert integer to specific position        [int position, int value]");
	println("4 - Update value of specific position          []");
	println("5 - Switch values between two array positions  []");
	println("6 - Remove value from array position           []");
	println("7 - Print array values                         []");
	println("8 - Print single array value                   [int position]");
}

// String handler
int getValue()
{
	int value = 0; // MUST CHANGE TO LONG
	char c;

	int i;
	char s[NUMBER_OF_FUNCTIONS];
	for (i = 48; i <= NUMBER_OF_FUNCTIONS + 48; i++) {
		s[i - 48] = i;
	}

	for (i = 0; i <= NUMBER_OF_FUNCTIONS; i++) {
		printf("%c", s[i]);
	}

	for ( ; ; )
	{
		printf("\n>");
		scanf("%d", value);
		value += 48;
		// value = atol(c);
		if (value >= 48 && value <= NUMBER_OF_FUNCTIONS + 48) {
			break;
		} else println("Valor invalido. Tente novamente.");
	}

	return value;
}

void pause()
{
	fflush(stdin);
	getchar();
}

void error()
{
	println(" +--------------------------+");
	println(" |          Error           |");
	println(" +--------------------------+");
	pause();
}

// Position handler
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

/*

+-----------------------------------------+
|             Switch Functions            |
+-----------------------------------------+

*/

void state_1(int v[])
{
	// Init
	init(v);
	println(" +--------------------------+");
	println(" |     Array Initialized    |");
	println(" +--------------------------+");
	pause();
}

void state_2(int v[])
{
	// Push

}

void state_3(int v[])
{
	// Insert
	println("Value :");
	printf(">");
	int val;
	scanf("%d", &val);
	int pos = getPosition();
	insert(v, val, pos);
	
}

void state_4(int v[])
{
	
}

void state_5(int v[])
{
	
}

void state_6(int v[])
{
	
}

void state_7(int v[])
{
	// Prints entire array
	printV(v, SIZE);

}

void state_8(int v[])
{

}

/*

+-----------------------------------------+
|             Main Functions              |
+-----------------------------------------+

*/

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

void printV(int v[], int l)
{

	int i;
	for (i = 0; i < l; i++) {
		printf("%d - ", v[i]);
	}

}