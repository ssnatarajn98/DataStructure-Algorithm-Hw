
#include <exception>
#include <vector>
#include <iostream>
class empty_queue_error {};
using namespace std;
template <class Type>
class SortedPQ
{
private:
	
	std::vector<Type> PQ_vector;
public:
	SortedPQ(void) {
		PQ_vector = {};
	};
	SortedPQ(Type *dataArray, int n) {
		PQ_vector = {};
		for (int i = 0; i < n; i++) {
			insertItem(dataArray[i]);
		}
	};

	~SortedPQ(void) {};

	bool isEmpty(void) {
		if (PQ_vector.size() == 0) {
			return true;
		}
		return false;
	};

	int size(void) {
		return PQ_vector.size() ;
	};

	// inserts a piece of data into the priority queue
	void insertItem(Type data)
	{
		PQ_vector.push_back(data);
		int cnt = PQ_vector.size() - 1;
		if (PQ_vector.size() != 1)
		{
			//swaping elements until the inserted element is in the right position
			while ((cnt != 0) && (PQ_vector[cnt] >= PQ_vector[cnt - 1]))
			{
				
				Type curr_val = PQ_vector[cnt];
				PQ_vector[cnt] = PQ_vector[cnt - 1];
				PQ_vector[cnt - 1] = curr_val;
				--cnt;
			}
		}

	};

	// removes and returns the minimum value in the queue
	Type removeMin(void)

	{
		if (PQ_vector.size() != 0) {
			Type return_val = PQ_vector.back();
			PQ_vector.pop_back();
			return return_val;
		}
		else {
			throw empty_queue_error {};
		}

	};

	//returns but does not delete minimum value
	Type minValue(void)
	{
		if (PQ_vector.size() != 0)
		{
			//access last element in vector
			return PQ_vector.back();
		}
		else {
			throw  empty_queue_error {};
		}
	};
};

