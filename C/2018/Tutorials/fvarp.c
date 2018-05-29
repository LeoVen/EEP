/**
 * @file fvarp.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/05/2018
 *
 * @brief Storing functions in variables and passing as parameters
 *
 */

/*
 * Additional functions as variables
 * 
 * Functions can also be passed as parameter
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct function_wapper_t {
    int    (*sum)   (int, int);
    int    (*mult)  (int, int);
    void   (*print) (int (*func) (int, int), int, int, char*);
} function_wapper_t;

int sum(int a, int b);
int mult(int a, int b);
void print(int (*func) (int, int), int arg1, int arg2, char* message);

void build_wrapper(function_wapper_t **f)
{
    *f = malloc(sizeof(function_wapper_t));

    (*f)->sum = sum;
    (*f)->mult = mult;
    (*f)->print = print;
}

int sum(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

void print(int (*func) (int, int), int arg1, int arg2, char* message)
{
    printf("%s %d", message, func(arg1, arg2));
}

int main(int argc, char const *argv[])
{
    function_wapper_t *f;

    build_wrapper(&f);

    f->print(mult, 6, 3, "\nMultiplying numbers 6 and 3 = ");

    f->print(sum, 6, 3, "\nAdding numbers 6 and 3 = ");

    return 0;
}
