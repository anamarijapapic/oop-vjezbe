/*
    [OP] - VJEZBA 10 - ZADATAK 2
    @file Stack.hpp
    @author Anamarija Papic
*/

#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class Stack {
	T* arr;
	size_t size, capacity;
public:
	Stack(size_t start_capacity);
	void push(const T& element);
	void pop();
	bool is_empty();
	void print_stack();
	~Stack();
};