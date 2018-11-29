#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

typedef long long int integer;

// Greates common divisor of numbers a and b
integer gcd(integer a, integer b)
{
	if (a == 0 || b == 0)
		return 0;

	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);  

	return gcd(a, b - a);
}

// Least commom multiple of numbers a and b
integer lcm(integer a, integer b)
{
	// Division by zero is no fun...
	if (a == 0 || b == 0)
		return 0;

	return (a * b) / gcd(a, b);
}

int main(int argc, char const *argv[])
{
	printf("\nGCD( 12,  6) = %"PRId64"", gcd(12, 6));
	printf("\nGCD( 50, 63) = %"PRId64"", gcd(50, 63));
	printf("\nLCM( 13,  6) = %"PRId64"", lcm(13, 6));
	printf("\nLCM( 20, 42) = %"PRId64"", lcm(20, 42));
	
	return 0;
}
