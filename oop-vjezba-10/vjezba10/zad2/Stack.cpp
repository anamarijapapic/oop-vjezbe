/*
    [OP] - VJEZBA 10 - ZADATAK 2
    @file Stack.cpp
    @author Anamarija Papic
*/

#include "Stack.hpp"

template <class T>
Stack<T>::Stack(size_t start_capacity)
{
	size = 0;
	capacity = start_capacity;
	arr = new T[capacity];
}

template <class T>
void Stack<T>::push(const T& element)
{
	if (size == capacity) {
		capacity *= 2;
		T* temp_arr = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
			temp_arr[i] = arr[i];
		delete[] arr;
		arr = temp_arr;
	}
	arr[size] = element;
	size++;
}

template <class T>
void Stack<T>::pop()
{
	if (is_empty()) {
		cout << typeid(*arr).name() << " stack is empty." << endl;
		return;
	}
	cout << "Popped element from " << typeid(*arr).name() << " stack." << endl;
	size--;
}

template <class T>
bool Stack<T>::is_empty()
{
	return !size;
}

template <class T>
void Stack<T>::print_stack()
{
	cout << typeid(*arr).name() << " stack: ";
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <class T>
Stack<T>::~Stack()
{ 
	while (!is_empty())
		pop();
	delete[] arr; 
}