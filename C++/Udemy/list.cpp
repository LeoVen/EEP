/**
 * @file list.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 30/07/2018
 * 
 * Working with stl list
 */
#include <iostream>
#include <string>
#include <list>

#define ENTER std::cout << std::endl;

using std::list;
using std::string;

int main(int argc, char const *argv[])
{
	list<int> l1;		 // empty list
	list<int> l2(3, 10); // three integers each with value of 10

	list<int>::iterator it;

	l1.push_back(10);
	l1.push_back(10);
	l1.push_front(20);
	l1.push_back(30);

	std::cout << "\nList 1:" << std::endl;

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nList 2:" << std::endl;

	for (it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nList 1:" << std::endl;

	std::cout << "First element : " << l1.front() << std::endl;
	std::cout << "Last element  : " << l1.back() << std::endl;
	std::cout << "List size     : " << l1.size() << std::endl;

	l1.pop_front();
	l1.pop_back();

	std::cout << "\nList 1 after pop_front() and pop_back() :" << std::endl;

	ENTER;

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nClearing List 2:" << std::endl;

	while (!l2.empty())
	{
		l2.pop_front();
	}

	std::cout << "\nAssign:" << std::endl;

	int vet[] = {1, 2, 3, 4};

	l2.assign(vet, vet + 4);

	for (it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	it = l2.begin();

	it++;
	it++;
	it++;

	std::cout << "\nInsert:" << std::endl;

	l2.insert(it, 99);

	for (it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	it = l2.begin();

	it++;

	std::cout << "\nInserting n times the value a:" << std::endl;

	// Inserting 2 times the number 50 at position of the iterator
	l2.insert(it, 2, 50);

	for (it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nClearing the first two numbers:" << std::endl;

	list<int>::iterator iter = l2.begin();

	iter++;
	iter++;

	l2.erase(l2.begin(), iter);

	for (it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nSplice List 1 and List 2:" << std::endl;

	l1.splice(l1.end(), l2);

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;
	ENTER;

	std::cout << "List 1 size     : " << l1.size() << std::endl;
	std::cout << "List 2 size     : " << l2.size() << std::endl;

	std::cout << "\nRemoving all elements from list of value 10:" << std::endl;

	l1.remove(10);

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nremove_if():" << std::endl;

	l1.remove_if([](const int &n) {
		return n % 2 != 0;
	});

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	ENTER;

	std::cout << "\nsort():" << std::endl;

	l1.sort();

	for (it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << *it << " ";
	}

	list<string> str_list;

	list<string>::iterator str_it;

	str_list.push_back("python");
	str_list.push_back("c++");
	str_list.push_back("java");
	str_list.push_back("haskell");
	str_list.push_back("javascript");

	ENTER;

	std::cout << "\nList of string:" << std::endl;

	for (str_it = str_list.begin(); str_it != str_list.end(); str_it++)
	{
		std::cout << *str_it << " ";
	}

	ENTER;

	std::cout << "\nsort():" << std::endl;

	str_list.sort();

	for (str_it = str_list.begin(); str_it != str_list.end(); str_it++)
	{
		std::cout << *str_it << " ";
	}

	ENTER;

	std::cout << "\nsort() list of strings with predicate:" << std::endl;

	str_list.sort([](const string& s1, const string& s2) {
		if (s1.length() < s2.length())
			return true;
		return false;
	});

	for (str_it = str_list.begin(); str_it != str_list.end(); str_it++)
	{
		std::cout << *str_it << " ";
	}

	ENTER;

	return 0;
}
