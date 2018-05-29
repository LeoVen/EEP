/**
 * @file fvar.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/05/2018
 *
 * @brief Storing functions in variables
 *
 */

/*
 * Function as a variable has the following declaration:
 *
 * return_type (*function_var_name) (param1_type, param2_type,..., paramN_type);
 * 
 * Example:
 * 
 * int (*var_caesar_cipher) (char*, char**, int);
 * 
 * A variable function that is called var_caesar_cipher that returns
 * 'int' and receives three parameters: 'char *', 'char **', and 'int'.
 * To assign it to the caesar_cipher function simply do:
 * 
 * var_caesar_cipher = caesar_cipher;
 * 
 * var_function = function_name;
 * 
 * Note that the variable must be a pointer since it points to a function
 * 
 */

#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <math.h>   // sqrt

typedef struct Vector {
    int x;
    int y;
    int z;
    unsigned mod;
    void (*vec_mod) (struct Vector*);
} Vector;

typedef struct printer_t {
    int (*print_int) (int);
    int (*print_doub) (double);
    int (*print_vec) (Vector*);
} printer_t;

void vec_modulus(Vector *v);
void vec_build(Vector **v);

void printer_build(printer_t **p);

int print_integer(int x);
int print_double(double x);
int print_vector(Vector *v);

void vec_build(Vector **v)
{
    *v = malloc(sizeof(Vector));
    (*v)->x = 0;
    (*v)->y = 0;
    (*v)->z = 0;
    (*v)->mod = 0;
    (*v)->vec_mod = vec_modulus;
}

void vec_modulus(Vector *v)
{
    v->mod = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void printer_build(printer_t **p)
{
    *p = malloc(sizeof(printer_t));

    (*p)->print_int = print_integer;
    (*p)->print_doub = print_double;
    (*p)->print_vec = print_vector;
}

int print_integer(int x)
{
    printf("\n%d", x);

    return 100;
}

int print_double(double x)
{
    printf("\n%lf", x);

    return 200;
}

int print_vector(Vector *v)
{
    printf("\n(%d, %d, %d)", v->x, v->y, v->z);

    return 300;
}

int main(int argc, char const *argv[])
{
    Vector *v;

    vec_build(&v);

    v->x = 2;
    v->y = -1;
    v->z = 3;

    v->vec_mod(v);

    printf("\nVector modulus: %u", v->mod);

    printer_t *p;

    printer_build(&p);

    p->print_vec(v);

    return 0;
}
