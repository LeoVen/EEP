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
#include <stdbool.h>

// Array size
#define SIZE 20

// Don't change
#define NUMBER_OF_FUNCTIONS 8

// change to "clear" if on linux
#define CLEAR_SCREEN "cls"

/*
+-----------------------------------------+
|           Utility Functions             |
+-----------------------------------------+
*/
void printMenu(); // Prints options
void println(const char *str); // Automatically prints a line
long getValue(); // Gets user's choice
long getPosition(); // Gets array position

bool checkPosition(long v, long pos);
bool checkPositionIsSet(long v, long pos);

void pause();
void error();

void randomFill(long v[]);

/*
+-----------------------------------------+
|             Main Functions              |
+-----------------------------------------+
*/
void push(long v[], long n);
void insert(long v[], long n, long p);
void removee(long v[], long p);           // Avoiding remove() conflict
void update(long v[], long n, long p);
void switchh(long v[], long p1, long p2);  // Avoiding switch() conflict
void init(long v[]);
void printV(long v[], long p, long e);

/*
+-----------------------------------------+
|           Switch() Functions            |
+-----------------------------------------+
*/
void state_1(long v[], bool s); // Init          1
void state_2(long v[]);         // Push          2
void state_3(long v[]);         // Insert        3
void state_4(long v[]);         // Update        4
void state_5(long v[]);         // Switch        5
void state_6(long v[]);         // Remove        6
void state_7(long v[]);         // Print Values  7
void state_8(long v[]);         // Print 1 value 8

