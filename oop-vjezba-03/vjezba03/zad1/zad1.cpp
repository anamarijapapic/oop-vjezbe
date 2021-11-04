/*
	[OP] - VJEZBA 3 - ZADATAK 1
	@file zad1.cpp
	@author Anamarija Papic
*/

#include "vector.hpp"
using namespace std;

int main()
{
	vector<int> myVector1, myVector2;
	int n, lwrBound, uprBound, tmp;

	cout << "Vector 1:" << endl;
	do {
		cout << "How many numbers do you want to enter to a vector: ";
		cin >> n;
		if (n <= 0)
			cout << "Invalid input!" << endl;
	} while (n <= 0);
	cout << "Enter vector elements:" << endl;
	vector_input_1(myVector1, n);
	cout << "Your vector:" << endl;
	vector_print(myVector1);

	cout << endl << "Vector 2:" << endl;
	cout << "Enter lower bound: ";
	cin >> lwrBound;
	cout << "Enter upper bound: ";
	cin >> uprBound;
	if (lwrBound > uprBound) {
		tmp = lwrBound;
		lwrBound = uprBound;
		uprBound = tmp;
	}
	cout << "Enter vector elements (interval [" << lwrBound << ", " << uprBound << "]):" << endl;
	vector_input_2(myVector2, lwrBound, uprBound);
	cout << "Your vector:" << endl;
	vector_print(myVector2);

	return 0;
}