#include <iostream>
#include<stdio.h>
#include <vector>
using namespace std;
class Point {
private:
	int a;
	int b;
public:
	Point(int x, int y) {
		a = x;
		b = y;
	}
	Point() {
		a = 10;
		b = 20;
	}
	~Point() {
		cout << "Destructor called: " << endl;
	}

	void print() {
		cout << "( " << a << " , " << b << " )" << endl;
	}


};
int main()
{
	Point stackArray[] = { Point(1, 1),Point(2, 2),Point(3, 3),Point(4, 4),Point(5, 5),Point(6, 6),Point(7, 7),Point(8, 8),Point(9, 9),Point(10, 10) };
	for (int i = 0; i < 10; i++) {
		Point temp = stackArray[i];
		temp.print();
	}
	Point* heapArray = new Point[10];
	for (int i = 0; i < 10; i++) {
		heapArray[i].print();
	}
	delete[] heapArray;
	int x;
	cin >> x;
}
