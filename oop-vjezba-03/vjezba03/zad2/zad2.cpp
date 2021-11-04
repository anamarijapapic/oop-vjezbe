/*
	[OP] - VJEZBA 3 - ZADATAK 2
	@file zad2.cpp
	@author Anamarija Papic
*/

#include "..\zad1\vector.hpp"
#include "..\zad1\vector.cpp"
#include <iostream>
#include <vector>
using namespace std;

vector<int> vectorDifference(vector<int> v1, vector<int> v2)
{
	vector<int> v3;
	for (size_t i = 0; i < v1.size(); i++) {
		bool found = false;
		for (size_t j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			v3.push_back(v1[i]);
		}
	}
	return v3;
}

int main()
{
	vector<int> v1, v2, v3;
	int n, lwrBound, uprBound, tmp;

	cout << "Vector 1:" << endl;
	do {
		cout << "How many numbers do you want to enter to a vector: ";
		cin >> n;
		if (n <= 0)
			cout << "Invalid input!" << endl;
	} while (n <= 0);
	cout << "Enter vector elements:" << endl;
	vector_input_1(v1, n);
	cout << "Your vector 1:" << endl;
	vector_print(v1);

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
	vector_input_2(v2, lwrBound, uprBound);
	cout << "Your vector 2:" << endl;
	vector_print(v2);

	cout << endl << "Vector 3:" << endl;
	v3 = vectorDifference(v1, v2);
	cout << "Your vector 3:" << endl;
	vector_print(v3);
	
	return 0;
}
