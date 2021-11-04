/*
	[OP] - VJEZBA 3 - ZADATAK 4
	@file zad4.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vector_input(vector<int>& myVector, int n)
{
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		myVector.push_back(input);
	}
}

void vector_print(vector<int>& myVector)
{
	for (size_t i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << "\t";
	}
	cout << endl;
}

void remove_vector_element(vector<int>& myVector, size_t i)
{
	swap(myVector[i], myVector.back());
	myVector.pop_back();
}

int main()
{
	vector<int> v;
	int n;
	size_t i;

	cout << "Vector:" << endl;
	do {
		cout << "How many numbers do you want to enter to a vector: ";
		cin >> n;
		if (n <= 0)
			cout << "Invalid input!" << endl;
	} while (n <= 0);
	cout << "Enter vector elements:" << endl;
	vector_input(v, n);
	cout << endl << "Original vector:" << endl;
	vector_print(v);

	do {
		cout << endl << "Enter index of the vector element to remove it:" << endl;
		cin >> i;
		if (i <= 0 || i >= v.size())
			cout << "Invalid input!";
	} while (i <= 0 || i >= v.size());

	remove_vector_element(v, i);
	cout << endl << "Vector after removing element:" << endl;
	vector_print(v);

	return 0;
}
