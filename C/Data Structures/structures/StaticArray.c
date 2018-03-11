/*
	Leonardo Vencovsky
	28/02/2018

	push()   - Insere um inteiro na primeira posição livre
	insert() - Insere um inteiro na posição indicada em um parametro
	remove() - Remove (limpa) uma posição do vetor
	update() - Atualiza um valor de uma posição indicada do vertor
	switch() - Troca uma valor de uma posição pelo valor de outra
	init()   - Inicializa todas as posições do vetor com um certo valor
	printV() - Listar todos os dados do vetor

    +-----------------------------------------+
    |               Static Array              |
    +-----------------------------------------+

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <utility.h>
#include <StaticArray.h>

void randomFill(long *v, int size);

/*
+-----------------------------------------+
|             Main Functions              |
+-----------------------------------------+
*/


int * getArray(int size)
{
    int *p = malloc ( ( size + 0 ) * sizeof(int));

    int *arr = p;

    for (int i = 0; i < size; i++)
    {
        *p = 0;
        p++;
    }
    return arr;
}

int initArray(int *array, int size)
{
    long i;

    for (i = 0; i < size; i++) {
        array[i] = 0;
    }

    return 200;
}

int insertValueArray(int *array, int size, int position, int value)
{
    if (position < 0 || position >= size) return 7; // Invalid position
    else {
        array += position;
        if (*array == 0) {
            // Position not taken
            *array = value;
            return 210; // Value inserted
        } else return 102; // Position already taken
    }
}

int pushValueArray(int *array, int size, int value)
{
    long j;
    bool ok = false;

    for (j = 0; j < size; j++) {
        if (*array == 0) {
            *array = value;
            ok = true;
            break;
        } else array++;
    }
    if (!ok) return 201; // Array completely filled
    return 211;
}

int printArray(int *array, int size)
{
    int i;
    println("\nSTATIC ARRRAY\n");
    for (i = 0; i < size; i++) {
        printf("%d ", *array);
        array++;
    }
    println(" ");
    return 0;
}

int updateArray(int *array, int size, int position, int value)
{
    if (position < 0 || position >= size) return 7; // Invalid position
    else {
        array += position;
        *array = value;
        return 103;
    }
}

/*


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



void randomFill(long *v, int size)
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

*/
/*
+-----------------------------------------+
|           Utility Functions             |
+-----------------------------------------+
*/

// String handler
// Needs to be implemented !
/*
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



bool checkPositionIsSet(long v, long pos)
{
    if (v != 0) return true;
    else {
        printf("Position %ld has not been initialized. Please use insert function.\n", pos);
        pause();
        return false;
    }
}
*/