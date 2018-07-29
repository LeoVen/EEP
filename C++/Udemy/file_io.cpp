/**
 * @file file_io.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * Working with fstream
 */
#include <iostream>
#include <fstream>

main(int argc, char const *argv[])
{
	// Read
	std::ifstream in("udemy.txt");

	std::string text;

	char c = in.get();

	text.push_back(c);

	std::cout << "Printing char by char :" << std::endl;

	while (in.good())
	{
		std::cout << c;

		c = in.get();

		text.push_back(c);
	}

	std::cout << "Full String: \n" << text << std::endl;

	// Write
	std::ofstream out("ymedu.txt");

	out << "One ring to rule them all\nOne ring to find them and in the darkness bind them\n";

	return 0;
}
