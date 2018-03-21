#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <stdio.h>
template <class Type>
class Node 
{
public:
	Type data;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node<Type>(Type d) 
	{
		data = d;
	}
};
//initializing Deque structure
template <class Type>
class Deque {
	private:
		//int s is the size
		//assumption that head is front and tail is back 
		int s;
		Node<Type>* head;	
		Node<Type>* tail;
	public:
		Deque<Type>(void) {
			//initializing size with 0
			s = 0;
			head = nullptr ;
			tail = nullptr;
		};
		~Deque<Type>(void) { //deleting all the nodes
			Node<Type>* curr_node = head; 
			while (curr_node != nullptr)
			{
				Node<Type>* del_node = curr_node;
				curr_node = curr_node->prev;
				delete[] del_node;
			}
		};
		bool isEmpty(void) { //checking if the size is empty based on s val
			if (s < 1) {
				return true;
			}
			return false;
		};

		int size(void) {
			return s;
		};

		Type first(void) {
			try {
				if (isEmpty()) {
					throw std::runtime_error("empty stack");
				}
				else {
					return head->data;
				}
			}
			catch (std::exception const& exc) {
				std::cerr << "empty stack" << "\n";
			}
		}
		Type last(void) {
			try {
				if (isEmpty()) {
					throw std::runtime_error("empty stack");
				}
				else {
					return tail->data;
				}
			}
			catch (std::exception const& exc) {
				std::cerr << "empty stack" << "\n";
			}
		}
		void insertFirst(Type o) {
			Node<Type>* curr_node = new Node<Type>(o);
			if (!isEmpty()) { //making the new first element the head
				curr_node->prev = head;
				curr_node->next = nullptr;
				head->next = curr_node;
				head = curr_node;
			}
			else {
				head = tail = curr_node;
			}
			++s;
		}
		void insertLast(Type o) { //making the new last element the tail
			Node<Type>* curr_node = new Node<Type>(o);
			if (!isEmpty()) {
				curr_node->next = tail;
				curr_node->prev = nullptr;
				tail->prev = curr_node;
				tail = curr_node;
			}
			else {
				head = tail = curr_node;
			}
			++s;
		};

		Type removeFirst(void) {
			try {
				if (isEmpty()) {
					throw std::runtime_error("Empty stack");
				}
				else {
					Type return_val = head->data; //storing the value I need to return before deleting the node 
					head = head->prev;
					--s;
					return return_val;
				}
			}
			catch (std::exception const& exc) {
				std::cerr << "empty stack" << "\n";
			}
		};

		Type removeLast(void) {
			try {
				if (isEmpty()) {
					throw std::runtime_error("Empty stack");
				}
				else {
					Type return_val = tail->data;
					tail = tail->next;
					--s;
					return return_val;
				}
			}
			catch (std::exception const& exc) {
				std::cerr << "empty stack" << "\n";
			}
		};
};
int main() {
	Deque<char> intQ;
	printf("isEmpty(1): %d\n", intQ.isEmpty() ? 1 : 0);
	intQ.insertFirst(4);
	printf("removeLast(4): %d\n", intQ.removeLast());
	intQ.insertFirst(5);
	intQ.insertFirst(12);
	intQ.insertLast(7);
	intQ.insertLast(13);
	printf("first(12): %d\n", intQ.first());
	printf("last(13): %d\n", intQ.last());
	printf("size(4): %d\n", intQ.size());
	printf("isEmpty(0): %d\n", intQ.isEmpty() ? 1 : 0);
	printf("removeLast(13) :%d\n", intQ.removeLast());
	printf("removeLast(7) :%d\n", intQ.removeLast());
	printf("removeLast(5) :%d\n", intQ.removeLast());
	printf("removeFirst(12) :%d\n", intQ.removeFirst());
	printf("size(0): %d\n", intQ.size());
	printf("isEmpty(1): %d\n", intQ.isEmpty() ? 1 : 0);
	int k;
	std::cin >> k;
}


