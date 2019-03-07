/**
 * @file anonym.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 07/03/2019
 *
 * Anonymous struct
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    unsigned id;
    char name[20];
    double price;
} LotR;

int main(int argc, char const *argv[])
{
    LotR.id = 12;
    strcpy(LotR.name, "Lord of the Rings");
    LotR.price = 59.99;

    printf("{ %u, %s, %.2lf }", LotR.id, LotR.name, LotR.price);

    return 0;
}
