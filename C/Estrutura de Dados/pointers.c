#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int x = 10;
	int *ptr = &x;

	ptr++;    // Pointer moves to the next int position (as if it was an array)
	++ptr;    // Pointer moves to the next int position (as if it was an array)
	++*ptr;   // The value of ptr is incremented
	++(*ptr); // The value of ptr is incremented
	++*(ptr); // The value of ptr is incremented
	*ptr++;   // Pointer moves to the next int position (as if it was an array). But returns the old content
	(*ptr)++; // The value of ptr is incremented
	*(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
	*++ptr;   // Pointer moves to the next int position, and then get's accessed, with your code, segfault
	*(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault

	return 0;
}