long main(long argc, char const *argv[])
{

	long vet[SIZE];
	bool exit = false;
	bool init = false;

	while (!exit) {
		
		printMenu();
		long v = getValue();
		switch (v)
		{
			case 0:
				exit = true;
				break;
			case 1:
				state_1(vet, init);
				init = true;
				break;
			case 2:
				if (init) state_2(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 3:
				if (init) state_3(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 4:
				if (init) state_4(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 5:
				if (init) state_5(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 6:
				if (init) state_6(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 7:
				if (init) state_7(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 8:
				if (init) state_8(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			case 9:
				if (init) randomFill(vet);
				else {
					println("Array has not been initialized.");
					pause();
				}
				break;
			default:
				error();
				break;
		}

	}

	system(CLEAR_SCREEN);
	println(" ");
	println(" +--------------------------+");
	println(" |        Good Bye!         |");
	println(" +--------------------------+");
	println(" ");
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
	println(" Choose an option\n");
	println(" [  0  ] - Exit");
	println(" [  1  ] - Initialize or reset array (with 0's)       (long array[])");
	println(" [  2  ] - Push integer to array                      (long array[], long value)");
	println(" [  3  ] - Insert integer to specific position        (long array[], long position, long value)");
	println(" [  4  ] - Update value of specific position          (long array[], long position, long value)");
	println(" [  5  ] - Switch values between two array positions  (long array[], long position_1, long position_2)");
	println(" [  6  ] - Remove value from array position           (long array[], long position)");
	println(" [  7  ] - Print array values                         (long array[])");
	println(" [  8  ] - Print single array value                   (long array[], long position)");
	println(" [  9  ] - Fill array with random numbers             (long array[], long position)");
}

// String handler
// Needs to be implemented !
long getValue()
{
	long value;

	for ( ; ; )
	{
		printf("\n[Option] >");
		scanf("%ld", &value);

		// + 1 to accept 0 - Exit
		if (value >= 0 && value <= NUMBER_OF_FUNCTIONS + 1) {
			break;
		} else println("\nInvalid value. Try again:");
	}

	return value;
}

void pause()
{
	printf("Press enter to continue...");
	fflush(stdin);
	getchar();
}

void error()
{
	println(" ");
	println(" +--------------------------+");
	println(" |          Error           |");
	println(" +--------------------------+");
	println(" ");
	pause();
}

// Position handler
long getPosition()
{
	long p;
	bool ok = false;

	while (!ok)
	{
		printf("[Position] >");
		scanf("%ld", &p);
		if (p < 0 || p >= SIZE) {
			println("Invalid position. Try again:");
		} else ok = true;
	}

	return p;
}

long getInt()
{
	long val;
	printf("\n[Value] >");
	scanf("%ld", &val);
	return val;
}

bool checkPosition(long v, long pos)
{
	if (v == 0) return true;
	else {
		printf("Position %ld is already taken. Please use update function.\n", pos);
		pause();
		return false;
	}
}

bool checkPositionIsSet(long v, long pos)
{
	if (v != 0) return true;
	else {
		printf("Position %ld has not been initialized. Please use insert function.\n", pos);
		pause();
		return false;
	}
}

/*

+-----------------------------------------+
|             Switch Functions            |
+-----------------------------------------+

*/

void state_1(long v[], bool s)
{
	// Init
	init(v);
	if (!s) {
		println(" ");
		println(" +--------------------------+");
		println(" |     Array Initialized    |");
		println(" +--------------------------+");
		println(" ");
	} else {
		println(" ");
		println(" +--------------------------+");
		println(" |      Array Restarted     |");
		println(" +--------------------------+");
		println(" ");
	}
	pause();
}

void state_2(long v[])
{
	// Push
	long value = getInt();

	push(v, value);
}

void state_3(long v[])
{
	// Insert
	long pos = getPosition();
	
	long val = getInt();

	insert(v, pos, val);
}

void state_4(long v[])
{
	// Update
	long pos = getPosition();

	long val = getInt();

	update(v, pos, val);
}

void state_5(long v[])
{
	// Switch
	long pos1 = getPosition();
	long pos2 = getPosition();

	switchh(v, pos1, pos2);
}

void state_6(long v[])
{
	// Remove
	long pos = getPosition();
	removee(v, pos);
}

void state_7(long v[])
{
	// Prints entire array
	printV(v, 0, SIZE);
}

void state_8(long v[])
{
	long pos = getPosition();
	printV(v, pos, pos + 1);
}

/*

+-----------------------------------------+
|             Main Functions              |
+-----------------------------------------+

*/

void init(long v[])
{
	long i;

	for (i = 0; i < SIZE; i++) {
		v[i] = 0;
	}
}

void push(long v[], long n)
{
	long i = 0;
	long j;
	bool ok = false;

	for (j = 0; j < SIZE; j++) {
		if (v[j] == 0 && j < SIZE) {
			v[j] = n;
			ok = true;
			break;
		} else continue;
	}
	if (!ok) println("\nArray completely filled...\n");
	pause();
}

void insert(long v[], long p, long n)
{
	bool ok = checkPosition(v[p], p);
	if (ok) v[p] = n;
}

void update(long v[], long p,  long n)
{
	bool ok = checkPositionIsSet(v[p], p);
	if (ok) v[p] = n;
}

void removee(long v[], long p)
{
	bool ok = checkPositionIsSet(v[p], p);
	if (ok) v[p] = 0;
}

void switchh(long v[], long p1, long p2)
{
	bool ok1 = checkPositionIsSet(v[p1], p1);
	bool ok2 = checkPositionIsSet(v[p2], p2);

	if (ok1 && ok2) {
		long sup = v[p1];
		v[p1] = v[p2];
		v[p2] = sup;
	}
}

void printV(long v[], long p, long e)
{
	println(" ");
	long i;
	for (i = p; i < e; i++) {
		printf("%ld - ", v[i]);
	}
	println("\n");
	pause();

}

void randomFill(long v[])
{
	long pos;
	for (pos = 0; pos < SIZE; pos++) {
		while (v[pos] == 0) {
			v[pos] = rand() % 10;
		}
	}
	println(" ");
	println(" +--------------------------+");
	println(" |     Array Randomized     |");
	println(" +--------------------------+");
	println(" ");
	pause();
}