#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include <math.h>
#include <stdbool.h>

#define PI 3.1415926535897932
#define E 2.7182818284590452
#define PHI 1.6180339887498948

int main(int argc, char const *argv[])
{
	/* This code is made to find the mathematical constants e and pi */

	//Variables
	double e = 0, pi = 1, phi, di;
	int i, j;
	
	//First, e:
	for (i = 0; i <= 70; i++)
	{
		e += 1 / factorial(i);
	}
/*
	//Now pi:
	for (i = 0; i <= 1000000000; i++)
	{
		pi += ( pow(- 1, i) * 4 ) / ( 2 * i + 1 );
	}
*/
	//Now the golden ratio
	phi = ( 1 + sqrt(5) ) / 2;


	for (i = 1; i <= 1000000000; i++)
	{
		di = i;
		pi *= ( 4 * di * di ) / (4 * di * di - 1);
		//pi *= ( ( 2 * i ) / ( (2 * i) - 1 ) ) * ( ( 2 * i ) / ( (2 * i) + 1 ) );
	}
	pi *= 2;


	printf("\nEuler\'s Constant :\t%.16lf", e);
	printf("\nPi Constant: \t\t%.16lf", pi);
	printf("\nThe Golden Ratio : \t%.16lf", phi);

	return 0;
}