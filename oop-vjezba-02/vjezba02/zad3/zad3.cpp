/*
	[OP] - VJEZBA 2 - ZADATAK 3
	@file zad3.cpp
	@author Anamarija Papic
*/

#include <iostream>
#define POW2(x) ((x)*(x))
using namespace std;

struct Point {
	double x, y;
};

//	 T(x1, y2)    T2(x2, y2)
//	 *--------------------*
//	 |                    |
//	 |                    |
//	 |                    |
//	 |                    |
//	 *--------------------*
//	 T1(x1, y1)    T(x2, y1)

struct Rectangle {
	// opposite diagonal points
	Point bottomLeft; // T1(x1, y1)
	Point upperRight; // T2(x2, y2)
};

struct Circle {
	double radius;
	Point center; // Ts(xs, ys)
	void newCircle()
	{
		cout << "Circle: " << endl;
		cout << "Enter circle radius:" << endl;
		cout << "r = ";
		cin >> radius;
		cout << "Enter coordinates of the circle center:" << endl;
		cout << "x = ";
		cin >> center.x;
		cout << "y = ";
		cin >> center.y;
	}
};

Rectangle* newRectangle(int n)
{
	Rectangle* rectangle = new Rectangle[n];
	for (int i = 0; i < n; i++) {
		cout << endl << "Rectangle " << i + 1 << ":" << endl;
		cout << "Enter coordinates of the bottom left point:" << endl;
		cout << "x = ";
		cin >> rectangle[i].bottomLeft.x;
		cout << "y = ";
		cin >> rectangle[i].bottomLeft.y;
		cout << "Enter coordinates of the upper right point:" << endl;
		cout << "x = ";
		cin >> rectangle[i].upperRight.x;
		cout << "y = ";
		cin >> rectangle[i].upperRight.y;
	}
	return rectangle;
}

bool intersect(double x1, double y1, double x2, double y2, double xc, double yc, double r)
{
	// find the point on the rectangle nearest to the center of the circle
	double x = max(x1, min(x2, xc));
	double y = max(y1, min(y2, yc));
	// distance formula
	if ((POW2(x - xc) + POW2(y - yc)) <= POW2(r)) // (x - xs)^2 + (y - ys)^2 = r^2
		return true;
	return false;
}

int countIntersect(const Rectangle* (&rectangle), const Circle& circle, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (intersect(rectangle[i].bottomLeft.x, rectangle[i].bottomLeft.y, rectangle[i].upperRight.x, rectangle[i].upperRight.y, circle.center.x, circle.center.y, circle.radius))
			cnt++;
	}
	return cnt;
}

int main()
{
	Circle circle;
	const Rectangle* rectangleArr;
	int n;

	circle.newCircle();
	
	do {
		cout << endl << "Enter number of rectangles: ";
		cin >> n;
		if (n < 0)
			cout << "Invalid input!";
	} while (n < 0);
	rectangleArr = newRectangle(n);
	
	cout << endl << "Number of detected rectangle-circle collisions: " << countIntersect(rectangleArr, circle, n);

	delete[] rectangleArr;

	return 0;
}