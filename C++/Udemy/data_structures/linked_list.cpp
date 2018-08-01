/**
 * @file linked_list.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 30/07/2018
 * 
 * Templated Linked List implementation example
 */
#include <iostream>

template <class T>
class LinkedList
{
	class Node
	{
	  private:
		T _value;
		Node *_next;

	  public:
		Node(T value)
		{
			this->_value = value;
			this->_next = nullptr;
		}

		~Node() = default;

		T value()
		{
			return this->_value;
		}

		Node *get_next()
		{
			return this->_next;
		}

		void set_next(Node *next)
		{
			this->_next = next;
		}

		void print()
		{
			std::cout << this->_value << " -> ";
		}
	};

  private:
	Node *head;
	Node *tail;
	size_t _size;

	Node *iterate(size_t iter)
	{
		Node *scan = this->head;

		for (int i = 0; i < iter; i++)
			scan = scan->get_next();

		return scan;
	}

  public:
	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->_size = 0;
	}

	~LinkedList()
	{
		Node *scan = this->head;

		while (!this->empty())
		{
			this->head = this->head->get_next();

			delete scan;
			
			scan = this->head;
		}
	}

	bool empty()
	{
		return this->head == nullptr;
	}

	size_t size()
	{
		return this->_size;
	}

	void print()
	{
		std::cout << "\nSingly Linked List" << std::endl;
		if (this->empty())
			std::cout << "[ EMPTY ]" << std::endl;
		else
		{
			Node *scan = this->head;

			while (scan != nullptr)
			{
				scan->print();
				scan = scan->get_next();
			}

			std::cout << "NULL" << std::endl;
		}
	}

	void insert_front(T element)
	{
		Node *node = new Node(element);

		if (this->empty())
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			node->set_next(this->head);
			this->head = node;
		}
		this->_size++;
	}

	void insert_back(T element)
	{
		Node *node = new Node(element);

		if (this->empty())
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->tail->set_next(node);
			this->tail = node;
		}
	}

	void insert(T element, size_t pos)
	{
		if (pos > this->size())
			throw "Invalid position";

		if (pos == 0)
			this->insert_front(element);
		else if (pos == this->size())
			this->insert_back(element);
		else
		{
			Node *scan = this->iterate(pos - 1);
			Node *node = new Node(element);

			node->set_next(scan->get_next());

			scan->set_next(node);

			this->_size++;
		}
	}

	void remove_front()
	{
		if (this->empty())
			throw "List is empty";

		Node *prev = this->head;

		this->head = this->head->get_next();

		delete prev;

		this->_size--;

		if (this->empty())
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
	}

	void remove_back()
	{
		if (this->empty())
			throw "List is empty";

		Node *prev = nullptr;
		Node *curr = this->tail;

		while (curr->get_next() != nullptr)
		{
			prev = curr;
			curr = curr->get_next();
		}

		if (prev == nullptr)
		{
			delete curr;

			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			prev->set_next(nullptr);

			this->tail = prev;

			delete curr;
		}

		this->_size--;

		if (this->empty())
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
	}

	void remove(size_t pos)
	{
		if (pos >= this->size())
			throw "Invalid position";

		if (pos == 0)
			this->remove_front();
		else if (pos == this->size() - 1)
			this->remove_back();
		else
		{
			Node *prev = this->iterate(pos - 1);
			Node *curr = this->iterate(pos);

			prev->set_next(curr->get_next());

			delete curr;

			this->_size--;

			if (this->empty())
			{
				this->head = nullptr;
				this->tail = nullptr;
			}
		}
	}

	bool exists(T element)
	{
		Node *scan = this->head;

		while (scan != nullptr)
		{
			if (scan->value() == element)
				return true;

			scan = scan->get_next();
		}

		return false;
	}
};

int main(int argc, char const *argv[])
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
		list.insert_front(i);

	for (int i = 0; i < 10; i++)
	{
		list.insert_back(i);
	}

	std::cout << list.size() << std::endl;

	list.print();

	LinkedList<std::string> str_list;

	str_list.insert_front("Hello");
	str_list.insert_front("World");

	str_list.print();

	if (str_list.exists("Hello"))
		std::cout << "\nThere is the string Hello in the list" << std::endl;

	str_list.insert("Middle", 1);

	str_list.print();

	str_list.remove_back();

	str_list.print();

	str_list.remove_front();

	str_list.print();

	return 0;
}
