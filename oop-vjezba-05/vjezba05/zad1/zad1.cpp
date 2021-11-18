/*
	[OP] - VJEZBA 5 - ZADATAK 1
	@file zad1.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "point.hpp"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	double xA, yA, zA;

	cout << "Point A:" << endl;
	cout << "Please enter coordinates: " << endl;
	cout << "x = ";
	cin >> xA;
	cout << "y = ";
	cin >> yA;
	cout << "z = ";
	cin >> zA;
	Point A(xA, yA, zA);

	cout << endl << "Point B:" << endl;
	Point B;
	double lwrBound, uprBound;
	cout << "Enter lower bound: ";
	cin >> lwrBound;
	cout << "Enter upper bound: ";
	cin >> uprBound;
	if (lwrBound > uprBound) {
		lwrBound += uprBound;
		uprBound = lwrBound - uprBound;
		lwrBound -= uprBound;
	}
	B.set_pseudorandom(lwrBound, uprBound);
	cout << "Pseudorandomly generated coordinates: " << endl;
	B.print();

	double distance2D = A.calculate_2D_distance(B);
	double distance3D = A.calculate_3D_distance(B);
	cout << endl << "2D distance between point A and point B: " << distance2D << endl;
	cout << "3D distance between point A and point B: " << distance3D << endl;

	return 0;
}