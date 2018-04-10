#include <iostream>

template<class T>
class QueueNode
{
	private:
		struct Node
		{
			T val;
			Node *next;
		};

		Node *first;
		Node *last;

		int size;

	public:
		QueueNode():size(0)
		{
		}

		void insert(T m_val)
		{
			Node *oldlast = last;
			last = new Node;
			last->val = m_val;
			if (isEmpty())
				first = last;
			else
				oldlast->next = last;
			size++;
		}

		T deque()
		{
			Node *oldfirst = first;
			first = first->next;
			T fr = oldfirst->val;
			delete oldfirst;
			size--;
			if (isEmpty())
			{
				last = nullptr;
			}
			return fr;
		}

		bool isEmpty()
		{
			return (size == 0);
		}

		void iterPrint()
		{
			Node *it = first; 
			while(it != nullptr)
			{
				std::cout << it->val << " ";
				it = it->next;
			}
			std::cout << '\n';
		}

		int count()
		{
			return size;
		}

		~QueueNode()
		{
			Node *it = first;
			while(it != nullptr)
			{
				Node *new_it = it->next;
				delete it;
				it = new_it;
			}
		}
};

int main()
{
	QueueNode<int> qn;
	std::cout << "Initialized new queue node, Is it empty?" << '\n';
	std::cout << qn.isEmpty() << '\n';
	std::cout << "Size of new queue node: " << '\n';
	std::cout << qn.count() << '\n';

	qn.insert(4);
	int a = 9;
	qn.insert(a);
	qn.insert(a);
	qn.insert(32);
	qn.iterPrint();
	std::cout << "Size of recent queue node: " << '\n';
	std::cout << qn.count() << '\n';
	std::cout << "Dequeing an element out" << '\n';
	std::cout << qn.deque() << '\n';
	std::cout << "Size of queue node now: " << '\n';
	std::cout << qn.count() << '\n';

	qn.deque();
	qn.deque();
	qn.deque();
	qn.insert(53);
	std::cout << qn.deque() << '\n';


	std::cout << "Is the queue empty now?" << '\n';
	std::cout << qn.isEmpty() << '\n';
	std::cout << "Size of queue node now " << '\n';
	std::cout << qn.count() << '\n';

	return 0;

}
