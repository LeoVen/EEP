/**
 * @file smart_ptr.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 01/10/2018
 * 
 * Smart pointers in C++
 */

#include <iostream>
#include <stdio.h>
#include <memory>

struct my_struct
{
	int x = 100;
	int y = 200;
};

int main(int argc, char const *argv[])
{
	// Shared pointer
	std::shared_ptr<struct my_struct> ptr0 = std::make_shared<struct my_struct>();

	// More than one pointer can be pointing to the same object
	std::shared_ptr<struct my_struct> ptr1 = ptr0;

	printf("\nptr0: %p \t ptr1: %p", &(*ptr0), &(*ptr1));

	// Unique pointer
	std::unique_ptr<struct my_struct> ptr2 = std::make_unique<struct my_struct>();
	
	// Only one pointer can be pointing to the same object so we need to transfer ownership
	std::unique_ptr<struct my_struct> ptr3 = std::move(ptr2);

	printf("\nptr2: %p \t ptr3: %p", &(*ptr2), &(*ptr3));

	return 0;
}
