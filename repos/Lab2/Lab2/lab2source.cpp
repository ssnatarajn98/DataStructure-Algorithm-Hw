#include<iostream>
#include<vector>
using namespace std;
template<class T, int N>
class Point
{
public:
	
	T arr[N];
	Point(vector<T>x)
	{
		for (int i = 0; i<N; i++)
		{
			arr[i] = x[i];
		}
	}
};
template<class T, int N>
int euclideanDistance(Point<T, N> const &p1, Point<T, N> const &p2)
{
	int dist = 0;
	for (int i = 0; i<N; i++)
	{
		dist += ((p2.arr[i] - p1.arr[i])*(p2.arr[i] - p1.arr[i]));
	}
	return dist;
}

int main()

{
	Point<int, 3> p({ 5,5,5 });
	Point<int, 3> py({ 7,7,7 });
	int finalans = euclideanDistance(p,py);
	cout << finalans<<endl;
	Point<double, 3> px({ 5,5,5 });
	Point<double, 3> pz({ 7,7,7 });
    finalans = euclideanDistance(px, pz);
	cout << finalans;
	int check;
	cin >> check;
	

}