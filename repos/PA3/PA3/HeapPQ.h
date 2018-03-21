#include <exception>
#include <vector>
#include <iostream>
#include <list>
#include <exception>
/**
* Note: in order to try to make things easier, the queue below will only have a single type of value
* in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
* make a priority queue that stored an object with both the key/value in it and a comparison operator
* that only compared the keys.
*/

class empty_PQHeap_error {};
using namespace std;
template <class Type>
class PQHeap
{
private:
	Type * arr; //store array stack
	int arr_size = 1; // stores size of array
	int num_val = -1; //
public:
	PQHeap(void)
	{
		//initalizing with size  1;
		arr = new Type[1];
	};


	PQHeap(Type *dataArray, int n) {
		arr = new Type[n];
		for (int i = 0; i < n; i++) {
			insertItem(dataArray[i]);
		}
	};

	~PQHeap(void) {
		delete[]  arr;
	};

	bool isEmpty(void) {
		if (num_val + 1 == 0) {
			return true;
		}
		return false;
	};


	int size(void) {
		return num_val+1;
	};


	// inserts a piece of data into the priority queue

	void insertItem(Type data) {
		if (arr_size == (num_val + 1)) { // if current stack is full
			Type* temp_arr = new Type[arr_size * 2]; // create new array on the heap with the new size
			for (int i = 0; i < arr_size; i++) //transfer data from old stack to new stack
			{
				temp_arr[i] = arr[i];
			}
			delete[] arr;
			arr = temp_arr;
			arr_size = arr_size * 2;
			++num_val;
			arr[num_val] = data;
		}
		else {
			num_val += 1;
			arr[num_val] = data;
		}
		insertHeap(num_val);
	};

	void insertHeap(int last_insert) {
		if (last_insert == 0) {
			return;
		}
		int parentIndex = (last_insert - 1) / 2;
		if (arr[parentIndex] > arr[last_insert])
		{
			int temp = arr[parentIndex];
			arr[parentIndex] = arr[last_insert];
			arr[last_insert] = temp;
			insertHeap(parentIndex);
		}
	};


	void removeHeap(int init_index) {
		int length = num_val;
		int leftChildIndex = 2 * init_index + 1;
		int rightChildIndex = 2 * init_index + 2;

		if (leftChildIndex >= length)
			return;
		int minIndex = init_index;

		if (arr[init_index] > arr[leftChildIndex]) {
			minIndex = leftChildIndex;
		}
		if ((rightChildIndex < length) && (arr[minIndex] > arr[rightChildIndex]))
		{
			minIndex = rightChildIndex;
		};
		if (minIndex != init_index) {
			int temp = arr[init_index];
			arr[init_index] = arr[minIndex];
			arr[minIndex] = temp;
			removeHeap(minIndex);
		}

	};

	Type removeMin(void)
	{
		if (!isEmpty()) {

			Type return_val = arr[0];
			arr[0] = arr[num_val];
			--num_val;
			removeHeap(0);
			return return_val;
		}
		else {
			throw  empty_PQHeap_error{};
		}
	};

	Type minValue(void)
	{
		if (!isEmpty()) {
			return arr[0];
		}
		else {
			throw  empty_PQHeap_error{};
		}
	};

};


