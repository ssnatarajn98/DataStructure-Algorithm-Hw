#include <exception>
#include <vector>
#include <iostream>
#include <list>
#include <exception>
class empty_UnsortedPQ_error {};
using namespace std;
template <class Type>
class UnsortedPQ
{
private:
	//using stl list
	std::list<Type> PQ_list;
public:
	UnsortedPQ(void) {
		PQ_list = {};
	};

	UnsortedPQ(Type *dataArray, int n) {
		PQ_list = {};
		for (int i = 0; i < n; i++) {
			PQ_list.push_back(dataArray[i]);
		}
	};

	~UnsortedPQ(void) {};

	bool isEmpty(void) {
		if (PQ_list.size() == 0) {
			return true;
		}
		return false;
	};

	int size(void) {
		return PQ_list.size();
	};

	// inserts a piece of data into the priority queue
	void insertItem(Type data) {
		PQ_list.push_back(data);
	}

	// removes and returns the minimum value in the queue
	// throws an exception if the queue is empty
	Type removeMin(void)
	{
		if (!isEmpty()) {
			Type curr_min = *(PQ_list.begin());
			//using stl iterator to handle pointers
			typename list<Type>::iterator runner;
			runner = PQ_list.begin();
			int curr_pos = 0;
			for (int i = 0; i < PQ_list.size(); i++) {
				if (*runner < curr_min)
				{
					curr_min = *runner;
					curr_pos = i;
				}
				std::advance(runner, 1);
			}
			runner = PQ_list.begin();
			std::advance(runner, curr_pos);
			//difference between removeMin and Min Value
			PQ_list.erase(runner);
			return curr_min;
		}
		else
		{
			throw empty_UnsortedPQ_error();
		}
	};

	// return the minimum value in the queue without removing it
	// throws an exception if the queue is empty
	Type minValue(void)
	{
		if (!isEmpty()) {
			Type curr_min = *(PQ_list.begin());
			//using stl iterator to handle pointers
			typename list<Type>::iterator runner;
			runner = PQ_list.begin();
			int curr_pos = 0;
			for (int i = 0; i < PQ_list.size(); i++) {
				if (*runner < curr_min)
				{
					curr_min = *runner;
					curr_pos = i;
				}
				std::advance(runner, 1);
			}
			runner = PQ_list.begin();
			std::advance(runner, curr_pos);
		
			return curr_min;
		}
		else
		{
			throw empty_UnsortedPQ_error();
		}
	}
};



