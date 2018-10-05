/**
 * @file bubble.c
 *
 * @author Leonardo Vencovsky
 * @author Guilherme Pinazza
 * @author Yan Trevizam
 * 
 * @date 04/10/2018
 *
 * @brief Algoritmo bubble sort
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>   // usleep

#define SIZE 60
#define CLEAR_SCREEN system("clear");

int find_max(int *array, size_t arr_size)
{
	int max = array[0];

	for (size_t i = 0; i < arr_size; i++)
		if (array[i] > max)
			max = array[i];

	return max;
}

void print(int *array, size_t arr_size, size_t current)
{
	int max = find_max(array, arr_size);

	for (int i = max; i >= 0; i--)
	{
		for (size_t j = 0; j < arr_size; j++)
		{
			if (array[j] >= i)
			{
				if (j == current)
					printf("~");
				else
					printf("#");
			}
			else
				printf(" ");
		}

		printf("\n");
	}
}

void bubble(int *array, size_t arr_size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < arr_size - 1; i++)
	{

		for (j = 0; j < arr_size - i - 1; j++)
		{

			if (array[j] > array[j + 1])
			{

				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}

			CLEAR_SCREEN;
			print(array, arr_size, j + 1);
			usleep(50000);
			//getch();
		}
	}

	return;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int *arr = malloc(sizeof(int) * SIZE);

	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 20;
	}

	bubble(arr, SIZE);

	CLEAR_SCREEN;
	print(arr, SIZE, -1);

	free(arr);

	return 0;
}