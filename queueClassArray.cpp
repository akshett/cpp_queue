#include <iostream>

template<class T>
class QueueArray
{
	private:
		T *arr;
		int size;
		int capacity;
		int first_pos;

		void resize_arr(int cap)
		{
			T *temp_arr = new T[cap];
			for (int i = 0; i < size; ++i)
			{
				temp_arr[cap - 1 - i] = arr[first_pos - i];
			}
			delete[] arr;
			arr = temp_arr;
		}

	public:
		QueueArray():arr(new T[1]), size(0), capacity(1), first_pos(0)
		{
		}

		void insert(T m_val)
		{
			if (size >= capacity)
			{
				resize_arr(2*capacity);
				capacity *= 2;
				first_pos = capacity - 1;
			}
			arr[first_pos - size] = m_val;
			size++;
		}

		T deque()
		{
			T el = arr[first_pos--];
			size--;
			if (size > 0 && size <= capacity/4)
			{
				resize_arr(capacity/2);
				capacity /= 2;
				first_pos = capacity - 1;
			}
			return el;
		}

		bool isEmpty()
		{
			return (size == 0);
		}

		int count()
		{
			return size;
		}

		void iterPrint()
		{
			for (int i = 0 ; i < size; ++i)
			{
				std::cout << arr[first_pos - i] << " ";
			}
			std::cout << '\n';
		}

		~QueueArray()
		{
			delete[] arr;
		}

};

int main()
{

	QueueArray<int> qa;
	std::cout << "Initialized new queue array, Is it empty?" << '\n';
	std::cout << qa.isEmpty() << '\n';
	std::cout << "Size of new queue array: " << '\n';
	std::cout << qa.count() << '\n';

	qa.insert(4);
	int a = 9;
	qa.insert(a);
	qa.insert(a);
	qa.insert(32);
	qa.iterPrint();
	std::cout << "Size of recent queue array: " << '\n';
	std::cout << qa.count() << '\n';
	std::cout << "Dequeing an element out" << '\n';
	std::cout << qa.deque() << '\n';
	std::cout << "Size of queue array now: " << '\n';
	std::cout << qa.count() << '\n';

	qa.deque();
	qa.deque();
	qa.deque();
	qa.insert(53);
	std::cout << qa.deque() << '\n';


	std::cout << "Is the queue empty now?" << '\n';
	std::cout << qa.isEmpty() << '\n';
	std::cout << "Size of queue array now " << '\n';
	std::cout << qa.count() << '\n';

	return 0;
}
