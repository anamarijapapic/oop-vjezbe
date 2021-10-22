/*
	[OP] - VJEZBA 1 - ZADATAK 4
	@file zad4.cpp
	@author Anamarija Papic
*/

#include <iostream>
#define MAX_N 10
using namespace std;

void arrInput(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		cout << "array[" << i << "]: ";
		cin >> arr[i];
	}
}

void arrPrint(int arr[], int n)
{
	int i;
	cout << "Your array:" << endl;
	for (i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

/*
// Koristenje gotovih funkcija min i max - 2 funkcije
int findMin_R(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	return min(arr[n - 1], findMin_R(arr, n - 1));
}

int findMax_R(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	return max(arr[n - 1], findMax_R(arr, n - 1));
}
*/

/*
// 2 odvojene funkcije za trazenje minimuma i maksimuma
int findMin_Rec(int* arr, int n) {
	if (n == 1)
		return *arr;
	int tempMin = findMin_Rec(arr + 1, n - 1);
	return *arr > tempMin ? tempMin : *arr;
}

int findMax_Rec(int* arr, int n) {
	if (n == 1)
		return *arr;
	int tempMax = findMax_Rec(arr + 1, n - 1);
	return *arr < tempMax ? tempMax : *arr;
}
*/

// 1 funkcija za trazenje min i max
void findMinMax_Rec(int* arr, int* minNum, int* maxNum, int n)
{
	if (n < 0)
		return;
	if (arr[n] < *minNum)
		*minNum = arr[n];
	if (arr[n] > *maxNum)
		*maxNum = arr[n];
	return findMinMax_Rec(arr, minNum, maxNum, n - 1);
}

int main() {
	int arr[MAX_N];
	int n;
	do {
		cout << "How many integers do you want to enter to an array (not more than " << MAX_N << "):" << endl;
		cin >> n;
		if (n <= 0 || n > MAX_N)
			cout << "Invalid input!" << endl;
	} while (n <= 0 || n > MAX_N);
	arrInput(arr, n);
	arrPrint(arr, n);
	/*
	// Poziv: Koristenje gotovih funkcija min i max - 2 funkcije
	cout << "Minimum: " << findMin_R(arr, n) << endl;
	cout << "Maximum: " << findMax_R(arr, n) << endl;
	*/
	/*
	// Poziv: 2 odvojene funkcije za trazenje minimuma i maksimuma
	cout << "Minimum: " << findMin_Rec(arr, n) << endl;
	cout << "Maximum: " << findMax_Rec(arr, n) << endl;
	*/
	// Poziv: 1 funkcija za trazenje min i max
	int minNum = arr[0];
	int maxNum = arr[0];
	findMinMax_Rec(arr, &minNum, &maxNum, n - 1);
	cout << "Minimum: " << minNum << endl;
	cout << "Maximum: " << maxNum << endl;
	return 0;
}