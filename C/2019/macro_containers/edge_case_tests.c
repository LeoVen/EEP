#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "macro_containers.h"

CONTAINER_GENERATE(LIST, PUBLIC, l, list, static, int)
CONTAINER_GENERATE(STACK, PUBLIC, s, stack, static, int)
CONTAINER_GENERATE(QUEUE, PUBLIC, q, queue, static, int)
CONTAINER_GENERATE(DEQUE, PUBLIC, d, deque, static, int)

int main(int argc, char const *argv[])
{
	list *l = l_new(100);
	stack *s = s_new(100);
	queue *q = q_new(100);
	deque *d = d_new(100);

	for (int i = 1; i < 101; i++)
	{
		l_push_front(l, i);
		s_push(s, i);
		q_enqueue(q, i);
		d_push_front(d, i);
	}

	int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;

	FOR_EACH(l, list, int, l, {
		sum0 += var;
	})

	FOR_EACH(s, stack, int, s, {
		sum1 += var;
	})

	FOR_EACH(q, queue, int, q, {
		sum2 += var;
	})

	FOR_EACH(d, deque, int, d, {
		sum3 += var;
	})

	printf(" List Sum: %d\n", sum0);
	printf("Stack Sum: %d\n", sum1);
	printf("Queue Sum: %d\n", sum2);
	printf("Deque Sum: %d\n", sum3);

	l_free(l);
	s_free(s);
	q_free(q);
	d_free(d);

	assert(sum0 == 5050);
	assert(sum1 == 5050);
	assert(sum2 == 5050);
	assert(sum3 == 5050);

	l = l_new(100);
	s = s_new(100);
	q = q_new(100);
	d = d_new(100);

	sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;

	FOR_EACH(l, list, int, l, {
		sum0 += var;
	})

	FOR_EACH(s, stack, int, s, {
		sum1 += var;
	})

	FOR_EACH(q, queue, int, q, {
		sum2 += var;
	})

	FOR_EACH(d, deque, int, d, {
		sum3 += var;
	})

	printf(" List Sum: %d\n", sum0);
	printf("Stack Sum: %d\n", sum1);
	printf("Queue Sum: %d\n", sum2);
	printf("Deque Sum: %d\n", sum3);

	l_free(l);
	s_free(s);
	q_free(q);
	d_free(d);

	assert(sum0 == 0);
	assert(sum1 == 0);
	assert(sum2 == 0);
	assert(sum3 == 0);

	return 0;
}
