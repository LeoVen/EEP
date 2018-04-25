#include  <stdio.h>
#include  <sys/types.h>

int main(int argc, char const *argv[])
{
	fork();
	fork();
	fork();

	printf("hello\n");
	
	return 0;
}

/*

fork ();   // Line 1
fork ();   // Line 2
fork ();   // Line 3

       L1       // There will be 1 child process created by line 1.
    /     \     
  L2      L2    // There will be 2 child processes created by line 2
 /  \    /  \   
L3  L3  L3  L3  // There will be 4 child processes created by line 3

*/