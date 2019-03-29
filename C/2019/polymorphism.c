#include <stdio.h>

struct animal
{
    void (*eat)(int);
    char *name;
};

struct dog
{
    struct animal base;
    void (*walk)(int, int);
};

struct cat
{
    struct animal base;
    void (*fall)(double);
};

void who_am_i(struct animal *a)
{
    printf("I'm %s\n", a->name);
}

int main(int argc, char const *argv[])
{
    struct animal A1 = {NULL, "Animal1"};

    struct dog D1 = {{NULL, "Dog1"}, NULL};

    struct cat C1 = {{NULL, "Cat1"}, NULL};

    who_am_i(&A1);
    who_am_i((struct animal *)&D1);
    who_am_i((struct animal *)&C1);

    return 0;
}
