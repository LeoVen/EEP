/**
 * @file const.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/05/2018
 * 
 * Using const keyword
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int vet[] = {1, 2, 3};
    const int cvet[] = {9, 8, 7};

    // Pode modificar os ponteiros mas não seus interios (para onde o pointeiro aponta)
    const int* p1;

    // Pode modificar os ponteiros mas não seus interios (para onde o pointeiro aponta)
    int const* p2;

    // Um ponteiro constante, não muda para quem aponta. Deve ser inicializado quando declarado
    int* const p3 = vet;

    // Não pode ser feito
    //p3++;

    for (int i = 0; i < 3; i++)
    {
        cout << p3[i] << " ";
    }

    // Porém é possível mudar seu conteúdo
    p3[1] = 5;

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << p3[i] << " ";
    }

    cout << endl;

    // Um ponteiro constante, que aponta para um inteiro constante. Deve ser inicializado quando declarado
    const int* const p4 = cvet;

    // Não pode ser feito
    //p4++;
    //p4[1] = 2;

    for (int i = 0; i < 3; i++)
    {
        cout << p4[i] << " ";
    }

    return 0;
}
