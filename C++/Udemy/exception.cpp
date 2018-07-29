/**
 * @file exception.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/07/2018
 * 
 * Working with exceptions and try-catch
 */
#include <iostream>
#include <string>

class CustomException : public std::exception
{
  protected:
	std::string message;

  public:
	CustomException(const char *e)
	{
		message.append(e);
	}

	virtual std::string what()
	{
		return message;
	}
};

int factorial(int n)
{
	if (n < 0)
		throw "Negative number not allowed!";

	if (n == 0 || n == 1)
		return 1;

	return n * factorial(n - 1);
}

double divide(double a, double b)
{
	if (b == 0)
		throw CustomException("Division by zero not allowed! ");

	return a / b;
}

main(int argc, char const *argv[])
{

	try
	{
		std::cout << "10! : " << factorial(10) << std::endl;
		//std::cout << "-5! : " << factorial(-5) << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "ERROR! " << e << std::endl;
	}
	catch (...)
	{
		std::cerr << "UNEXPECTED ERROR (This catches anything)" << std::endl;
	}

	try
	{
		std::cout << "2/5 : " << divide(2, 5) << std::endl;
		std::cout << "2/0 : " << divide(2, 0) << std::endl;
	}
	catch (CustomException e)
	{
		std::cerr << "ERROR! " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "UNEXPECTED ERROR (This catches anything)" << std::endl;
	}

	return 0;
}
