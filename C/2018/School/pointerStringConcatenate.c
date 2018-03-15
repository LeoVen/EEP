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

// Change to "clear" if on linux
#define CLEAR_SCREEN "cls"

char * concatenate(char *s1, char *s2);

int main(int argc, char **argv) {
	
	char *string1 = (char *) calloc (100, sizeof(char));
	char *string2 = (char *) calloc (100, sizeof(char));
	char c = ' ';
	char *scan = NULL;

	fflush(stdin);
	system(CLEAR_SCREEN);
	printf("\nEnter first string [Ctrl + Enter to end] :\n");

	scan = string1;
	while( *scan == 0 )
	{
		fflush(stdin);
		c = getch();
		*scan = c;
		scan++;
		if (c == '\n') {
			break;
		}
		system(CLEAR_SCREEN);
		printf("%s\n", string1);
	}

	*scan = '\0';
	c = ' ';
	system(CLEAR_SCREEN);
	printf("\nEnter second string [Ctrl + Enter to end] :\n");

	scan = string2;
	while ( *scan == 0 )
	{
		fflush(stdin);
		c = getch();
		*scan = c;
		scan++;
		if (c == '\n') {
			break;
		}
		system(CLEAR_SCREEN);
		printf("%s\n", string2);
	}

	c = ' ';

	printf("\nString 1 : %s", string1);
	printf("\nString 2 : %s", string2);
	printf("\n\n+-----------------------------+");
	printf("  \n+                             +");
	printf("  \n+          Concatenate        +");
	printf("  \n+                             +");
	printf("  \n+-----------------------------+\n");

	printf("\n%s", concatenate(string1, string2));

	free(string1);
	free(string2);

	return 0;
}

char * concatenate(char *s1, char *s2)
{
	int s1_size = strlen(s1);
	int s2_size = strlen(s2);

	s1[s1_size-1] = ' ';

	char *returnString = (char *) calloc(s1_size + s2_size, sizeof(char));

	for (int i = 0; i < s1_size; i++) {
		returnString[i] = s1[i];
	}
	for (int i = s1_size; i < s1_size + s2_size; i++) {
		returnString[i-1] = s2[i - s1_size];	
	}
	returnString[s1_size + s2_size] = '\0';

	return returnString;
}