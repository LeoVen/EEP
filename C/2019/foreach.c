#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR_EACH(type, target, size, body) \
                                           \
    for (size_t i = 0; i < size; i++)      \
    {                                      \
        type value = target[i];            \
        body;                              \
    }

int main(int argc, char const *argv[])
{
    int arr[4] = {0, 1, 2, 3};

    char *name = "My Name";

    FOR_EACH(int, arr, 4, {
        printf("%d\n", value);
    })

    size_t len = strlen(name);

    FOR_EACH(char, name, len, {
        printf("%c-", value);
    })

    return 0;
}
