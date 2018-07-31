/**
 * @file setw.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 30/07/2018
 * 
 * Working with setw
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Person
{
  public:
	string name;
	int age;

	Person(const string &name, const int &age)
	{
		this->name.assign(name);
		this->age = age;
	}
};

int main(int argc, char const *argv[])
{

	Person p1("Alan Turing", 33);
	Person p2("Ada Lovelace", 28);
	Person p3("Niels Bohr", 35);

	cout << setw(20) << "Person's name" << setw(10) << "Age" << endl;
	cout << setw(20) << p1.name << setw(10) << p1.age << endl;
	cout << setw(20) << p2.name << setw(10) << p2.age << endl;
	cout << setw(20) << p3.name << setw(10) << p3.age << endl;

	return 0;
}
