/**
 * @file vector.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/07/2018
 * 
 * Working with stl vector
 */
#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()

using std::vector;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	std::cout << "Printing vector:" << std::endl;

	vector<int> v0;

	for (int i = 0; i < 10; i++)
		v0.push_back(i);

	int size = v0.size();

	for (int i = 0; i < size; i++)
		std::cout << v0[i] << " ";

	std::cout << "\nEmpty vector:" << std::endl;

	vector<int> v1(3);
	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << " ";

	std::cout << "\nVector iterator:" << std::endl;

	vector<int> v2(rand() % 113);
	for (int i = 0; i < v2.size(); i++)
		v2[i] = rand() % 10;

	vector<int>::iterator it;

	for (it = v2.begin(); it < v2.end(); it++)
		std::cout << *it << " ";

	std::cout << "\nVector reverse iterator:" << std::endl;

	vector<int>::reverse_iterator rit;

	for (rit = v2.rbegin(); rit < v2.rend(); rit++)
		std::cout << *rit << " ";

	std::cout << std::endl;

	while (!v2.empty())
		v2.pop_back();

	if (v2.empty())
		std::cout << "Vector is now empty!" << std::endl;

	vector<int> v3(rand() % 113);

	for (int i = 0; i < v3.size(); i++)
		v3[i] = rand() % 10;

	for (it = v3.begin(); it < v3.end(); it++)
		std::cout << *it << " ";

	v3.clear();

	if (v3.empty())
		std::cout << "\nVector is now empty!" << std::endl;

	unsigned int j;

	// Vector(size, initial_value)
	vector<int> a(2, 10);
	vector<int> b(3, 20);

	std::cout << "\nA:" << std::endl;
	for (j = 0; j < a.size(); j++)
		std::cout << a[j] << " ";

	std::cout << "\nB:" << std::endl;
	for (j = 0; j < b.size(); j++)
		std::cout << b[j] << " ";

	a.swap(b);

	std::cout << "\n\nSWAP" << std::endl;
	
	std::cout << "\nA:" << std::endl;
	for (j = 0; j < a.size(); j++)
		std::cout << a[j] << " ";

	std::cout << "\nB:" << std::endl;
	for (j = 0; j < b.size(); j++)
		std::cout << b[j] << " ";



	return 0;
}
