/**
 * @file queue.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 30/07/2018
 * 
 * Templated Queue implementation example
 */
#include <iostream>
#include <list>

using std::list;

template <class T>
class Queue
{
  private:
	list<T> queue;

  public:
	void enqueue(const T &element)
	{
		this->queue.push_back(element);
	}

	T dequeue()
	{
		if (!this->is_empty())
		{
			T element = queue.front();
			this->queue.pop_front();

			return element;
		}

		throw "Dequeue but queue is empty!";
	}

	bool is_empty()
	{
		return queue.empty();
	}

	T front()
	{
		if (!this->is_empty())
		{
			return this->queue.front();
		}

		throw "Queue is empty!";
	}

	T back()
	{
		if (!this->is_empty())
		{
			return this->queue.back();
		}

		throw "Queue is empty!";
	}

	int size()
	{
		return queue.size();
	}

	void print()
	{
		if (this->queue.empty())
			std::cout << "Queue is empty!" << std::endl;
		else
		{
			std::cout << std::endl;

			for(auto var : this->queue)
			{
				std::cout << var << " ";
			}

			std::cout << std::endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Queue<double> q;

	if (q.is_empty())
		q.print();

	std::cout << "\nAdding elements to the queue:" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		q.enqueue((double)i);
		q.print();
	}

	std::cout << "\nRemoving elements from the queue:" << std::endl;

	double a;

	while (!q.is_empty())
	{
		q.print();
		a = q.dequeue();
	}

	return 0;
}
