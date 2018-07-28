/**
 * @file oper_overload.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * Examples of Operator Overloading
 */
#include <iostream>
#include <string>

class Complex
{
  public:
	int real, imag;

	Complex(int real, int imag)
	{
		this->real = real;
		this->imag = imag;
	}

	Complex operator+(Complex &c)
	{
		return Complex(this->real + c.real, this->imag + c.imag);
	}

	Complex operator-(Complex &c)
	{
		return Complex(this->real - c.real, this->imag - c.imag);
	}

	friend std::ostream &operator<<(std::ostream &stream, const Complex &c)
	{
		stream << std::to_string(c.real) << " + " << std::to_string(c.imag) << "i";

		return stream;
	}

	std::string to_string()
	{
		return std::to_string(this->real) + " + " + std::to_string(this->imag) + "i";
	}
};

main(int argc, char const *argv[])
{
	Complex c1(1, 2), c2(3, 4);

	Complex c3 = c1 + c2;

	Complex c4 = c1 - c2;

	std::cout << c3 << std::endl;
	std::cout << c4 << std::endl;

	Complex c5 = c4;

	c4 = c3 - c1;

	std::cout << std::endl;

	std::cout << c4 << std::endl;
	std::cout << c5 << std::endl;

	return 0;
}
