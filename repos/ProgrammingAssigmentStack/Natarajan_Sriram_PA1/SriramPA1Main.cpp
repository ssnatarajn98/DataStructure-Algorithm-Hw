#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <stdio.h>
#define STOPWATCH_H
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
// StopWatch class copied from homework assigment
class StopWatch
{
private:
	/// Timer Resolution
	float			resolution;

	/// Using The Performance Timer?
	bool			performanceTimer;

	/// Start Value
	__int64			begin;
	/// End Value
	__int64			end;

	bool running;

public:
	StopWatch() {
		/// Timer Frequency
		__int64			frequency;

		begin = end = 0;
		running = false;

		// Check to see whether this computer has a performance timer
		if (!QueryPerformanceFrequency((LARGE_INTEGER *)&frequency))
		{
			// no performace counter available
			performanceTimer = false;
			resolution = 1.0f / 1000.0f;
		}
		else
		{
			// there is a performace timer available, so set the resolution
			performanceTimer = true;
			// calculate the resolution of the counter
			resolution = (float)(((double)1.0f) / ((double)frequency));
		}
	}

	// starts the timer
	void start() {
		__int64 time;

		// check if performance timer is used
		if (performanceTimer)
		{
			// get the current time
			QueryPerformanceCounter((LARGE_INTEGER *)&time);
			begin = time;
		}
		else
		{
			// set the last time this function was called to now
			begin = timeGetTime();
		}
		running = true;
	}

	// stops the timer from running
	void stop(void)
	{
		__int64 time;

		// check if performance timer is used
		if (performanceTimer)
		{
			// get the current time
			QueryPerformanceCounter((LARGE_INTEGER *)&time);
			end = time;
		}
		else
		{
			// set the last time this function was called to now
			end = timeGetTime();
		}
		running = false;
	}

	// returns the time in seconds of the timer.  If the timer is running, returns
	// the number of seconds since start was called.
	double seconds(void)
	{
		if (!running)
		{
			return ((double)(end - begin)*resolution);
		}
		__int64 now;

		// check if performance timer is used
		if (performanceTimer)
		{
			// get the current time
			QueryPerformanceCounter((LARGE_INTEGER *)&now);
		}
		else
		{
			// get the current time
			end = timeGetTime();
		}
		return ((double)(now - begin)*resolution);
	}

	// returns the time in milliseconds of the timer.  If the timer is running, returns
	// the number of milliseconds since start was called.
	double ms(void)
	{
		return seconds() * 1000;
	}
};


template <class Type>
class ArrayStack
{
private:
	Type* arr; //store array stack
	int arr_size; // stores size of array
	int num_val = -1; // stores number of values in stack
	int exp_val = 100; // How much the array will expand by each time it overflows

public:
	ArrayStack<Type>(int initsize) {
		//checking for invalid input
		try {
			if (initsize <= 0) { throw std::runtime_error("invalid input"); }
			else {
				arr = new Type[initsize];
				arr_size = initsize;
			
			};
		}
		catch (std::exception const& exc) {
			std::cerr << "invalid input" << "\n";
		}
	};

	~ArrayStack<Type>() {
		delete[] arr; //delete array which is on the heap
	
	};

	bool isEmpty()
	{
		if (num_val <= -1) { 
			return true;
		};

		return false;
	};

	int size(){ return (num_val + 1); }; // since when initaited num_val = -1;

	Type top() 
	{
		try {
			if (num_val <= -1) { throw std::runtime_error("empty stack"); }
			return arr[num_val];
		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
		}
	};

	Type pop()
	{
		try
		{
			if (num_val <= -1) {
				throw std::runtime_error("empty stack");
			}
			else {
				Type curr_val = arr[num_val];
				--num_val;
				return (curr_val);
			};
		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
		}
		
		
	};

	void push(Type e) {
		if (arr_size == (num_val + 1)) { // if current stack is full
			Type* temp_arr = new Type[arr_size + exp_val]; // create new array on the heap with the new size
			
			for (int i = 0; i < arr_size; i++) //transfer data from old stack to new stack
			{
				temp_arr[i] = arr[i];
			}
			delete[] arr; // delete old stack to avoid memory leak
			arr = temp_arr;
			arr_size = arr_size + exp_val;
			++num_val;
			arr[num_val] = e;
		}
		else {
			num_val += 1;
			arr[num_val] = e;
		}
	};

	/* 
	void PrintStack() { // for testing
		if (num_val <0) {
			throw EmptyStack();
		}
		else {
			for (int i = 0; i < (num_val + 1); i++)
			{
				std::cout << arr[i] << '\n';
			};
		};
		
	}; */
};
//------------------------------- DoublingArrayStack ---------------------//
template <class Type>
class DoublingArrayStack
{
private:
	Type * arr; //store array stack
	int arr_size; // stores size of array
	int num_val = -1; // stores number of values in stack
	

public:
	DoublingArrayStack<Type>(int initsize) {
		//checking for invalid input
		try {
			if (initsize <= 0) { throw std::runtime_error("invalid input"); }
			else {
				arr = new Type[initsize];
				arr_size = initsize;

			};
		}
		catch (std::exception const& exc) {
			std::cerr << "invalid input" << "\n";
		}
	};

