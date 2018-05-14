/**
 * @file args.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/05/2018
 * 
 * Program arguments
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;

    return 0;
}
