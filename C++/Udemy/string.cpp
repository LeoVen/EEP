/**
 * @file string.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * String examples
 */
#include <iostream>
#include <string>

using std::string;

main(int argc, char const *argv[])
{
	size_t s;

	string str = "Jon Snow";

	std::cout << "String      : " << str << std::endl;
	std::cout << "Size        : " << str.size() << std::endl;
	std::cout << "at(4)       : " << str.at(4) << std::endl;
	std::cout << "back()      : " << str.back() << std::endl;
	std::cout << "front()     : " << str.front() << std::endl;

	str.append(" Targarye");

	std::cout << "append()    : " << str << std::endl;

	str.push_back('n');

	std::cout << "push_back() : " << str << std::endl;

	str.insert(str.size(), " Lollypop");

	std::cout << "insert()    : " << str << std::endl;

	str.erase(4, str.size());

	std::cout << "erase()     : " << str << std::endl;

	if (!str.empty())
		std::cout << "!empty()    : " << str << std::endl;

	str.clear();

	if (!str.empty())
		std::cout << "clear()    : " << str << std::endl;
	else
		std::cout << "str is empty" << std::endl;

	str.append("Sherlock Holmes");

	std::cout << "new string  : " << str << std::endl;

	// [int, )
	str.replace(9, str.size(), "Watson");

	std::cout << "replace()   : " << str << std::endl;

	string my_str;

	std::cout << "Write a substring:";

	getline(std::cin, my_str);

	s = str.find(my_str);

	if (s != string::npos)
		std::cout << "Substring " << my_str << " found!" << std::endl;
	else
		std::cout << "Substring " << my_str << " not found!" << std::endl;

	return 0;
}