#include "HeapPQ.h"
#include "SortedPQ.h"
#include "UnsortedPQ.h"
#include <fstream>
#include <iostream>
#include "StopWatch.h"
#include <stdio.h>
using namespace std;
/*
using namespace std;
int main() {
	int Qtype; 
	int n;
	int cnt;
	ifstream input_file("numbers.txt");
	if (input_file.is_open()) {
		input_file >> Qtype >> n;
		switch(Qtype) {
		case 0: {
			std::cout << "UnsortedPQ" << endl;

		}
		}
	}
}
*/
int main() {

	int r;
	char c;
	PQHeap<int> test;
	StopWatch t;
	t.start();
	for (int i = 0; i < 2000; i++) {
		c = rand() % 100;
		test.insertItem(c);
	}
	t.stop();
	std::cout << t.ms() << '\n';
	/*
	std::cout << test.isEmpty() << '\n';
	std::cout<<test.size()<<'\n';
	for (int i = 0; i < 1000000; i++) {
	
		std::cout<< test.removeMin() << '\n';
	}
	std::cout << test.size() << '\n';
	std::cout << test.isEmpty() << '\n';
	std::cout << test.removeMin() << '\n';
	
	*/
	int k;
	cin >> k;
}