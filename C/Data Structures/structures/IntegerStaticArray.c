/*
	Leonardo Vencovsky
	28/02/2018

	push()   - Insere um inteiro na primeira posição livre
	insert() - Insere um inteiro na posição indicada em um parametro
	remove() - Remove (limpa) uma posição do vetor
	update() - Atualiza um valor de uma posição indicada do vertor
	switch() - Troca uma valor de uma posição pelo valor de outra
	initSSLL()   - Inicializa todas as posições do vetor com um certo valor
	printV() - Listar todos os dados do vetor

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <utility.h>
#include <IntegerStaticArray.h>

long getValue(); // Gets user's choice
long getPosition(); // Gets array position

bool checkPosition(long v, long pos);
bool checkPositionIsSet(long v, long pos);

void randomFill(long v[]);

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

void initArray(int *v, int size)
{
    long i;

    for (i = 0; i < size; i++) {
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


/*
+-----------------------------------------+
|           Utility Functions             |
+-----------------------------------------+
*/

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
