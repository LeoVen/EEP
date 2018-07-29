/**
 * @file inline.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * Inline functions
 */
#include <iostream>

/*
 * Inline functions are replaced with their body wherever it is being called
 */
inline void foo()
{
	std::cout << "Hello, World!" << std::endl;
}

main(int argc, char const *argv[])
{
	// The line below will be replaced by the function's body
	foo();
	
	return 0;
}
