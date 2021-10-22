/*
    [OP] - VJEZBA 2 - ZADATAK 4
    @file vector.hpp
    @author Anamarija Papic
*/

#pragma once
#include <cstddef>
#include <iostream>
struct MyVector
{
    int* arr;
    size_t size, capacity;

    // member functions
    void vector_new(size_t sz = 0);
    void vector_delete();
    void vector_push_back(int n); /* adds a new element at the end of the vector */
    void vector_pop_back(); /* removes the last element in the vector */
    int& vector_front(); /* returns a reference to the first element in the vector*/
    int& vector_back(); /* returns a reference to the last element in the vector */
    size_t vector_size(); /* returns the number of the elements in the vector */

    void print_vector();
};