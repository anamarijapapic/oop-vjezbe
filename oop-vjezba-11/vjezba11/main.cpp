/*
    [OP] - VJEZBA 11
    @file main.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <algorithm>
using namespace std;

void fill_vector_from_file(const string& filename, vector<int>& numbers)
{
	ifstream fin;

	fin.open(filename);
	if (fin.fail()) {
		throw exception();
	}

	istream_iterator<int> it(fin);
	istream_iterator<int> eos;
	copy(it, eos, back_inserter(numbers));
}

void fill_container_from_vector(vector<int>& numbers)
{
	ostream_iterator<int> out(cout, " ");
	copy(numbers.begin(), numbers.end(), out);
	cout << endl;
}

void count_greater_than(const vector<int>& numbers, int number)
{
	cout << "Greater than " << number << ": " << count_if(numbers.begin(), numbers.end(), [&](int n) { return n > number; }) << " numbers" << endl;
}

void min_max_element(const vector<int>& numbers)
{
	auto result = minmax_element(numbers.begin(), numbers.end());
	cout << "Min element: " << *result.first << endl << "Max element: " << *result.second << endl;
}

void remove_less_than(vector<int>& numbers, int number)
{
	numbers.erase(remove_if(numbers.begin(), numbers.end(), [&](int n) { return n < number; }), numbers.end());
}

int main()
{
	vector<int> numbers;
	const string filename = "numbers.txt";

	try {
		fill_vector_from_file(filename, numbers);
	}
	catch (const exception&) {
		cerr << "Error opening file " << filename << "!" << endl;
		exit(1);
	}

	cout << "All numbers from file saved to vector: " << endl;
	fill_container_from_vector(numbers);

	count_greater_than(numbers, 500);
	
	min_max_element(numbers);
	
	remove_less_than(numbers, 300);
	
	sort(numbers.begin(), numbers.end(), greater<int>());

	cout << "All remaining numbers from vector sorted in descending order: " << endl;
	fill_container_from_vector(numbers);

	return 0;
}