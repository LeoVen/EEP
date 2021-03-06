// AppZero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <static_ds.hpp>

int main()
{
	ds::static_queue<int, 100> queue(0);
	ds::static_stack<int, 100> stack(0);

	int i = 0, j = 0;

	while (!queue.full())
	{
		queue.enqueue(i++);
	}

	while (!stack.full())
	{
		stack.push(j++);
	}

	while (!queue.empty())
	{
		std::cout << queue.peek() << " ";
		queue.dequeue();
	}

	std::cout << "\n\n";

	while (!stack.empty())
	{
		std::cout << stack.peek() << " ";
		stack.pop();
	}

	std::cin.ignore();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
