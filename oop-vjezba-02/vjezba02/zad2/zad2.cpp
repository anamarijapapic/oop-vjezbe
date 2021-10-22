/*
	[OP] - VJEZBA 2 - ZADATAK 2
	@file zad2.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <iomanip>
using namespace std;

void arrPrint(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(6) << "[" << i << "]";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(8) << arr[i];
	cout << endl;
}

int& returnReference(int& ref, unsigned i)
{
	return (&ref)[i];
}

int main()
{
	unsigned i;
	int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	cout << "Array:" << endl;
	arrPrint(arr, 10);
	do {
		cout << "Enter index of an element: ";
		cin >> i;
		if (i < 0 || i >= 10)
			cout << "Invalid input!" << endl;
	} while (i < 0 || i >= 10);
	returnReference(arr[0], i) += 1;
	cout << "Changed array:" << endl;
	arrPrint(arr, 10);
	return 0;
}
