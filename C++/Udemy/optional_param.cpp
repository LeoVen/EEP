/**
 * @file optional_param.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * Examples of optional parameters
 */
#include <iostream>

// Note that number is an optional parameter with its default value as 0
int sqr(int number = 0)
{
	return number * number;
}

main(int argc, char const *argv[])
{
	
	std::cout << "With parameter    : " << sqr(7) << std::endl;
	std::cout << "Without parameter : " << sqr() << std::endl;

	return 0;
}