	~DoublingArrayStack<Type>() {
		delete[] arr; //delete array which is on the heap

	};

	bool isEmpty()
	{
		if (num_val <= -1) {
			return true;
		};

		return false;
	};

	int size() { return (num_val + 1); }; // since when initaited num_val = -1;

	Type top()
	{
		try {
			if (num_val <= -1) { throw std::runtime_error("empty stack"); }
			return arr[num_val];
		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
		}
	};

	Type pop()
	{
		try
		{
			if (num_val <= -1) {
				throw std::runtime_error("empty stack");
			}
			else {
				Type curr_val = arr[num_val];
				--num_val;
				return (curr_val);
			};
		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
		}


	};

	void push(Type e) {
		if (arr_size == (num_val + 1)) { // if current stack is full
			Type* temp_arr = new Type[arr_size *2]; // create new array on the heap with the new size

			for (int i = 0; i < arr_size; i++) //transfer data from old stack to new stack
			{
				temp_arr[i] = arr[i];
			}
			delete[] arr; // delete old stack to avoid memory leak
			arr = temp_arr;
			arr_size = arr_size *2;
			++num_val;
			arr[num_val] = e;
		}
		else {
			num_val += 1;
			arr[num_val] = e;
		}
	};

	/*
	void PrintStack() { // for testing
	if (num_val <0) {
	throw EmptyStack();
	}
	else {
	for (int i = 0; i < (num_val + 1); i++)
	{
	std::cout << arr[i] << '\n';
	};
	};

	}; */
};


//-----Node Class -----//

template <class Type>
//Node class, Node are used in LLStack 
class Node {
public:
	Type data;
	Node* next;
	Node<Type>(Type d) {
		data = d;
		next = nullptr;
	}
};

template <class Type>

class LLStack {
private:
	int l_size = 0; // initiating l_size as 0 here because we don't need to call by index
	Node<Type>* head = nullptr; // designed so that head is the top
public:
	LLStack<Type>(Type d) : head(new Node<Type>(d)) {
		++l_size;
	};

	~LLStack<Type>()
	{
		Node* curr_node = head; // used to delete all the nodes in the list
		while (curr_node != nullptr)
		{
			Node* del_node = curr_node;
			curr_node = curr_node->next;
			delete[] del_node;
		}
	};

	int size() { return l_size; };

	void push(Type d) { // put a new object, assign its next as the current head and then make it the head
		Node<Type>* curr_node = new Node<Type>(d);
		curr_node->next = head;
		head = curr_node;
		++l_size;
	}

	Type top() {
		try {
			if (l_size <= 0) { throw std::runtime_error("empty stack"); }
			else {
				return head->data;
			}

		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
			
		}
		


	}
	bool isEmpty() {
		if (l_size <= 0) {
			return true;
		};
		return false;
	}
	Type pop()
	{
		try {
			if (l_size<= 0) { throw std::runtime_error("invalid input"); }
			else { // store the data value in head and then assign the new head as head-> next
				Type return_val = head->data;
				head = head->next;
				--l_size;
				return return_val;
			};
		}
		catch (std::exception const& exc) {
			std::cerr << "empty stack" << "\n";
		}
	}
	/*
	void printStack() {
		Node<Type>* curr_node = head;
		while (curr_node != nullptr)
		{
			Node<Type>* print_node = curr_node;
			curr_node = curr_node->next;
			std::cout << (print_node->data) << '\n';
		}
	};
	*/
};

	int main()
	{
		/*
		DoublingArrayStack<char>* temp = new DoublingArrayStack<char>(20);
		//ArrayStack<char>* temp = new ArrayStack<char>(20);
		cout << temp->top() << '\n';
		cout << temp->pop() << '\n';
		//cout << (temp->isEmpty()) << '\n';
		for (int j = 0; j <201; j++) {
			temp->push('b');
		}
		cout << temp->top() << '\n';
		cout << temp->pop() << '\n';
		//cout << (temp->top()) << '\n';
		for (int q = 0; q < 200; q++) {
			temp->pop();
		}
		cout << (temp->top()) << '\n';
		temp->pop();
		cout << (temp->isEmpty()) << '\n';
		cout << (temp->top()) << '\n';
		*/
		LLStack<int>* test_stack = new  LLStack<int>(1);
		StopWatch t;
		t.start();
		for (int j = 0; j < 1000000; j++) {
			test_stack->push(rand() % 10);
		}
		t.stop();
		printf("Took %f milliseconds\n", t.ms());
		int p;
		std::cin >> p;
	

		
	};
