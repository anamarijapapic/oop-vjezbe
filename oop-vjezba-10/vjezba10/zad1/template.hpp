/*
    [OP] - VJEZBA 10 - ZADATAK 1
    @file template.hpp
    @author Anamarija Papic
*/

#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T>
void sort(T* array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (array[i] < array[j])
                swap(array[i], array[j]);
        }
    }
}

template <>
void sort<char>(char* array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (tolower(array[i]) < tolower(array[j]))
                swap(array[i], array[j]);
        }
    }
}

template<typename T>
void print_array(T array, size_t size)
{
    cout << typeid(*array).name() << ": ";
    for (size_t i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}