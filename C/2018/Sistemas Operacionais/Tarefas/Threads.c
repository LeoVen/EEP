/*
 * Tarefa 02 - Threads
 * 
 * Leonardo Vencovsky 201710276
 * Matheus Quellis Barros 201710669
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *sum(void *arg)
{
	int *arr = (int *)arg;
	arr[3] = arr[0] * arr[1] * arr[2];
	printf("\nCalculando diagonal %d >> (%d)", arr[4], arr[3]);
	pthread_exit(0);
}

int main(int argc, char const *argv[])
{

	int A11, A12, A13, A21, A22, A23, A31, A32, A33;

	printf("\nA11: ");
	scanf("%d", &A11);

	printf("\nA12: ");
	scanf("%d", &A12);

	printf("\nA13: ");
	scanf("%d", &A13);

	printf("\nA21: ");
	scanf("%d", &A21);

	printf("\nA22: ");
	scanf("%d", &A22);

	printf("\nA23: ");
	scanf("%d", &A23);

	printf("\nA31: ");
	scanf("%d", &A31);

	printf("\nA32: ");
	scanf("%d", &A32);

	printf("\nA33: ");
	scanf("%d", &A33);

	printf("\n|%6d %6d %6d\t|", A11, A12, A13);
	printf("\n|%6d %6d %6d\t|", A21, A22, A23);
	printf("\n|%6d %6d %6d\t|", A31, A22, A33);

	printf("\n");

	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	pthread_t thread_id4;
	pthread_t thread_id5;
	pthread_t thread_id6;

	int Dd1[5] = {A11, A22, A33, 0, 1};
	int Dd2[5] = {A12, A23, A31, 0, 2};
	int Dd3[5] = {A13, A21, A32, 0, 3};

	int De1[5] = {A13, A22, A31, 0, 4};
	int De2[5] = {A11, A23, A32, 0, 5};
	int De3[5] = {A12, A21, A33, 0, 6};

	if (pthread_create(&thread_id1, NULL, sum, Dd1) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_create(&thread_id2, NULL, sum, Dd2) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_create(&thread_id3, NULL, sum, Dd3) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_create(&thread_id4, NULL, sum, De1) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_create(&thread_id5, NULL, sum, De2) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_create(&thread_id6, NULL, sum, De3) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
	pthread_join(thread_id3, NULL);
	pthread_join(thread_id4, NULL);
	pthread_join(thread_id5, NULL);
	pthread_join(thread_id6, NULL);

	int r = Dd1[3] + Dd2[3] + Dd3[3] + (De1[3] * -1) + (De2[3] * -1) + (De3[3] * -1);

	printf("\n\nResultado: %d", r);

	printf("\n");
	return 0;
}