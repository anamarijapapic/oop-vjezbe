/*
    [OP] - VJEZBA 3 - ZADATAK 1
    @file vector.cpp
    @author Anamarija Papic
*/

#include "vector.hpp"
using namespace std;

void vector_input_1(vector<int>& myVector, int n)
{
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		myVector.push_back(input);
	}
}

void vector_input_2(vector<int>& myVector, int lowerBound, int upperBound)
{
	int input;
	cin >> input;
	while (input >= lowerBound && input <= upperBound) {
		myVector.push_back(input);
		cin >> input;
	}
}

void vector_print(vector<int>& myVector)
{
	for (size_t i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << "\t";
	}
	cout << endl;
}