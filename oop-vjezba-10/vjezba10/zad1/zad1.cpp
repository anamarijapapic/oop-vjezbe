/*
    [OP] - VJEZBA 10 - ZADATAK 1
    @file zad1.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include "template.hpp"

int main()
{
    int arr_int[]{ 50, 20, 30, 10, -10, 0, 50 };
    float arr_float[]{ 5.5, 2.2, 3.3, 1.1, -1.1, 0, 5.5 };
    double arr_double[]{ 5.5, 2.2, 3.3, 1.1, -1.1, 0, 5.5 };
    char arr_char[]{ 'a', 'b', 'd', 'a', 'f', 'c', 'e', 'h', 'g'};
    char arr_Char[]{ 'A', 'b', 'd', 'a', 'f', 'c', 'e', 'H', 'g'};

    cout << "Unsorted arrays:" << endl;
    print_array(arr_int, size(arr_int));
    print_array(arr_float, size(arr_float));
    print_array(arr_double, size(arr_double));
    print_array(arr_char, size(arr_char));
    print_array(arr_Char, size(arr_Char));

    sort(arr_int, size(arr_int));
    sort(arr_float, size(arr_float));
    sort(arr_double, size(arr_double));
    sort(arr_char, size(arr_char));
    sort(arr_Char, size(arr_Char));

    cout << endl << "Sorted arrays:" << endl;
    print_array(arr_int, size(arr_int));
    print_array(arr_float, size(arr_float));
    print_array(arr_double, size(arr_double));
    print_array(arr_char, size(arr_char));
    print_array(arr_Char, size(arr_Char));

    return 0;
}