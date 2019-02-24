/**
 * @file var_args.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 22/02/2019
 *
 * A function that returns function pointers.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double op_sum(double op1, double op2)
{
	return op1 + op2;
}

double op_sub(double op1, double op2)
{
	return op1 - op2;
}

double op_mul(double op1, double op2)
{
	return op1 * op2;
}

double op_div(double op1, double op2)
{
	return op1 / op2;
}

double op_pow(double op1, double op2)
{
	return pow(op1, op2);
}

double op_mod(double op1, double op2)
{
	return fmod(op1, op2);
}

double (*operator(const char op)) (double, double) {
	switch (op)
	{
		case '+':
			return op_sum;
		case '-':
			return op_sub;
		case '*':
			return op_mul;
		case '/':
			return op_div;
		case '^':
			return op_pow;
		case '%':
			return op_mod;
		default:
			return NULL;
	}
}

typedef double (*oper_t)(double,double);

int main(void)
{
	double a = 12.22, b = 7.9, c = -3.53;

	oper_t op1, op2, op3,  op4, op5, op6;

	op1 = operator('+');
	op2 = operator('-');
	op3 = operator('*');
	op4 = operator('/');
	op5 = operator('^');
	op6 = operator('%');

	printf(" %5.2lf + %5.2lf = %5.2lf\n", a,  c, op1(a, c));
	printf(" %5.2lf - %5.2lf = %5.2lf\n", a,  b, op2(a, b));
	printf(" %5.2lf * %5.2lf = %5.2lf\n", b,  a, op3(b, a));
	printf(" %5.2lf / %5.2lf = %5.2lf\n", c,  b, op4(c, b));
	printf(" %5.2lf ^ %5.2lf = %5.2lf\n", a,  c, op5(a, c));
	printf(" %5.2lf %% %5.2lf = %5.2lf\n", a,  b, op6(a, b));

	return 0;
}