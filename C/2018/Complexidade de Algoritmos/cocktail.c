/**
 * @file cocktail.c
 *
 * @author Leonardo Vencovsky
 * @author Guilherme Pinazza
 * @author Yan Trevizam
 * 
 * @date 04/10/2018
 *
 * @brief Algoritmo cocktail sort
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//#include <windows.h>

#define SIZE 60
#define MAX 20
#define CLEAR_SCREEN system("cls");

int find_max(int *array, long long arr_size)
{
	int max = array[0];

	for (long long i = 0; i < arr_size; i++)
		if (array[i] > max)	
			max = array[i];

	return max;
}

void print(int *array, long long arr_size, long long current)
{
	int max = find_max(array, arr_size);

	char buff[SIZE + 1];
	for (int i = max; i >= 0; i--)
	{
		for (long long j = 0; j < arr_size; j++)
		{
			if (array[j] >= i)
			{
				if (j == current)
					buff[j] = '~';
				else
					buff[j] = '#';
			}
			else
				buff[j] = ' ';
		}

		buff[SIZE] = '\0';
		printf("%s\n", buff);
	}
}

void cocktail(int *array, long long arr_size)
{
	long long start = 0, end = arr_size - 1;
	int tmp;
	bool swapped = true;

	while (swapped)
	{
		for (long long j = 0; j < end; ++j)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}

			CLEAR_SCREEN;
			print(array, arr_size, j);
		}

		if (!swapped)
			break;

		swapped = false;

		end--;

		for (long long j = end - 1; j >= start; --j)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}

			CLEAR_SCREEN;
			print(array, arr_size, j);
		}

		start++;
	}

	return;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int *arr = malloc(sizeof(int) * SIZE);

	for (long long i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % MAX;
	}

	cocktail(arr, SIZE);

	CLEAR_SCREEN;
	print(arr, SIZE, -1);

	printf("\n");
	for (long long i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}
