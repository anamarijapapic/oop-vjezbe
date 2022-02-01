/*
    [OP] - VJEZBA 10 - ZADATAK 2
    @file zad2.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include "Stack.hpp"
#include "Stack.cpp"
using namespace std;

int main() 
{
	Stack<int> int_stack(2);
	Stack<float> float_stack(3);
	Stack<double> double_stack(3);
	Stack<char> char_stack(4);

	int_stack.push(1);
	int_stack.push(5);
	int_stack.push(10);
	int_stack.push(20);
	int_stack.print_stack();

	float_stack.push(1.1);
	float_stack.push(2.2);
	float_stack.push(3.3);
	float_stack.push(4.4);
	float_stack.print_stack();

	double_stack.push(1.1);
	double_stack.push(2.2);
	double_stack.push(3.3);
	double_stack.push(4.4);
	double_stack.print_stack();

	char_stack.push('a');
	char_stack.push('b');
	char_stack.push('c');
	char_stack.push('d');
	char_stack.print_stack();

	for (int i = 0; i < 5; i++) {
		int_stack.pop();
		float_stack.pop();
		double_stack.pop();
		char_stack.pop();
	}

	return 0;
}