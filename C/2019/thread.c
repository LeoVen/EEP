#include <stdio.h>

int main(int argc, char const *argv[])
{
#ifdef __STDC_NO_THREADS__
    printf("No threads :(\n");
#else
    printf("Yay! Threads!\n");
#endif

    return 0;
}
