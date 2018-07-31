/**
 * @file stack.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/07/2018
 * 
 * Templated Stack implementation example
 */
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

template <class T>
class Stack
{
  private:
	T *buffer;
	unsigned long max_size;
	unsigned long size;

  public:
	Stack(unsigned size)
	{
		buffer = new T[size];
		this->max_size = size;
		this->size = 0;
	}

	~Stack()
	{
		delete[] buffer;
	}

	int push(T element)
	{
		if (this->is_full())
			return 0;

		buffer[++size] = element;

		return 1;
	}

	int pop()
	{
		if (this->is_empty())
			return 0;

		size--;

		return 1;
	}

	T peek()
	{
		return buffer[size];
	}

	bool is_full()
	{
		return this->size == this->max_size - 1;
	}

	bool is_empty()
	{
		return this->size == 0;
	}
};

int main(int argc, char const *argv[])
{
	const char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	size_t len = 26;

	srand(time(NULL));

	Stack<char> stack(100);

	while (!stack.is_full())
	{
		stack.push(alpha[rand() % len]);
	}

	int i;
	while (!stack.is_empty())
	{
		std::cout << stack.peek() << " ";
		stack.pop();
	}

	return 0;
}
