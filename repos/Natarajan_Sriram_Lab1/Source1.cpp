#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

struct Point {
public:
	int num;
	Point & operator=(const Point& m)
	{
		num = m.num;
	}
	
	Point() {
		num = 5;
	}
};
class Shape {
	int shape_location;
public:
	virtual void Print() = 0;

};
class Circle : public Shape {
public:
	Circle() {

		circle_data = 30;
	}
	void Print() {
		cout << circle_data << endl;
		cout << typeid(circle_data).name() << endl;
	}
private:
	int circle_data;


};
class Square : public Shape {
public:
	Square() {
		square_data = 20;
	}
	void Print() {
		cout << (square_data) << endl;
		cout << (typeid(square_data).name()) << endl;
	}
private:
	int square_data;
};
int main() {
	Shape *s = new Circle();
	Shape *p = new Square();
	s->Print();
	p->Print();
	int x;
	cin >> x;


}