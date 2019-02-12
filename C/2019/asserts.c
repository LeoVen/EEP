#include <stdio.h>
// uncomment to disable assert()
// #define NDEBUG
#include <assert.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double number;

    scanf("%lf", &number);

    // This can't be used as error handling, only as debugging.
    assert(number >= 0.0);

    printf("Square root: %f", sqrt(number));

    return 0;
}
