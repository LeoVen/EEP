#pragma once

#include <stdbool.h>
#include <stdint.h>

#include <type_traits>

namespace ds
{
	template<typename T, int N>
	class static_linear_collection
	{
		static_assert(N > 0, "The static size needs to be greater than 0");

	protected:
		T _buffer[N];
		uintmax_t _count;

		static_linear_collection()
		{
			_count = 0;
		}

		static_linear_collection(const T & initial_value)
		{
			for (uintmax_t i = 0; i < N; i++)
				_buffer[i] = initial_value;

			_count = 0;
		}

	public:
		bool empty(void)
		{
			return _count == 0;
		}

		bool full(void)
		{
			return _count == N;
		}

		uintmax_t count(void)
		{
			return _count;
		}
	};

	template<typename T, int N>
	class static_queue : public static_linear_collection<T, N>
	{
	private:
		uintmax_t _front, _back;

		class static_queue_empty_exception : public std::exception
		{
		public:
			virtual const char * what() const throw()
			{
				return "static_queue is empty";
			}
		} empty_exception;

	public:
		static_queue(void)
		{
			_front = 0, _back = 0;
		}

		static_queue(const T & initial_value) : static_linear_collection<T, N>(initial_value)
		{
			_front = 0, _back = 0;
		}

		bool enqueue(const T & element)
		{
			if (this->full())
				return false;

			this->_buffer[_back] = element;

			_back = _back == N - 1 ? 0 : _back + 1;
			this->_count++;

			return true;
		}

		bool dequeue(void)
		{
			if (this->empty())
				return false;

			_front = _front == N - 1 ? 0 : _front + 1;
			this->_count--;

			return true;
		}

		const T & peek(void)
		{
			if (this->empty())
				throw empty_exception;

			return this->_buffer[_front];
		}
	};

	template<typename T, int N>
	class static_stack : public static_linear_collection<T, N>
	{
	private:

		class static_stack_empty_exception : public std::exception
		{
		public:
			virtual const char * what() const throw()
			{
				return "static_stack is empty";
			}
		} empty_exception;

	public:
		static_stack(void) {}

		static_stack(const T & initial_value) : static_linear_collection<T, N>(initial_value) {}

		bool push(const T & element)
		{
			if (this->full())
				return false;

			this->_buffer[this->_count] = element;

			this->_count++;

			return true;
		}

		bool pop(void)
		{
			if (this->empty())
				return false;

			this->_count--;

			return true;
		}

		const T & peek(void)
		{
			if (this->empty())
				throw empty_exception;

			return this->_buffer[this->_count - 1];
		}
	};
}
