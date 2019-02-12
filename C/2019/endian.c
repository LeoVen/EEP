#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool endianess_test()
{
	volatile uint32_t i = 0x01234567;

	return (*((uint8_t*)(&i))) == 0x67;
}

int main(int argc, char const *argv[])
{
	bool endianess = endianess_test();
	
	printf("Computer Endianness: %s\n", endianess ? "Little" : "Big");
	return 0;
}