/*
 * pointerStringConcatenate.c
 *
 * Author: Leonardo Vencovsky
 * Created on 13/03/2018
 *
 * Concatenate two string with pointers
 *
 */

// TODO
// Prototype : 
// char * concatenate(char *s1, char *s2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char **argv) {
	
	char *string1 = (char *) calloc (100, sizeof(char));
	char *string2 = (char *) calloc (100, sizeof(char));
	char c = ' ';
	char *scan = NULL;

	fflush(stdin);

	printf("\nEnter first string :");

	scan = string1;
	while( *scan == 0 )
	{
		fflush(stdin);
		c = getchar();
		*scan = c;
		scan++;
		if (c == '\n') {
			break;
		}
		printf("%s\n", string1);
	}
	printf("\ndebug\n");
	*scan = '\0';
printf("\ndebug\n");
	c = ' ';
printf("\ndebug\n");
	printf("\nEnter second string :");

	scan = string2;
	while ( *scan == 0 )
	{
		fflush(stdin);
		c = getchar();
		*scan = c;
		scan++;
		if (c == '\n') {
			break;
		}
	}

	c = ' ';

	printf("\nString 1 : %s", string1);
	printf("\nString 2 : %s", string2);

	free(string1);
	free(string2);

	return 0;
}

char * concatenate(char *s1, char *s2)
{
	char *returnString = NULL;

	int s1_size = strlen(s1);
	int s2_size = strlen(s2);

	return returnString;
}