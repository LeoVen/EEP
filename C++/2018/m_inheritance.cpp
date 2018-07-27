/**
 * @file m_inheritance.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/07/2018
 * 
 * Showcase for multiple inheritance in C++
 */
#include <iostream>

class A
{
  public:
	A()
	{
		std::cout << "A's constructor called" << std::endl;
	}
};

class B
{
  public:
	B()
	{
		std::cout << "B's constructor called" << std::endl;
	}
};

class C : public B, public A
{
  public:
	C()
	{
		std::cout << "C's constructor called" << std::endl;
	}
};

int main()
{
	C c;
	return 0;
}