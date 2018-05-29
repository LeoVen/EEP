/**
 * @file times.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/05/2018
 *
 * @brief Using time.h library
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	// structure
	time_t current_time;

	// Gets current time
	time(&current_time);

	// Prints current time
	printf("\n%s", ctime(&current_time));

	// Accessing specific fields (day, month, year, etc)
	// Convert time_t to tm
	struct tm *ct = localtime(&current_time);

	printf("\nMonths are 0 based: %i", ct->tm_mon);

	printf("\n%i/%i/%i %i:%i:%i", ct->tm_mday, ct->tm_mon, ct->tm_year, ct->tm_hour, ct->tm_min, ct->tm_sec);

	printf("\n Fixed:");
	printf("\n%i/%i/%i %i:%i:%i", ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900, ct->tm_hour, ct->tm_min, ct->tm_sec);

	// clock() returns how long the program has been running
	int ticks = clock();
	printf("\n\nExecution time %f", (float)ticks/CLOCKS_PER_SEC);

	return 0;
}