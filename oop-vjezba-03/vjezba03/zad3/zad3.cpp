/*
	[OP] - VJEZBA 3 - ZADATAK 3
	@file zad3.cpp
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

void vector_element_sum(vector<int>& myVector, int* sum)
{
	*sum = 0;
	for (size_t i = 0; i < myVector.size(); i++) {
		*sum += myVector[i];
	}
}

int main()
{
	vector<int> v;
	int n, sum;

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

	sort(v.begin(), v.end());
	cout << endl << "Sorted vector:" << endl;
	vector_print(v);

	cout << endl << "Changed vector:" << endl;
	vector<int>::iterator it = v.begin();
	v.insert(it, 1, 0);
	vector_element_sum(v, &sum);
	v.push_back(sum);
	vector_print(v);

	return 0;
}
