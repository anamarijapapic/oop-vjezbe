/*
	[OP] - VJEZBA 2 - ZADATAK 1
	@file zad1.cpp
	@author Anamarija Papic
*/

#include <iostream>
using namespace std;

void arrInput(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << "array[" << i << "]: ";
		cin >> arr[i];
	}
}

void arrPrint(int arr[], int n)
{
	cout << "Your array:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void findMinMax(int arr[], int n, int& minNum, int& maxNum)
{
	minNum = arr[0];
	maxNum = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < minNum)
			minNum = arr[i];
		else if (arr[i] > maxNum)
			maxNum = arr[i];
	}
}

int main() {
	int* arr;
	int n, minNum, maxNum;
	do {
		cout << "How many integers do you want to enter to an array: ";
		cin >> n;
		if (n <= 0)
			cout << "Invalid input!" << endl;
	} while (n <= 0);
	arr = new int[n];
	arrInput(arr, n);
	arrPrint(arr, n);
	findMinMax(arr, n, minNum, maxNum);
	cout << "Minimum: " << minNum << endl;
	cout << "Maximum: " << maxNum << endl;
	delete[] arr;
	arr = 0;
	return 0;
}