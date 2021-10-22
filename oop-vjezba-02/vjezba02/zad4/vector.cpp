/*
	[OP] - VJEZBA 2 - ZADATAK 4
	@file vector.cpp
	@author Anamarija Papic
*/

#include "vector.hpp"
using namespace std;

void MyVector::vector_new(size_t sz)
{
    arr = new int[sz];
    size = 0;
    capacity = 1;
}

void MyVector::vector_delete()
{
    delete[] arr;
}

void MyVector::vector_push_back(int n)
{
    if (size == capacity) {
        capacity *= 2;
        int* arrDouble = new int[capacity];
        for (int i = 0; i < capacity - 1; i++) {
            arrDouble[i] = arr[i];
        }
        delete[] arr;
        arr = arrDouble;
    }
    arr[size] = n;
    size++;
}

void MyVector::vector_pop_back()
{
    size--;
}

int& MyVector::vector_front()
{
    return arr[0];
}

int& MyVector::vector_back()
{
    return arr[size - 1];
}

size_t MyVector::vector_size()
{
    return size;
}

void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}