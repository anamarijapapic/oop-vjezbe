/*
	[OP] - VJEZBA 2 - ZADATAK 4
	@file zad4.cpp
	@author Anamarija Papic
*/

#include "vector.hpp"
#include <iostream>
using namespace std;

int main()
{
    MyVector mv;
    mv.vector_new(1);

    int m;
    cout << "Enter vector elements, Ctrl+z (Win) or Ctrl+d (Linux) for exit: " << endl;
    while (cin >> m)
        mv.vector_push_back(m);

    cout << endl << "First element: " << mv.vector_front() << endl;
    cout << "Last element: " << mv.vector_back() << endl;
    cout << "Vector: ";
    mv.print_vector();

    cout << endl << "Removing last element..." << endl;
    mv.vector_pop_back();
    cout << "Vector: ";
    mv.print_vector();

    cout << endl << "Size: " << mv.vector_size() << endl;
    cout << "Capacity: " << mv.capacity << endl;

    mv.vector_delete();
    
    return 0;
}
