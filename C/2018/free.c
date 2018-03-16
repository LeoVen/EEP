#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Wokring");
	char* string = "Hello World!";
	char** refStr = &string;
	free(refStr);
	free(NULL);
}