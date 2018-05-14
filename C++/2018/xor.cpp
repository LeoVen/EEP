/**
 * @file xor.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/05/2018
 * 
 * Using XOR to swap integers
 */

#include <iostream>

using namespace std;

void swap_integers(int *t1, int *t2)
{
    *t1 = (*t1) ^ (*t2);
    *t2 = (*t1) ^ (*t2);
    *t1 = (*t1) ^ (*t2);
}

int main(int argc, char const *argv[])
{
    
    double arr[] = {1, 2, 3};

    double *p1 = &arr[0];
    double *p2 = &arr[1];

    int diff = p2 - p1;

    cout << diff << endl;

    int a = 2;
    int b = 3;

    cout << "A: " << a << " B: " << b << endl;

    // Is the same as doing:
    // a, b = b, a
    swap_integers(&a, &b);

    cout << "A: " << a << " B: " << b << endl;

    return 0;
}
